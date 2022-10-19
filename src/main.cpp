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
                break;
            case Parser::cType::C_COMMAND:
                binary = "111" + opcode.comp(parser.comp()) + opcode.dest(parser.dest()) + opcode.jump(parser.jump());
                break;
            case Parser::cType::L_COMMAND:
                mnemomic = parser.symbol();
                ofs << mnemomic << std::endl;
                break;
            case Parser::cType::IGNORE:
                break;
           }
            ofs << binary << "\n";
            binary = "";
        }

    } 

    return 0;
}