//! Test the function that parses the cmd arguments given by the user !
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "ProcessCommandLine.hpp"
#include <iostream>
using namespace std;

TEST_CASE("Test help requested", "[cmdargs]"){
    ProgramSettings settings{false, false, "", "", "", CipherMode::Encrypt};
    const std::vector<std::string> args{"programName", "--help"};
    REQUIRE( processCommandLine(args, settings) == true );
    REQUIRE( settings.helpRequested == true );
}

TEST_CASE("Test version requested", "[cmdargs]"){
    ProgramSettings settings{false, false, "", "", "", CipherMode::Encrypt};
    const std::vector<std::string> args{"programName", "--version"};
    REQUIRE( processCommandLine(args, settings) == true );
    REQUIRE( settings.versionRequested == true );
}

TEST_CASE("Test input file requested", "[cmdargs]"){
    ProgramSettings settings{false, false, "", "", "", CipherMode::Encrypt};
    const std::vector<std::string> args{"programName", "-i", "inF.txt"};
    REQUIRE( processCommandLine(args, settings) == true );
    REQUIRE( settings.inputFile == "inF.txt" );
}

TEST_CASE("Test output file requested", "[cmdargs]"){
    ProgramSettings settings{false, false, "", "", "", CipherMode::Encrypt};
    const std::vector<std::string> args{"programName", "-o", "outF.txt"};
    REQUIRE( processCommandLine(args, settings) == true );
    REQUIRE( settings.outputFile == "outF.txt" );
}

TEST_CASE("Test cipher key requested", "[cmdargs]"){
    ProgramSettings settings{false, false, "", "", "", CipherMode::Encrypt};
    const std::vector<std::string> args{"programName", "-k", "4"};
    REQUIRE( processCommandLine(args, settings) == true );
    REQUIRE( settings.cipherKey == "4" );
}

TEST_CASE("Test cipher mode encrypt", "[cmdargs]"){
    ProgramSettings settings{false, false, "", "", "", CipherMode::Encrypt};
    const std::vector<std::string> args{"programName", "--encrypt"};
    REQUIRE( processCommandLine(args, settings) == true );
    REQUIRE( settings.mode == CipherMode::Encrypt );
}

TEST_CASE("Test cipher mode decrypt", "[cmdargs]"){
    ProgramSettings settings{false, false, "", "", "", CipherMode::Encrypt};
    const std::vector<std::string> args{"programName", "--decrypt"};
    REQUIRE( processCommandLine(args, settings) == true );
    REQUIRE( settings.mode == CipherMode::Decrypt );
}

TEST_CASE("Test non existing setting requested by cmd", "[cmdargs]"){
    ProgramSettings settings{false, false, "", "", "", CipherMode::Encrypt};
    const std::vector<std::string> args{"programName", "-kk"};
    const bool res{ processCommandLine(args, settings) };
    REQUIRE( !res );
    REQUIRE( settings.mode == CipherMode::Encrypt );//the default!
}