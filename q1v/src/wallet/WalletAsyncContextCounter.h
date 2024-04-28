/**
 * Copyright (c) 2012-2016, The CryptoNote developers, The Bytecoin developers
 * Copyright (c) 2021-2024, The Quan Project developers
 *
 * Complete copyright information can be found in the accompanying LICENSE file
*/

#pragma once

#include <condition_variable>
#include <mutex>
#include <stdint.h>

namespace Q1v {

    class WalletAsyncContextCounter {
    public:
        WalletAsyncContextCounter() : m_asyncContexts(0) {}

        void addAsyncContext();

        void delAsyncContext();

        //returns true if contexts are finished before timeout
        void waitAsyncContextsFinish();

    private:
        uint32_t m_asyncContexts;
        std::condition_variable m_cv;
        std::mutex m_mutex;
    };

} //namespace Q1v
