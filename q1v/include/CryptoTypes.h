/**
 * Copyright (c) 2012-2016, The CryptoNote developers, The Bytecoin developers
 * Copyright (c) 2021-2024, The Quan Project developers
 *
 * Complete copyright information can be found in the accompanying LICENSE file
*/

#pragma once

#include <cstdint>

namespace Crypto {

    struct Hash {
        uint8_t data[32];
    };

    struct PublicKey {
        uint8_t data[32];
    };

    struct SecretKey {
        uint8_t data[32];
    };

    struct KeyDerivation {
        uint8_t data[32];
    };

    struct KeyImage {
        uint8_t data[32];
    };

    struct Signature {
        uint8_t data[64];
    };

}
