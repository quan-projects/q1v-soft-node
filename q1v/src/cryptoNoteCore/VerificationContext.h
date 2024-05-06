/**
 * Copyright (c) 2012-2016, The CryptoNote developers, The Bytecoin developers
 * Copyright (c) 2021-2024, The Quan Project developers
 *
 * Complete copyright information can be found in the accompanying LICENSE file
*/

#pragma once
namespace Q1v {
    /************************************************************************/
    /*                                                                      */
    /************************************************************************/
    struct tx_verification_context {
        bool m_should_be_relayed;
        bool m_verifivation_failed; //bad tx, should drop connection
        bool m_verifivation_impossible; //the transaction is related with an alternative blockchain
        bool m_added_to_pool;
        bool m_tx_fee_too_small;
    };

    struct block_verification_context {
        bool m_added_to_main_chain;
        bool m_verifivation_failed; //bad block, should drop connection
        bool m_marked_as_orphaned;
        bool m_already_exists;
        bool m_switched_to_alt_chain;
    };
}
