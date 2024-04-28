/**
 * Copyright (c) 2012-2016, The CryptoNote developers, The Bytecoin developers
 * Copyright (c) 2021-2024, The Quan Project developers
 *
 * Complete copyright information can be found in the accompanying LICENSE file
*/

#pragma once

#include "IInputStream.h"

namespace Common {

    class MemoryInputStream : public IInputStream {
    public:
        MemoryInputStream(const void *buffer, size_t bufferSize);

        size_t getPosition() const;

        bool endOfStream() const;

        // IInputStream
        virtual size_t readSome(void *data, size_t size) override;

    private:
        const char *buffer;
        size_t bufferSize;
        size_t position;
    };
}
