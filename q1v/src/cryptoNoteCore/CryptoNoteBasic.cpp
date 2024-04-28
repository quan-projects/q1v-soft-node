/**
 * Copyright (c) 2012-2016, The CryptoNote developers, The Bytecoin developers
 * Copyright (c) 2021-2024, The Quan Project developers
 *
 * Complete copyright information can be found in the accompanying LICENSE file
*/

#include "CryptoNoteBasic.h"
#include "crypto/crypto.h"

namespace Q1v {

    KeyPair generateKeyPair() {
        KeyPair k;
        Crypto::generate_keys(k.publicKey, k.secretKey);
        return k;
    }

}
