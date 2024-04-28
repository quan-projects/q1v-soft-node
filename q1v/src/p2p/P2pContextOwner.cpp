/**
 * Copyright (c) 2012-2016, The CryptoNote developers, The Bytecoin developers
 * Copyright (c) 2021-2024, The Quan Project developers
 *
 * Complete copyright information can be found in the accompanying LICENSE file
*/

#include "P2pContextOwner.h"
#include <cassert>
#include "P2pContext.h"

namespace Q1v {

    P2pContextOwner::P2pContextOwner(P2pContext *ctx, ContextList &contextList) : contextList(contextList) {
        contextIterator = contextList.insert(contextList.end(), ContextList::value_type(ctx));
    }

    P2pContextOwner::P2pContextOwner(P2pContextOwner &&other) : contextList(other.contextList),
                                                                contextIterator(other.contextIterator) {
        other.contextIterator = contextList.end();
    }

    P2pContextOwner::~P2pContextOwner() {
        if (contextIterator != contextList.end()) {
            contextList.erase(contextIterator);
        }
    }

    P2pContext &P2pContextOwner::get() {
        assert(contextIterator != contextList.end());
        return *contextIterator->get();
    }

    P2pContext *P2pContextOwner::operator->() {
        return &get();
    }

}
