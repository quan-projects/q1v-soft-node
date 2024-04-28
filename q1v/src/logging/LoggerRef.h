/**
 * Copyright (c) 2012-2016, The CryptoNote developers, The Bytecoin developers
 * Copyright (c) 2021-2024, The Quan Project developers
 *
 * Complete copyright information can be found in the accompanying LICENSE file
*/

#pragma once

#include "ILogger.h"
#include "LoggerMessage.h"

namespace Logging {

    class LoggerRef {
    public:
        LoggerRef(ILogger &logger, const std::string &category);

        LoggerMessage operator()(Level level = INFO, const std::string &color = DEFAULT) const;

        ILogger &getLogger() const;

    private:
        ILogger *logger;
        std::string category;
    };

}
