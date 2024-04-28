/**
 * Copyright (c) 2012-2016, The CryptoNote developers, The Bytecoin developers
 * Copyright (c) 2021-2024, The Quan Project developers
 *
 * Complete copyright information can be found in the accompanying LICENSE file
*/

#pragma once

#include "cryptoNoteCore/CryptoNoteBasic.h"

namespace Q1v {

    struct BlockInfo {
        uint32_t height;
        Crypto::Hash id;

        BlockInfo() {
            clear();
        }

        void clear() {
            height = 0;
            id = Q1v::NULL_HASH;
        }

        bool empty() const {
            return id == Q1v::NULL_HASH;
        }
    };

    class ITransactionValidator {
    public:
        virtual ~ITransactionValidator() {}

        virtual bool checkTransactionInputs(const Q1v::Transaction &tx, BlockInfo &maxUsedBlock) = 0;

        virtual bool
        checkTransactionInputs(const Q1v::Transaction &tx, BlockInfo &maxUsedBlock, BlockInfo &lastFailed) = 0;

        virtual bool haveSpentKeyImages(const Q1v::Transaction &tx) = 0;

        virtual bool checkTransactionSize(size_t blobSize) = 0;
    };

}
