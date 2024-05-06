/**
 * Copyright (c) 2012-2016, The CryptoNote developers, The Bytecoin developers
 * Copyright (c) 2021-2024, The Quan Project developers
 *
 * Complete copyright information can be found in the accompanying LICENSE file
*/

#include "FileLogger.h"

namespace Logging {

    FileLogger::FileLogger(Level level) : StreamLogger(level) {
    }

    void FileLogger::init(const std::string &fileName) {
        fileStream.open(fileName, std::ios::app);
        StreamLogger::attachToStream(fileStream);
    }

}
