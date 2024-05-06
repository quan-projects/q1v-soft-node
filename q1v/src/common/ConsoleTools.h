/**
 * Copyright (c) 2012-2016, The CryptoNote developers, The Bytecoin developers
 * Copyright (c) 2021-2024, The Quan Project developers
 *
 * Complete copyright information can be found in the accompanying LICENSE file
*/

#pragma once

#include <cstdint>

namespace Common {
    namespace Console {

        enum class Color : uint8_t {
            Default,
            Blue,
            Green,
            Red,
            Yellow,
            White,
            Cyan,
            Magenta,
            BrightBlue,
            BrightGreen,
            BrightRed,
            BrightYellow,
            BrightWhite,
            BrightCyan,
            BrightMagenta
        };

        void setTextColor(Color color);

        bool isConsoleTty();

    }
}
