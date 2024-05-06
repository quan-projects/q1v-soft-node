/**
 * Copyright (c) 2012-2016, The CryptoNote developers, The Bytecoin developers
 * Copyright (c) 2021-2024, The Quan Project developers
 *
 * Complete copyright information can be found in the accompanying LICENSE file
*/

#include "CommandLine.h"

namespace command_line {
    const arg_descriptor<bool> arg_help = {"help", "Produce help message"};
    const arg_descriptor<bool> arg_version = {"version", "Output version information"};
    const arg_descriptor<std::string> arg_data_dir = {"data-dir", "Specify data directory"};
}
