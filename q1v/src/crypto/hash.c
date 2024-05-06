/**
 * Copyright (c) 2012-2016, The CryptoNote developers, The Bytecoin developers
 * Copyright (c) 2021-2024, The Quan Project developers
 *
 * Complete copyright information can be found in the accompanying LICENSE file
*/

#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include "hash-ops.h"
#include "keccak.h"

void hash_permutation(union hash_state *state) {
    keccakf((uint64_t *) state, 24);
}

void hash_process(union hash_state *state, const uint8_t *buf, size_t count) {
    keccak1600(buf, (int) count, (uint8_t *) state);
}

void q1v_fast_hash(const void *data, size_t length, char *hash) {
    union hash_state state;
    hash_process(&state, data, length);
    memcpy(hash, &state, HASH_SIZE);
}
