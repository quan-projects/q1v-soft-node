/**
 * Copyright (c) 2012-2016, The CryptoNote developers, The Bytecoin developers
 * Copyright (c) 2021-2024, The Quan Project developers
 *
 * Complete copyright information can be found in the accompanying LICENSE file
*/

#include "StdInputStream.h"

namespace Common {

    StdInputStream::StdInputStream(std::istream &in) : in(in) {
    }

    size_t StdInputStream::readSome(void *data, size_t size) {
        in.read(static_cast<char *>(data), size);
        return in.gcount();
    }

}
