#pragma once
#include <iostream>
#include <string>
#include <botan-3/botan/hash.h>
#include <botan-3/botan/hex.h>
#include <vector>


class Hasher{
private:
    std::string password;
    std::string hash_algo;
    std::vector<uint8_t> salt;
    std::unique_ptr<Botan::HashFunction> hash;
    size_t iterations;
    size_t key_length;

    void hashF();

public:
    Hasher(std::string hash_algo);
    ~Hasher();
};
