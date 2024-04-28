/**
 * Copyright (c) 2012-2016, The CryptoNote developers, The Bytecoin developers
 * Copyright (c) 2021-2024, The Quan Project developers
 *
 * Complete copyright information can be found in the accompanying LICENSE file
*/

#pragma once

#include <time.h>

namespace Q1v {

    struct ITimeProvider {
        virtual time_t now() = 0;

        virtual ~ITimeProvider() {}
    };

    struct RealTimeProvider : public ITimeProvider {
        virtual time_t now() override {
            return time(nullptr);
        }
    };

}
