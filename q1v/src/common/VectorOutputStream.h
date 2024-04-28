/**
 * Copyright (c) 2012-2016, The CryptoNote developers, The Bytecoin developers
 * Copyright (c) 2021-2024, The Quan Project developers
 *
 * Complete copyright information can be found in the accompanying LICENSE file
*/

#pragma once

#include <cstdint>
#include <vector>
#include "IOutputStream.h"

namespace Common {

    class VectorOutputStream : public IOutputStream {
    public:
        VectorOutputStream(std::vector<uint8_t> &out);

        VectorOutputStream &operator=(const VectorOutputStream &) = delete;

        size_t writeSome(const void *data, size_t size) override;

    private:
        std::vector<uint8_t> &out;
    };

}
