/**
 * Copyright (c) 2012-2016, The CryptoNote developers, The Bytecoin developers
 * Copyright (c) 2021-2024, The Quan Project developers
 *
 * Complete copyright information can be found in the accompanying LICENSE file
*/

#pragma once

namespace Q1v {
    template<typename T>
    class IObservable {
    public:
        virtual void addObserver(T *observer) = 0;

        virtual void removeObserver(T *observer) = 0;
    };
}
