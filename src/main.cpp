#include <iostream>
#include <vector>
#include <sodium.h>
#include <openssl/evp.h>
#include <iomanip>

/**
 * Hashes the provided data using the BLAKE2 algorithm.
 * 
 * @param data Input data to be hashed.
 * @return A vector containing the BLAKE2 hash of the input data.
 */
std::vector<unsigned char> hash_with_blake2(const std::vector<unsigned char>& data) {
    std::vector<unsigned char> hash_output(crypto_generichash_BYTES);
    crypto_generichash(hash_output.data(), hash_output.size(), data.data(), data.size(), nullptr, 0);
    return hash_output;
}

/**
 * Hashes the provided data using the SHA-3 algorithm.
 * 
 * @param data Input data to be hashed.
 * @return A vector containing the SHA-3 hash of the input data.
 */
std::vector<unsigned char> hash_with_sha3(const std::vector<unsigned char>& data) {
    std::vector<unsigned char> hash_output(32);  // Using SHA3-256
    EVP_MD_CTX *mdctx = EVP_MD_CTX_new();
    const EVP_MD *md = EVP_sha3_256();
    EVP_DigestInit_ex(mdctx, md, nullptr);
    EVP_DigestUpdate(mdctx, data.data(), data.size());
    EVP_DigestFinal_ex(mdctx, hash_output.data(), nullptr);
    EVP_MD_CTX_free(mdctx);
    return hash_output;
}

int main() {
    std::string domain, baseKey;

    // Prompt the user for the domain
    std::cout << "Enter the domain: ";
    std::getline(std::cin, domain);

    // Prompt the user for the base key
    std::cout << "Enter the base keyphrase: ";
    std::getline(std::cin, baseKey);

    // Combine the two inputs, or process them however you want
    std::string combinedInput = domain + baseKey;

    // Compute the hash
    std::vector<unsigned char> input(combinedInput.begin(), combinedInput.end());
    auto hashed = hash_with_blake2(input);
    hashed = hash_with_sha3(hashed);

    // Print the resulting hash
    for (auto byte : hashed) {
        printf("%02x", byte);
    }
    std::cout << std::endl;

    std::cout << "Press Enter to continue...";
    std::cin.get();  // Wait for user to press Enter
    return 0;
}
