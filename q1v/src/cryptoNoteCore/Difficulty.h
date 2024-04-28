/**
 * Copyright (c) 2012-2016, The CryptoNote developers, The Bytecoin developers
 * Copyright (c) 2021-2024, The Quan Project developers
 *
 * Complete copyright information can be found in the accompanying LICENSE file
*/

#pragma once

#include <cstdint>
#include <vector>

#include "crypto/hash.h"

namespace Q1v {
    typedef std::uint64_t difficulty_type;

    bool check_hash(const Crypto::Hash &hash, difficulty_type difficulty);
}
