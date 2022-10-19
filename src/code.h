#ifndef CODE_H
#define CODE_H

#include <bitset>
#include <string>

class Code
{
private:

public:
    Code();
    std::string dest(std::string mnemonic);
    std::string comp(std::string mnemonic);
    std::string jump(std::string mneminic);
};


#endif