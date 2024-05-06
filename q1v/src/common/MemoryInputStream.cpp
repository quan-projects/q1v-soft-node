/**
 * Copyright (c) 2012-2016, The CryptoNote developers, The Bytecoin developers
 * Copyright (c) 2021-2024, The Quan Project developers
 *
 * Complete copyright information can be found in the accompanying LICENSE file
*/

#include "MemoryInputStream.h"
#include <algorithm>
#include <cassert>
#include <cstring> // memcpy

namespace Common {

    MemoryInputStream::MemoryInputStream(const void *buffer, size_t bufferSize) : buffer(
            static_cast<const char *>(buffer)), bufferSize(bufferSize), position(0) {}

    size_t MemoryInputStream::getPosition() const {
        return position;
    }

    bool MemoryInputStream::endOfStream() const {
        return position == bufferSize;
    }

    size_t MemoryInputStream::readSome(void *data, size_t size) {
        assert(position <= bufferSize);
        size_t readSize = std::min(size, bufferSize - position);

        if (readSize > 0) {
            memcpy(data, buffer + position, readSize);
            position += readSize;
        }

        return readSize;
    }

}
