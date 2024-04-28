/**
 * Copyright (c) 2012-2016, The CryptoNote developers, The Bytecoin developers
 * Copyright (c) 2018, The Niobio Cash developers
 * Copyright (c) 2021-2024, The Quan Project developers
 *
 * Complete copyright information can be found in the accompanying LICENSE file
*/

#include "Checkpoints.h"
#include "../CryptoNoteConfig.h"
#include "common/StringTools.h"
#include "common/DnsTools.h"
#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <string>
#include <string.h>
#include <sstream>
#include <vector>
#include <iterator>
#include <boost/algorithm/string.hpp>
#include <thread>
#include <condition_variable>

using namespace Logging;

namespace Q1v {
    //---------------------------------------------------------------------------
    Checkpoints::Checkpoints(Logging::ILogger &log) : logger(log, "checkpoints") {
        m_mutex = new std::mutex();
    }

    //---------------------------------------------------------------------------
    bool Checkpoints::add_checkpoint(uint64_t height, const std::string &hash_str) {
        Crypto::Hash h = NULL_HASH;
        if (!Common::podFromHex(hash_str, h)) {
            logger(WARNING) << "Wrong hash in checkpoint for height " << height;
            return false;
        }
        if (0 != m_points.count(height)) {
            logger(WARNING) << "Checkpoint already exists.";
            return false;
        }

        m_points[height] = h;

        return true;
    }

    //---------------------------------------------------------------------------
    bool Checkpoints::is_in_checkpoint_zone(uint64_t height) const {
        return !m_points.empty() && (height <= (--m_points.end())->first);
    }

    //---------------------------------------------------------------------------
    bool Checkpoints::check_block(uint64_t height, const Crypto::Hash &h, bool &is_a_checkpoint) const {
        auto it = m_points.find(height);
        is_a_checkpoint = it != m_points.end();
        if (!is_a_checkpoint)
            return true;

        if (it->second == h) {
            logger(Logging::INFO, Logging::GREEN) << "CHECKPOINT PASSED FOR HEIGHT " << height << " " << h;
            return true;
        } else {
            logger(Logging::ERROR) << "CHECKPOINT FAILED FOR HEIGHT " << height << ". EXPECTED HASH: " << it->second
                                   << ", FETCHED HASH: " << h;
            return false;
        }
    }

    //---------------------------------------------------------------------------
    bool Checkpoints::check_block(uint64_t height, const Crypto::Hash &h) const {
        bool ignored;
        return check_block(height, h, ignored);
    }

    //---------------------------------------------------------------------------
    bool Checkpoints::is_alternative_block_allowed(uint64_t blockchain_height, uint64_t block_height) const {
        if (0 == block_height) return false;
        if (block_height < blockchain_height - Q1v::parameters::CRYPTONOTE_MINED_MONEY_UNLOCK_WINDOW &&
            !is_in_checkpoint_zone(block_height)) {
            logger(Logging::ERROR, Logging::BRIGHT_WHITE) << "An attempt of too deep reorganization: "
                                                          << blockchain_height - block_height << ", BLOCK REJECTED";
            return false;
        }
        auto it = m_points.upper_bound(blockchain_height);
        // Is blockchain_height before the first checkpoint?
        if (it == m_points.begin())
            return true;

        --it;
        uint32_t checkpoint_height = it->first;
        return checkpoint_height < block_height;
    }

    std::vector<uint64_t> Checkpoints::getCheckpointHeights() const {
        std::vector<uint64_t> checkpointHeights;
        checkpointHeights.reserve(m_points.size());
        for (const auto &it: m_points) {
            checkpointHeights.push_back(it.first);
        }

        return checkpointHeights;
    }

    bool Checkpoints::load_checkpoints_from_dns() {
        // better code from Karbo developers
        try {
            std::lock_guard<std::mutex> lock(*m_mutex);
            std::mutex m;
            std::condition_variable cv;
            std::string domain("checkpoints.quanproject.com");
            std::vector<std::string> records;
            bool res = true;

            std::thread t([&cv, &domain, &res, &records]() {
                res = Common::fetch_dns_txt(domain, records);
                cv.notify_one();
            });

            t.detach();

            {
                std::unique_lock<std::mutex> l(m);
                if (cv.wait_for(l, std::chrono::milliseconds(1000)) == std::cv_status::timeout) {
                    logger(Logging::INFO) << "Timeout lookup DNS checkpoint records from " << domain;
                    return false;
                }
            }

            if (!res) {
                logger(Logging::INFO) << "Failed to lookup DNS checkpoint records from " + domain;
                return false;
            }
            //
            for (const auto &record: records) {
                uint64_t height;
                Crypto::Hash hash = NULL_HASH;
                std::stringstream ss;
                size_t del = record.find_first_of(':');
                std::string height_str = record.substr(0, del), hash_str = record.substr(del + 1, 64);
                ss.str(height_str);
                ss >> height;
                char c;
                if (del == std::string::npos) continue;
                if ((ss.fail() || ss.get(c)) || !Common::podFromHex(hash_str, hash)) {
                    logger(Logging::INFO) << "Failed to parse DNS checkpoint record: " << record;
                    continue;
                }
                if (0 == m_points.count(height)) {
                    add_checkpoint(height, hash_str);
                    logger(Logging::INFO) << "Added DNS checkpoint: " << height_str << ":" << hash_str;
                } else {
                    logger(Logging::INFO) << "Checkpoint already exists for height: " << height
                                          << ". Ignoring DNS checkpoint.";
                }
            }
            //
            return true;
        } catch (std::runtime_error &e) {
            logger(Logging::INFO) << e.what();
            return false;
        }
    }
}
