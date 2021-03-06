#pragma once
#include "contracts.hpp"
#include <eosio/chain/abi_serializer.hpp>
#include <eosio/testing/tester.hpp>

using namespace eosio::testing;
using namespace eosio;
using namespace eosio::chain;
using namespace eosio::testing;
using namespace fc;
using namespace std;

using mvo = fc::mutable_variant_object;
using action_result = base_tester::action_result;

class pbtx_api
{
public:
    pbtx_api(name acnt, tester* tester);

    fc::variant get_network(const uint64_t &network_id);
    fc::variant get_actor_permission(const uint64_t &network_id, const uint64_t &actor);
    fc::variant get_actor_sequence(const uint64_t &network_id, const uint64_t &actor);
    fc::variant get_metadata(const uint64_t &network_id);
    fc::variant get_history_id(const uint64_t &network_id);
    fc::variant get_history(const uint64_t &network_id, const uint64_t &id);

    action_result regnetwork(const account_name &signer, const uint64_t &network_id,
                             const name &admin_acc, const vector<name> &listeners, const uint32_t &flags);
    action_result netmetadata(const account_name &signer, const uint64_t &network_id, const std::vector<uint8_t> &metadata);
    action_result unregnetwork(const account_name &signer, const uint64_t &network_id);
    action_result regactor(const account_name &signer, const uint64_t &network_id, const vector<uint8_t> &permission);
    action_result unregactor(const account_name &signer, const uint64_t &network_id, const uint64_t &actor);
    action_result exectrx(const account_name &signer, const account_name &worker, const vector<uint8_t> &trx_input);
    action_result cleanhistory(const account_name &signer, const uint64_t &network_id, const uint64_t &upto_id, const uint32_t &maxrows);
    
    name contract;

private:
    action_result push_action(const name &signer, const name &cnt, const action_name &name, const variant_object &data);

    abi_serializer abi_ser;
    tester *_tester;
};
