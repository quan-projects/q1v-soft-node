/**
 * Copyright (c) 2012-2016, The CryptoNote developers, The Bytecoin developers
 * Copyright (c) 2021-2024, The Quan Project developers
 *
 * Complete copyright information can be found in the accompanying LICENSE file
*/

#pragma once

#include <cstddef>

namespace Common {

    class IOutputStream {
    public:
        virtual ~IOutputStream() {}

        virtual size_t writeSome(const void *data, size_t size) = 0;
    };

}
