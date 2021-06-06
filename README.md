PBTX: Protocol Buffers Transaction protocol
===========================================

The goal of the project is to provide a base protocol for secure
mobile transactions, aiming for the following goals:

* Cryptographically protected security: every rtansaction is signed by
  the actor's private keys, and the protocol maintains the association
  of public keys and actors.

* Built-in integrity: every transaction has a sequence number, and the
  protocol keeps track of the last sequence number for every actor. It
  only accepts a next transaction with sequence number incremented by
  one.

* Low bandwidth: the transactions are compact and require only
  moinimal communication between the clients and servers. TRansactions
  can also be accumulated in offline storage and pushed to the network
  any time later.

* Built-in multi-signature: a transaction can be signed by multiple
  public keys.

* Universal base protocol: PBTX does not interpret the transaction
  content, and leaves its interpretation to the network-specific
  services. The protocol also allows multiple networks to use the same
  transport infrastructure.


EOSIO blockchain backend
------------------------

Currently EOSIO blockckchain is selected as the primary backend for
the protocol. It provides a smart contract that registers networks and
actors, and validates arriving transactions. It sends notifications to
network-specific listeners for further processing of the transaction
content.


