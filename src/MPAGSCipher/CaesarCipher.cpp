#include "CaesarCipher.hpp"
#include <iostream>
using namespace std;

CaesarCipher::CaesarCipher(const size_t& cipherKey):
    key_{cipherKey} {}

CaesarCipher::CaesarCipher(const string& cipherKey){
    // We have the key as a string, but the Caesar cipher needs an unsigned long
    if (!cipherKey.empty()) {
        // Here we loop through each character and checking that it
        // is a digit. We may also wish to check whether the number is too large 
        // to be represented by an unsigned long.
        for (const auto& elem : cipherKey) {
            if (!std::isdigit(elem)) {
                std::cerr
                    << "[error] cipher key must be an unsigned long integer for Caesar cipher,\n"
                    << "        the supplied key (" << cipherKey
                    << ") could not be successfully converted" << std::endl;
                exit(EXIT_FAILURE);
            }
        }
        key_ = std::stoul(cipherKey);
    }
}

std::string CaesarCipher::applyCipher(const std::string& inputText, const bool encrypt){
    // Create the output string
    std::string outputText;

    const std::size_t alphabetSize{abc_.size()};

    // Make sure that the key is in the range 0 - 25
    const std::size_t truncatedKey{key_ % alphabetSize};

    // Loop over the input text
    char processedChar{'x'};
    for (const auto& origChar : inputText) {
        // For each character in the input text, find the corresponding position in
        // the alphabet by using an indexed loop over the alphabet container
        for (size_t i{0}; i < alphabetSize; ++i) {
            if (origChar == abc_[i]) {
                // Apply the appropriate shift (depending on whether we're encrypting
                // or decrypting) and determine the new character
                // Can then break out of the loop over the alphabet
                if (encrypt) {
                    processedChar = abc_[(i + truncatedKey) % alphabetSize];
                } else {
                    processedChar = abc_[(i + alphabetSize - truncatedKey) %
                                             alphabetSize];
                }
                break;
            }
        }

        // Add the new character to the output text
        outputText += processedChar;
    }
    return outputText;
}
