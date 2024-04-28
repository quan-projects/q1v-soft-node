/**
 * Copyright (c) 2012-2016, The CryptoNote developers, The Bytecoin developers
 * Copyright (c) 2021-2024, The Quan Project developers
 *
 * Complete copyright information can be found in the accompanying LICENSE file
*/

#pragma once

#include <string>

#include <boost/program_options.hpp>

namespace Q1v {

    class CoreConfig {
    public:
        CoreConfig();

        static void initOptions(boost::program_options::options_description &desc);

        void init(const boost::program_options::variables_map &options);

        std::string configFolder;
        bool configFolderDefaulted = true;
    };

} //namespace Q1v
