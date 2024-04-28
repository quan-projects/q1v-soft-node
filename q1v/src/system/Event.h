/**
 * Copyright (c) 2012-2016, The CryptoNote developers, The Bytecoin developers
 * Copyright (c) 2021-2024, The Quan Project developers
 *
 * Complete copyright information can be found in the accompanying LICENSE file
*/

#pragma once

namespace System {

    class Dispatcher;

    class Event {
    public:
        Event();

        explicit Event(Dispatcher &dispatcher);

        Event(const Event &) = delete;

        Event(Event &&other);

        ~Event();

        Event &operator=(const Event &) = delete;

        Event &operator=(Event &&other);

        bool get() const;

        void clear();

        void set();

        void wait();

    private:
        Dispatcher *dispatcher;
        bool state;
        void *first;
        void *last;
    };

}
