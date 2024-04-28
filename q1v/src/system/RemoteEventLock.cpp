/**
 * Copyright (c) 2012-2016, The CryptoNote developers, The Bytecoin developers
 * Copyright (c) 2021-2024, The Quan Project developers
 *
 * Complete copyright information can be found in the accompanying LICENSE file
*/

#include "RemoteEventLock.h"
#include <cassert>
#include <mutex>
#include <condition_variable>
#include <system/Dispatcher.h>
#include <system/Event.h>

namespace System {

    RemoteEventLock::RemoteEventLock(Dispatcher &dispatcher, Event &event) : dispatcher(dispatcher), event(event) {
        std::mutex mutex;
        std::condition_variable condition;
        bool locked = false;

        dispatcher.remoteSpawn([&]() {
            while (!event.get()) {
                event.wait();
            }

            event.clear();
            mutex.lock();
            locked = true;
            condition.notify_one();
            mutex.unlock();
        });

        std::unique_lock<std::mutex> lock(mutex);
        while (!locked) {
            condition.wait(lock);
        }
    }

    RemoteEventLock::~RemoteEventLock() {
        Event *eventPointer = &event;
        dispatcher.remoteSpawn([=]() {
            assert(!eventPointer->get());
            eventPointer->set();
        });
    }

}
