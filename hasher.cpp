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

    hashOfPassword = "-1";

    this->hash_algo = hash_algo;
    this->password = password;
    this->iterations = iterations;
    this->key_length = key_length;
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

    // Example with another hash
    /*
    std::string data2 = "Another piece of data.";
    std::unique_ptr<Botan::HashFunction> hash_sha3_512(Botan::HashFunction::create("SHA-3(512)"));
    if (hash_sha3_512) {
        hash_sha3_512->update(data2);
        std::string hex_digest2 = Botan::hex_encode(hash_sha3_512->final());
        std::cout << "Data: " << data2 << std::endl;
        std::cout << "SHA-3(512) Hash: " << hex_digest2 << std::endl;
    }
    */
}

std::string Hasher::getHashOfPassword() {
    return hashOfPassword;
}

