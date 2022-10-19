#include "code.h"
#include <iostream>
#include <algorithm>
Code::Code() {

}

std::string Code::dest(std::string mnemonic) {
    mnemonic.erase(remove_if(mnemonic.begin(), mnemonic.end(), isspace), mnemonic.end());
    //std::cout << "received " << mnemonic << "\n";
    if (mnemonic == "")
        return std::string("000");
    else if (mnemonic == "M")
        return std::string("001");
    else if (mnemonic == "D")
        return std::string("010");
    else if (mnemonic == "MD")
        return std::string("011");
    else if (mnemonic == "A")
        return std::string("100");
    else if (mnemonic == "AM")
        return std::string("101");
    else if (mnemonic == "AD")
        return std::string("110");
    else
        return std::string("111");
}

std::string Code::jump(std::string mnemonic) {
    mnemonic.erase(remove_if(mnemonic.begin(), mnemonic.end(), isspace), mnemonic.end());
    //std::cout << "received " << mnemonic << "\n" ;
    if (mnemonic == "")
        return std::string("000");
    else if (mnemonic == "JGT")
        return std::string("001");
    else if (mnemonic == "JEQ")
        return std::string("010");
    else if (mnemonic == "JGE")
        return std::string("011");
    else if (mnemonic == "JLT")
        return std::string("100");
    else if (mnemonic == "JNE")
        return std::string("101");
    else if (mnemonic == "JLE")
        return std::string("110");
    else 
        return std::string("111");
}

std::string Code::comp(std::string mnemonic) {
    mnemonic.erase(remove_if(mnemonic.begin(), mnemonic.end(), isspace), mnemonic.end());
    //std::cout << "received " << mnemonic << "\n";
    if (mnemonic == "0")
        return std::string("0101010");
    else if (mnemonic == "1")
        return std::string("0111111");
    else if (mnemonic == "-1")
        return std::string("0111010");
    else if (mnemonic == "D")
        return std::string("0001100");
    else if (mnemonic == "A")
        return std::string("0110000");
    else if (mnemonic == "!D")
        return std::string("0001101");
    else if (mnemonic == "!A")
        return std::string("0110001");
    else if (mnemonic == "-D")
        return std::string("0001111");
    else if (mnemonic == "-A")
        return std::string("0110011");
    else if (mnemonic == "D+1")
        return std::string("0011111");
    else if (mnemonic == "A+1")
        return std::string("0110111");
    else if (mnemonic == "D-1")
        return std::string("0001110");
    else if (mnemonic == "A-1")
        return std::string("0110010");
    else if (mnemonic == "D+A")
        return std::string("0000010");
    else if (mnemonic == "D-A")
        return std::string("0010011");
    else if (mnemonic == "A-D")
        return std::string("0000111");
    else if (mnemonic == "D&A")
        return std::string("0000000");
    else if (mnemonic == "D|A")
        return std::string("0010101");
    else if (mnemonic == "M")
        return std::string("1110000");
    else if (mnemonic == "!M")
        return std::string("1110001");
    else if (mnemonic == "-M")
        return std::string("1110011");
    else if (mnemonic == "M+1")
        return std::string("1110111");
    else if (mnemonic == "M-1")
        return std::string("1110010");
    else if (mnemonic == "D+M")
        return std::string("1000010");
    else if (mnemonic == "D-M")
        return std::string("1010011");
    else if (mnemonic == "M-D")
        return std::string("1000111");
    else if (mnemonic == "D&M")
        return std::string("1000000");
    else
        return std::string("1010101");
}