/**
 * Copyright (c) 2012-2016, The CryptoNote developers, The Bytecoin developers
 * Copyright (c) 2021-2024, The Quan Project developers
 *
 * Complete copyright information can be found in the accompanying LICENSE file
*/

#include "EventLock.h"
#include <system/Event.h>

namespace System {

    EventLock::EventLock(Event &event) : event(event) {
        while (!event.get()) {
            event.wait();
        }

        event.clear();
    }

    EventLock::~EventLock() {
        event.set();
    }

}
