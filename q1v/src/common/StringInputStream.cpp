/**
 * Copyright (c) 2012-2016, The CryptoNote developers, The Bytecoin developers
 * Copyright (c) 2021-2024, The Quan Project developers
 *
 * Complete copyright information can be found in the accompanying LICENSE file
*/

#include "StringInputStream.h"
#include <string.h>

namespace Common {

    StringInputStream::StringInputStream(const std::string &in) : in(in), offset(0) {
    }

    size_t StringInputStream::readSome(void *data, size_t size) {
        if (size > in.size() - offset) {
            size = in.size() - offset;
        }

        memcpy(data, in.data() + offset, size);
        offset += size;
        return size;
    }

}
