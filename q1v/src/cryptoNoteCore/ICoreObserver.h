/**
 * Copyright (c) 2012-2016, The CryptoNote developers, The Bytecoin developers
 * Copyright (c) 2021-2024, The Quan Project developers
 *
 * Complete copyright information can be found in the accompanying LICENSE file
*/

#pragma once

namespace Q1v {

    class ICoreObserver {
    public:
        virtual ~ICoreObserver() {};

        virtual void blockchainUpdated() {};

        virtual void poolUpdated() {};
    };

}
