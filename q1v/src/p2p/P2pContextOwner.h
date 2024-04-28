/**
 * Copyright (c) 2012-2016, The CryptoNote developers, The Bytecoin developers
 * Copyright (c) 2021-2024, The Quan Project developers
 *
 * Complete copyright information can be found in the accompanying LICENSE file
*/

#pragma once

#include <list>
#include <memory>

namespace Q1v {

    class P2pContext;

    class P2pContextOwner {
    public:

        typedef std::list<std::unique_ptr<P2pContext>> ContextList;

        P2pContextOwner(P2pContext *ctx, ContextList &contextList);

        P2pContextOwner(P2pContextOwner &&other);

        P2pContextOwner(const P2pContextOwner &other) = delete;

        ~P2pContextOwner();

        P2pContext &get();

        P2pContext *operator->();

    private:

        ContextList &contextList;
        ContextList::iterator contextIterator;
    };

}
