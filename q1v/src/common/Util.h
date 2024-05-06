/**
 * Copyright (c) 2012-2016, The CryptoNote developers, The Bytecoin developers
 * Copyright (c) 2021-2024, The Quan Project developers
 *
 * Complete copyright information can be found in the accompanying LICENSE file
*/

#pragma once

#include <string>
#include <system_error>

namespace Tools {
    std::string getDataDirectory();

    std::string getDefaultDataDirectory();

    std::string getRebrandDataDirectory();

    std::string get_os_version_string();

    bool create_directories_if_necessary(const std::string &path);

    std::error_code replace_file(const std::string &replacement_name, const std::string &replaced_name);

    bool directoryExists(const std::string &path);
}
