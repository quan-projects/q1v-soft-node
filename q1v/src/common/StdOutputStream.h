/**
 * Copyright (c) 2012-2016, The CryptoNote developers, The Bytecoin developers
 * Copyright (c) 2021-2024, The Quan Project developers
 *
 * Complete copyright information can be found in the accompanying LICENSE file
*/

#pragma once

#include <ostream>
#include "IOutputStream.h"

namespace Common {

    class StdOutputStream : public IOutputStream {
    public:
        StdOutputStream(std::ostream &out);

        StdOutputStream &operator=(const StdOutputStream &) = delete;

        size_t writeSome(const void *data, size_t size) override;

    private:
        std::ostream &out;
    };

}
