/**
 * Copyright (c) 2012-2016, The CryptoNote developers, The Bytecoin developers
 * Copyright (c) 2021-2024, The Quan Project developers
 *
 * Complete copyright information can be found in the accompanying LICENSE file
*/

#pragma once

#include <system/Dispatcher.h>

namespace System {

    class ContextGroup {
    public:
        explicit ContextGroup(Dispatcher &dispatcher);

        ContextGroup(const ContextGroup &) = delete;

        ContextGroup(ContextGroup &&other);

        ~ContextGroup();

        ContextGroup &operator=(const ContextGroup &) = delete;

        ContextGroup &operator=(ContextGroup &&other);

        void interrupt();

        void spawn(std::function<void()> &&procedure);

        void wait();

    private:
        Dispatcher *dispatcher;
        NativeContextGroup contextGroup;
    };

}
