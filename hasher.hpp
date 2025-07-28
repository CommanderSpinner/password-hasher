#pragma once
#include <iostream>
#include <string>
#include <botan-3/botan/hash.h>
#include <botan-3/botan/hex.h>


class Hasher{
private:
    std::string password;

public:
    Hasher();
    ~Hasher();
};
