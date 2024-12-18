#ifndef MPAGSCIPHER_RUNCAESARCIPHER_HPP
#define MPAGSCIPHER_RUNCAESARCIPHER_HPP

#include "CipherMode.hpp"
#include <string>

//! Encrypt or decrypt text using the Caesar cipher with the given key
std::string runCaesarCipher(const std::string& inputText, const std::size_t key,
                            CipherMode encrypt);

#endif