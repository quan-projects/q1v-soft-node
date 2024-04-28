/**
 * Copyright (c) 2012-2016, The CryptoNote developers, The Bytecoin developers
 * Copyright (c) 2021-2024, The Quan Project developers
 *
 * Complete copyright information can be found in the accompanying LICENSE file
*/

#pragma once

#include <sstream>

namespace Q1v {

    class IStreamSerializable {
    public:
        virtual void save(std::ostream &os) = 0;

        virtual void load(std::istream &in) = 0;
    };

}
