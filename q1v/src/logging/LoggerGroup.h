/**
 * Copyright (c) 2012-2016, The CryptoNote developers, The Bytecoin developers
 * Copyright (c) 2021-2024, The Quan Project developers
 *
 * Complete copyright information can be found in the accompanying LICENSE file
*/

#pragma once

#include <vector>
#include "CommonLogger.h"

namespace Logging {

    class LoggerGroup : public CommonLogger {
    public:
        LoggerGroup(Level level = DEBUGGING);

        void addLogger(ILogger &logger);

        void removeLogger(ILogger &logger);

        virtual void operator()(const std::string &category, Level level, boost::posix_time::ptime time,
                                const std::string &body) override;

    protected:
        std::vector<ILogger *> loggers;
    };

}
