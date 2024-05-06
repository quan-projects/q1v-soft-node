/**
 * Copyright (c) 2016-2019, The Karbo developers
 * Copyright (c) 2021-2024, The Quan Project developers
 *
 * Complete copyright information can be found in the accompanying LICENSE file
*/

#pragma once

#include <string>
#include <vector>

namespace Common {

    bool fetch_dns_txt(const std::string domain, std::vector<std::string> &records);

}
