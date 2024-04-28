/**
 * Copyright (c) 2012-2016, The CryptoNote developers, The Bytecoin developers
 * Copyright (c) 2021-2024, The Quan Project developers
 *
 * Complete copyright information can be found in the accompanying LICENSE file
*/

#pragma once

#include <cstddef>
#include <cstdint>
#include <cstddef>

namespace Q1v {

    class ICryptoNoteProtocolObserver {
    public:
        virtual void peerCountUpdated(size_t count) {}

        virtual void lastKnownBlockHeightUpdated(uint32_t height) {}

        virtual void blockchainSynchronized(uint32_t topHeight) {}
    };

} //namespace Q1v
