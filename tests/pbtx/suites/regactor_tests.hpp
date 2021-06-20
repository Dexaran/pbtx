#include "pbtx_tester.hpp"

BOOST_AUTO_TEST_SUITE(regactor_tests)

BOOST_FIXTURE_TEST_CASE(asserts_regactor_test, pbtx_tester)
try
{
    // BOOST_REQUIRE_EQUAL(error("missing authority of bob"), 
    //                     m_pbtx_api.regactor(N(alice), 1000, {}));

    // BOOST_REQUIRE_EQUAL(wasm_assert_msg("Unknown network"),
    //                     m_pbtx_api.regactor(N(alice), 666, {}));

    // BOOST_REQUIRE_EQUAL(wasm_assert_msg("Threshold cannot be zero"),
    //                     m_pbtx_api.regactor(N(alice), 666, {}));

    // BOOST_REQUIRE_EQUAL(wasm_assert_msg("Key weight cannot be zero in key #"),
    //                     m_pbtx_api.regactor(N(alice), 666, {}));

    // BOOST_REQUIRE_EQUAL(wasm_assert_msg("Unknown key type: "),
    //                     m_pbtx_api.regactor(N(alice), 666, {}));

    // BOOST_REQUIRE_EQUAL(wasm_assert_msg("Key # is too short"),
    //                     m_pbtx_api.regactor(N(alice), 666, {}));

    // BOOST_REQUIRE_EQUAL(wasm_assert_msg("Threshold cannot be higher than sum of weights"),
    //                     m_pbtx_api.regactor(N(alice), 666, {}));

    // BOOST_REQUIRE_EQUAL(wasm_assert_msg("Unknown network"),
    //                     m_pbtx_api.regactor(N(alice), 666, {}));
}
FC_LOG_AND_RETHROW()

BOOST_FIXTURE_TEST_CASE(regactor_test, pbtx_tester)
try
{
    key keys{{get_public_key(N(alice), "active"), pbtx_KeyType_EOSIO_KEY, 1}};
    auto permisson = encode_permisson(string_to_uint64_t("alice"), 1, keys.size(), keys);
    
    BOOST_REQUIRE_EQUAL(success(), m_pbtx_api.regactor(N(bob), 1000, permisson));

    // auto permission = m_pbtx_api.get_actor_permission(1000, string_to_uint64_t("alice"));

    // REQUIRE_MATCHING_OBJECT(permission, mvo()
    // ("actor", "")
    // ("permission", ""));

    // auto sequence = m_pbtx_api.get_actor_sequence(1000, string_to_uint64_t("alice"));

    // REQUIRE_MATCHING_OBJECT(sequence, mvo()
    // ("actor", "")
    // ("seqnum", "")
    // ("last_modified", ""));
}
FC_LOG_AND_RETHROW()

BOOST_AUTO_TEST_SUITE_END()
