/**
 * Copyright (c) 2012-2016, The CryptoNote developers, The Bytecoin developers
 * Copyright (c) 2021-2024, The Quan Project developers
 *
 * Complete copyright information can be found in the accompanying LICENSE file
*/

#pragma once

#include <iosfwd>
#include <string>
#include <vector>
#include "../common/JsonValue.h"
#include "JsonInputValueSerializer.h"

namespace Q1v {

//deserialization
    class JsonInputStreamSerializer : public JsonInputValueSerializer {
    public:
        JsonInputStreamSerializer(std::istream &stream);

        virtual ~JsonInputStreamSerializer();
    };

}
