/**
 * Copyright (c) 2012-2016, The CryptoNote developers, The Bytecoin developers
 * Copyright (c) 2021-2024, The Quan Project developers
 *
 * Complete copyright information can be found in the accompanying LICENSE file
*/

#include "CoreConfig.h"

#include "common/Util.h"
#include "common/CommandLine.h"

namespace Q1v {

    CoreConfig::CoreConfig() {
        configFolder = Tools::getDefaultDataDirectory();
    }

    void CoreConfig::init(const boost::program_options::variables_map &options) {
        if (options.count(command_line::arg_data_dir.name) != 0 &&
            (!options[command_line::arg_data_dir.name].defaulted() ||
             configFolder == Tools::getDefaultDataDirectory())) {
            configFolder = command_line::get_arg(options, command_line::arg_data_dir);
            configFolderDefaulted = options[command_line::arg_data_dir.name].defaulted();
        }
    }

    void CoreConfig::initOptions(boost::program_options::options_description &desc) {
    }
} //namespace Q1v
