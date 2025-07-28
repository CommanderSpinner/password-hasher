#include "hasher.hpp"

Hasher::Hasher(std::string hash_algo){
    std::cout << "creating hashser \n";
    this->hash_algo = hash_algo;
}

Hasher::~Hasher(){
    std::cout << "destroying hashser \n";
}

void Hasher::hashF()
{
    // Create PBKDF2 object
    Botan::PBKDF* pbkdf = new Botan::PBKDF2(hash.release());

    // Prepare output buffer
    std::vector<uint8_t> derived_key(key_length);

    // Derive the key (hash the password)
    pbkdf->derive_key(derived_key.data(), derived_key.size(),
                      password.data(), password.size(),
                      salt.data(), salt.size(),
                      iterations);

    // Print the derived key as hex
    std::cout << "PBKDF2 hash: " << Botan::hex_encode(derived_key) << "\n";
}

