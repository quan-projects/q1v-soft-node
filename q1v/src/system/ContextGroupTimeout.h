/**
 * Copyright (c) 2012-2016, The CryptoNote developers, The Bytecoin developers
 * Copyright (c) 2021-2024, The Quan Project developers
 *
 * Complete copyright information can be found in the accompanying LICENSE file
*/

#pragma once

#include <chrono>
#include <system/ContextGroup.h>
#include <system/Timer.h>

namespace System {

    class ContextGroupTimeout {
    public:
        ContextGroupTimeout(Dispatcher &, ContextGroup &, std::chrono::nanoseconds);

    private:
        Timer timeoutTimer;
        ContextGroup workingContextGroup;
    };

}
