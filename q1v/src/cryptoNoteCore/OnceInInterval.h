/**
 * Copyright (c) 2012-2016, The CryptoNote developers, The Bytecoin developers
 * Copyright (c) 2021-2024, The Quan Project developers
 *
 * Complete copyright information can be found in the accompanying LICENSE file
*/

#pragma once

#include <time.h>

namespace Q1v {

    class OnceInInterval {
    public:

        OnceInInterval(unsigned interval, bool startNow = true) : m_interval(interval),
                                                                  m_lastCalled(startNow ? 0 : time(nullptr)) {}

        template<class F>
        bool call(F func) {
            time_t currentTime = time(nullptr);

            if (currentTime - m_lastCalled > m_interval) {
                bool res = func();
                time(&m_lastCalled);
                return res;
            }

            return true;
        }

    private:
        time_t m_lastCalled;
        time_t m_interval;
    };

}
