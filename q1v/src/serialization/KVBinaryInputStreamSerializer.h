/**
 * Copyright (c) 2012-2016, The CryptoNote developers, The Bytecoin developers
 * Copyright (c) 2021-2024, The Quan Project developers
 *
 * Complete copyright information can be found in the accompanying LICENSE file
*/

#pragma once

#include <common/IInputStream.h>
#include "ISerializer.h"
#include "JsonInputValueSerializer.h"

namespace Q1v {

    class KVBinaryInputStreamSerializer : public JsonInputValueSerializer {
    public:
        KVBinaryInputStreamSerializer(Common::IInputStream &strm);

        virtual bool binary(void *value, size_t size, Common::StringView name) override;

        virtual bool binary(std::string &value, Common::StringView name) override;
    };

}
