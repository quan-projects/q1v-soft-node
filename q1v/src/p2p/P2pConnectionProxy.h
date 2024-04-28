/**
 * Copyright (c) 2012-2016, The CryptoNote developers, The Bytecoin developers
 * Copyright (c) 2021-2024, The Quan Project developers
 *
 * Complete copyright information can be found in the accompanying LICENSE file
*/

#pragma once

#include <queue>

#include "IP2pNodeInternal.h"
#include "LevinProtocol.h"
#include "P2pContextOwner.h"
#include "P2pInterfaces.h"

namespace Q1v {

    class P2pContext;

    class P2pNode;

    class P2pConnectionProxy : public IP2pConnection {
    public:

        P2pConnectionProxy(P2pContextOwner &&ctx, IP2pNodeInternal &node);

        ~P2pConnectionProxy();

        bool processIncomingHandshake();

        // IP2pConnection
        virtual void read(P2pMessage &message) override;

        virtual void write(const P2pMessage &message) override;

        virtual void ban() override;

        virtual void stop() override;

    private:

        void writeHandshake(const P2pMessage &message);

        void handleHandshakeRequest(const LevinProtocol::Command &cmd);

        void handleHandshakeResponse(const LevinProtocol::Command &cmd, P2pMessage &message);

        void handleTimedSync(const LevinProtocol::Command &cmd);

        std::queue<P2pMessage> m_readQueue;
        P2pContextOwner m_contextOwner;
        P2pContext &m_context;
        IP2pNodeInternal &m_node;
    };

}
