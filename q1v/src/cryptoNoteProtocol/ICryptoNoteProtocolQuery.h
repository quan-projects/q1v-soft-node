/**
 * Copyright (c) 2012-2016, The CryptoNote developers, The Bytecoin developers
 * Copyright (c) 2021-2024, The Quan Project developers
 *
 * Complete copyright information can be found in the accompanying LICENSE file
*/

#pragma once

#include <cstddef>
#include <cstdint>

namespace Q1v {
    class ICryptoNoteProtocolObserver;

    class ICryptoNoteProtocolQuery {
    public:
        virtual bool addObserver(ICryptoNoteProtocolObserver *observer) = 0;

        virtual bool removeObserver(ICryptoNoteProtocolObserver *observer) = 0;

        virtual uint32_t getObservedHeight() const = 0;

        virtual size_t getPeerCount() const = 0;

        virtual bool isSynchronized() const = 0;
    };

} //namespace Q1v
