/**
 * Copyright (c) 2012-2016, The CryptoNote developers, The Bytecoin developers
 * Copyright (c) 2021-2024, The Quan Project developers
 *
 * Complete copyright information can be found in the accompanying LICENSE file
*/

#pragma once

#include <functional>

namespace Tools {

    class ScopeExit {
    public:
        ScopeExit(std::function<void()> &&handler);

        ~ScopeExit();

        ScopeExit(const ScopeExit &) = delete;

        ScopeExit(ScopeExit &&) = delete;

        ScopeExit &operator=(const ScopeExit &) = delete;

        ScopeExit &operator=(ScopeExit &&) = delete;

        void cancel();

    private:
        std::function<void()> m_handler;
        bool m_cancelled;
    };

}
