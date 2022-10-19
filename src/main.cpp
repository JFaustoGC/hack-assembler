#include <iostream>
#include <iostream>
#include <fstream>
#include <string>
#include <istream>
#include <bitset>
#include "parser.h"
#include "code.h"

int main(int argc, char **argv) {

    std::string filename (argv[1]);
    std::string pathr = "../Data/" + filename + ".asm";
    std::string pathw = "../Data/" + filename + ".hack";
    Parser parser (pathr);
    Code opcode;
    std::string mnemomic;
    std::string binary = "";
    std::bitset<16> bin;
    std::string dest;
    std::string comp;
    std::string jump;
    

    if (std::ifstream(pathr).good()) {
        std::ofstream ofs(pathw, std::ofstream::trunc);
        while(parser.hasMoreCommands() ) { 
            parser.advance();
            switch (parser.commandType())
            {
            case Parser::cType::A_COMMAND:
                mnemomic = parser.symbol();
                bin = std::bitset<16> (std::stoi(mnemomic));
                binary = bin.to_string();
                ofs << binary << std::endl;
                binary = "";
                break;
            case Parser::cType::C_COMMAND:
                dest = parser.dest();
                comp = parser.comp();
                jump = parser.jump();
                comp = opcode.comp(comp);
                dest = opcode.dest(dest);
                jump = opcode.jump(jump);
                binary = "111" + comp + dest + jump;
                ofs << binary << "\n";
                binary = "";
                break;
            case Parser::cType::L_COMMAND:
                mnemomic = parser.symbol();
                ofs << mnemomic << std::endl;
                break;
            case Parser::cType::IGNORE:
                break;
           }
 
        }

    } 

    return 0;
}