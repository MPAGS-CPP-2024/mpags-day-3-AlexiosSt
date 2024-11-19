//! Test the function that parses the cmd arguments given by the user !
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "ProcessCommandLine.hpp"
#include <iostream>
using namespace std;

void resetSetup(ProgramSettings& setup){
    setup={false, false, "", "", "", CipherMode::Encrypt};
}

TEST_CASE("Set of cmd arguments used", "[args]"){
    ProgramSettings settings{false, false, "", "", "", CipherMode::Encrypt};
    std::vector<std::string> args{"programName", "--help"};
    REQUIRE( processCommandLine(args, settings) == true );
    REQUIRE( settings.versionRequested == false );
    REQUIRE( settings.helpRequested == true );
    REQUIRE( settings.mode == CipherMode::Encrypt );

    resetSetup(settings);
    args.push_back("--version");
    REQUIRE( processCommandLine(args, settings) == true );
    REQUIRE( settings.mode == CipherMode::Encrypt );
    REQUIRE( settings.versionRequested == false );
    REQUIRE( settings.helpRequested == true );

    resetSetup(settings);
    args.at(1)="--version";
    REQUIRE( processCommandLine(args, settings) == true );
    REQUIRE( settings.versionRequested == true );
    REQUIRE( settings.helpRequested == false );

    resetSetup(settings);
    args.push_back("--help"); args.push_back("--decrypt");
    REQUIRE( processCommandLine(args, settings) == true );
    REQUIRE( settings.mode == CipherMode::Encrypt );

    resetSetup(settings);
    args={"programName", "-k", "4"};
    REQUIRE( processCommandLine(args, settings) == true );
    REQUIRE( settings.cipherKey == "4" );
    REQUIRE( settings.helpRequested == false );

    resetSetup(settings);
    //args.clear();
    args={"programName", "-o"};
    REQUIRE( processCommandLine(args, settings) == false );
    args.push_back("outF.txt");
    REQUIRE( processCommandLine(args, settings) == true );
    REQUIRE( settings.outputFile == "outF.txt");
 
    resetSetup(settings);
    args={"programName", "-i"};
    REQUIRE( processCommandLine(args, settings) == false );
    args.push_back("inF.txt");
    REQUIRE( processCommandLine(args, settings) == true );
    REQUIRE( settings.inputFile == "inF.txt");

    resetSetup(settings);
    args.push_back("kk");
    REQUIRE( processCommandLine(args, settings) == false );

    resetSetup(settings);
    args={"programName", "-k"};
    REQUIRE( processCommandLine(args, settings) == false );
}