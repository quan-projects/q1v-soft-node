/**
 * Copyright (c) 2012-2016, The CryptoNote developers, The Bytecoin developers
 * Copyright (c) 2021-2024, The Quan Project developers
 *
 * Complete copyright information can be found in the accompanying LICENSE file
*/

#include "StdOutputStream.h"

namespace Common {

    StdOutputStream::StdOutputStream(std::ostream &out) : out(out) {
    }

    size_t StdOutputStream::writeSome(const void *data, size_t size) {
        out.write(static_cast<const char *>(data), size);
        if (out.bad()) {
            return 0;
        }

        return size;
    }

}
