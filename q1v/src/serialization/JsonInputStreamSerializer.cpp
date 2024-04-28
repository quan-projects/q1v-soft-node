/**
 * Copyright (c) 2012-2016, The CryptoNote developers, The Bytecoin developers
 * Copyright (c) 2021-2024, The Quan Project developers
 *
 * Complete copyright information can be found in the accompanying LICENSE file
*/

#include "serialization/JsonInputStreamSerializer.h"

#include <ctype.h>
#include <exception>

namespace Q1v {

    namespace {

        Common::JsonValue getJsonValueFromStreamHelper(std::istream &stream) {
            Common::JsonValue value;
            stream >> value;
            return value;
        }

    }

    JsonInputStreamSerializer::JsonInputStreamSerializer(std::istream &stream) : JsonInputValueSerializer(
            getJsonValueFromStreamHelper(stream)) {
    }

    JsonInputStreamSerializer::~JsonInputStreamSerializer() {
    }

} //namespace Q1v
