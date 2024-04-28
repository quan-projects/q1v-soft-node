/**
 * Copyright (c) 2012-2016, The CryptoNote developers, The Bytecoin developers
 * Copyright (c) 2018-2019, The Niobio Cash developers
 * Copyright (c) 2021-2024, The Quan Project developers
 *
 * Complete copyright information can be found in the accompanying LICENSE file
*/

#pragma once

#include <map>
#include <mutex>
#include "CryptoNoteBasicImpl.h"
#include <logging/LoggerRef.h>
#include "crypto/hash.h"

namespace Q1v {
    class Checkpoints {
    public:
        Checkpoints(Logging::ILogger &log);

        bool add_checkpoint(uint64_t height, const std::string &hash_str);

        bool is_in_checkpoint_zone(uint64_t height) const;

        bool check_block(uint64_t height, const Crypto::Hash &h) const;

        bool check_block(uint64_t height, const Crypto::Hash &h, bool &is_a_checkpoint) const;

        bool is_alternative_block_allowed(uint64_t blockchain_height, uint64_t block_height) const;

        std::vector<uint64_t> getCheckpointHeights() const;

        bool load_checkpoints_from_dns();

    private:
        std::map<uint64_t, Crypto::Hash> m_points;
        Logging::LoggerRef logger;
        mutable std::mutex *m_mutex;
    };
}
