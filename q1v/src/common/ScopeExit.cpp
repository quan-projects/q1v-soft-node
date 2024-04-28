/**
 * Copyright (c) 2012-2016, The CryptoNote developers, The Bytecoin developers
 * Copyright (c) 2021-2024, The Quan Project developers
 *
 * Complete copyright information can be found in the accompanying LICENSE file
*/

#include "ScopeExit.h"

namespace Tools {

    ScopeExit::ScopeExit(std::function<void()> &&handler) : m_handler(std::move(handler)), m_cancelled(false) {
    }

    ScopeExit::~ScopeExit() {
        if (!m_cancelled) {
            m_handler();
        }
    }

    void ScopeExit::cancel() {
        m_cancelled = true;
    }

}
