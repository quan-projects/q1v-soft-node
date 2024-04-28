/**
 * Copyright (c) 2012-2016, The CryptoNote developers, The Bytecoin developers
 * Copyright (c) 2021-2024, The Quan Project developers
 *
 * Complete copyright information can be found in the accompanying LICENSE file
*/

#pragma once

#include <mutex>
#include "CommonLogger.h"

namespace Logging {

    class ConsoleLogger : public CommonLogger {
    public:
        ConsoleLogger(Level level = DEBUGGING);

    protected:
        virtual void doLogString(const std::string &message) override;

    private:
        std::mutex mutex;
    };

}
