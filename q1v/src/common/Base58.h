/**
 * Copyright (c) 2012-2016, The CryptoNote developers, The Bytecoin developers
 * Copyright (c) 2021-2024, The Quan Project developers
 *
 * Complete copyright information can be found in the accompanying LICENSE file
*/

#pragma once

#include <cstdint>
#include <string>

namespace Tools {
    namespace Base58 {
        std::string encode(const std::string &data);

        bool decode(const std::string &enc, std::string &data);

        std::string encode_addr(uint64_t tag, const std::string &data);

        bool decode_addr(std::string addr, uint64_t &tag, std::string &data);
    }
}
