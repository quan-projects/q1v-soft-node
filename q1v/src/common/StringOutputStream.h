/**
 * Copyright (c) 2012-2016, The CryptoNote developers, The Bytecoin developers
 * Copyright (c) 2021-2024, The Quan Project developers
 *
 * Complete copyright information can be found in the accompanying LICENSE file
*/

#pragma once

#include <string>
#include "IOutputStream.h"

namespace Common {

    class StringOutputStream : public IOutputStream {
    public:
        StringOutputStream(std::string &out);

        size_t writeSome(const void *data, size_t size) override;

    private:
        std::string &out;
    };

}
