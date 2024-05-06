/**
 * Copyright (c) 2012-2016, The CryptoNote developers, The Bytecoin developers
 * Copyright (c) 2021-2024, The Quan Project developers
 *
 * Complete copyright information can be found in the accompanying LICENSE file
*/

#include "LoggerRef.h"

namespace Logging {

    LoggerRef::LoggerRef(ILogger &logger, const std::string &category) : logger(&logger), category(category) {
    }

    LoggerMessage LoggerRef::operator()(Level level, const std::string &color) const {
        return LoggerMessage(*logger, category, level, color);
    }

    ILogger &LoggerRef::getLogger() const {
        return *logger;
    }

}
