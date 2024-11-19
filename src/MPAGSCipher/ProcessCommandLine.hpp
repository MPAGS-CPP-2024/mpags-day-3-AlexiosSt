#ifndef MPAGSCIPHER_PROCESSCOMMANDLINE_HPP
#define MPAGSCIPHER_PROCESSCOMMANDLINE_HPP

#include "CipherMode.hpp"
#include <string>
#include <vector>

struct ProgramSettings{
    bool helpRequested{false};
    bool versionRequested{false};
    std::string inputFile{""};
    std::string outputFile{""};
    std::string cipherKey{""};
    CipherMode mode{CipherMode::Encrypt};
};

bool processCommandLine(const std::vector<std::string>& cmdLineArgs,
                        ProgramSettings& settings);

#endif    // MPAGSCIPHER_PROCESSCOMMANDLINE_HPP