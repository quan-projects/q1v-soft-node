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

    class StreamLogger : public CommonLogger {
    public:
        StreamLogger(Level level = DEBUGGING);

        StreamLogger(std::ostream &stream, Level level = DEBUGGING);

        void attachToStream(std::ostream &stream);

    protected:
        virtual void doLogString(const std::string &message) override;

    protected:
        std::ostream *stream;

    private:
        std::mutex mutex;
    };

}
