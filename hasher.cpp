#include "hasher.hpp"
#include <botan/auto_rng.h>
#include <botan/hex.h>
#include <botan/hash.h>
#include <iostream>
#include <string>
#include <botan-3/botan/hash.h>
#include <botan-3/botan/hex.h>
#include <vector>
#include <memory>


Hasher::Hasher(std::string hash_algo,
               std::string password,
               size_t iterations,
               size_t key_length
        )
{
    std::cout << "creating hashser \n";

    this->hashOfPassword = "-1"; // initialise it to -1 in case something goes wrong its -1

    this->hash_algo = hash_algo;
    this->password = password;
    this->iterations = iterations;
    this->key_length = key_length;

    this->hashF();
}

Hasher::~Hasher(){
    std::cout << "destroying hashser \n";
}

void Hasher::hashF()
{
    std::unique_ptr<Botan::HashFunction> hash(Botan::HashFunction::create(hash_algo));

    hash->update(password);

    // Get the hash digest
    Botan::secure_vector<uint8_t> digest = hash->final();

    // Convert the digest to a hexadecimal string for printing
    std::string hex_digest = Botan::hex_encode(digest);

    std::cout << "password: " << password << std::endl;
    std::cout << "Hash: " << hex_digest << std::endl;

    this->hashOfPassword = hex_digest;
}

std::string Hasher::getHashOfPassword() {
    return hashOfPassword;
}

