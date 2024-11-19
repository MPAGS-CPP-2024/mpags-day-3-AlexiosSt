//! Test the Caesar Cipher class, which handles the encryption/decryption of the transliterated input text !
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "CaesarCipher.hpp"
#include <iostream>
using namespace std;

TEST_CASE( "Check the encryption and decryption of an input text", "[ccipher]" ) {

    CaesarCipher ccipher("5");

    SECTION("Encryption of a text", "[ccipher]"){
        string instr{"HELLOWORLD"};
        REQUIRE( ccipher.applyCipher(instr, CipherMode::Encrypt) == "MJQQTBTWQI" );
    }

    SECTION("Decryption of a text", "[ccipher]"){
        string instr{"MJQQTBTWQI"};
        REQUIRE( ccipher.applyCipher(instr, CipherMode::Decrypt) == "HELLOWORLD" );
    }
        
}