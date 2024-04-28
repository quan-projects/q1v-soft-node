/**
 * Copyright (c) 2012-2016, The CryptoNote developers, The Bytecoin developers
 * Copyright (c) 2021-2024, The Quan Project developers
 *
 * Complete copyright information can be found in the accompanying LICENSE file
*/

#pragma once

#include <fstream>
#include "StreamLogger.h"

namespace Logging {

    class FileLogger : public StreamLogger {
    public:
        FileLogger(Level level = DEBUGGING);

        void init(const std::string &filename);

    private:
        std::ofstream fileStream;
    };

}
