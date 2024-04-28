/**
 * Copyright (c) 2012-2016, The CryptoNote developers, The Bytecoin developers
 * Copyright (c) 2021-2024, The Quan Project developers
 *
 * Complete copyright information can be found in the accompanying LICENSE file
*/

#pragma once

#include <system/ContextGroup.h>
#include <system/Dispatcher.h>
#include <system/Timer.h>

namespace System {

    template<typename T>
    class OperationTimeout {
    public:
        OperationTimeout(Dispatcher &dispatcher, T &object, std::chrono::nanoseconds timeout) : object(object),
                                                                                                timerContext(
                                                                                                        dispatcher),
                                                                                                timeoutTimer(
                                                                                                        dispatcher) {
            timerContext.spawn([this, timeout]() {
                try {
                    timeoutTimer.sleep(timeout);
                    timerContext.interrupt();
                } catch (std::exception &) {
                }
            });
        }

        ~OperationTimeout() {
            timerContext.interrupt();
            timerContext.wait();
        }

    private:
        T &object;
        ContextGroup timerContext;
        Timer timeoutTimer;
    };

}
