#pragma once
#include <botan/auto_rng.h>
#include <botan/hex.h>
#include <botan/hash.h>
#include <iostream>
#include <string>
#include <botan-3/botan/hash.h>
#include <botan-3/botan/hex.h>
#include <vector>
#include <memory>

class Hasher{
private:
    Botan::AutoSeeded_RNG rng;
    std::string password;
    std::string hash_algo;
    std::vector<uint8_t> salt;
    size_t iterations;
    size_t key_length;

    std::string hashOfPassword;
    
    void hashF();
public:
    Hasher(std::string hash_algo, std::string password, size_t iterations, size_t key_length);
    ~Hasher();

    std::string getHashOfPassword();
};
