/**
 * Copyright (c) 2012-2016, The CryptoNote developers, The Bytecoin developers
 * Copyright (c) 2021-2024, The Quan Project developers
 *
 * Complete copyright information can be found in the accompanying LICENSE file
*/

#pragma once

#include "cryptoNoteCore/CryptoNoteBasic.h"
#include "crypto/crypto.h"

namespace Q1v {

    class ISerializer;

    /************************************************************************/
    /*                                                                      */
    /************************************************************************/
    class AccountBase {
    public:
        AccountBase();

        void generate();

        void generateDeterministic();

        const AccountKeys &getAccountKeys() const;

        void setAccountKeys(const AccountKeys &keys);

        uint64_t get_createtime() const { return m_creation_timestamp; }

        void set_createtime(uint64_t val) { m_creation_timestamp = val; }

        void serialize(ISerializer &s);

        template<class t_archive>
        inline void serialize(t_archive &a, const unsigned int /*ver*/) {
            a & m_keys;
            a & m_creation_timestamp;
        }

    private:
        void setNull();

        AccountKeys m_keys;
        uint64_t m_creation_timestamp;
    };
}
