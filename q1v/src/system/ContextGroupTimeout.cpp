/**
 * Copyright (c) 2012-2016, The CryptoNote developers, The Bytecoin developers
 * Copyright (c) 2021-2024, The Quan Project developers
 *
 * Complete copyright information can be found in the accompanying LICENSE file
*/

#include "ContextGroupTimeout.h"
#include <system/InterruptedException.h>

using namespace System;

ContextGroupTimeout::ContextGroupTimeout(Dispatcher &dispatcher, ContextGroup &contextGroup,
                                         std::chrono::nanoseconds timeout) : workingContextGroup(dispatcher),
                                                                             timeoutTimer(dispatcher) {
    workingContextGroup.spawn([&, timeout] {
        try {
            timeoutTimer.sleep(timeout);
            contextGroup.interrupt();
        } catch (InterruptedException &) {
        }
    });
}
