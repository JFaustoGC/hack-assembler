#include <iostream>
#include <iostream>
#include <fstream>
#include <string>
#include <istream>
#include <bitset>
#include "parser.h"
#include "code.h"
#include "symboltable.h"

int main(int argc, char **argv) {

    std::string filename (argv[1]);
    std::string pathr = "../Data/" + filename + ".asm";
    std::string pathw = "../Data/" + filename + ".hack";
    Parser parser (pathr);
    Code opcode;
    std::string mnemomic;
    std::string binary = "";
    std::bitset<16> bin;
    Symboltable table;
    

    

    if (std::ifstream(pathr).good()) {
        int idx = 0;
        while (parser.hasMoreCommands()) {
            parser.advance();
           
            if (parser.commandType() == Parser::cType::L_COMMAND) {
                table.addEntry(parser.symbol(), idx);
            }
            if (parser.commandType() != Parser::cType::IGNORE) idx++;
        }

        parser.reset();

        //std::ofstream ofs(pathw, std::ofstream::trunc);
        while(parser.hasMoreCommands() ) { 
            parser.advance();
            switch (parser.commandType())
            {
            case Parser::cType::A_COMMAND:
                mnemomic = parser.symbol();
                std::cout << parser.command << std::endl;
                //bin = std::bitset<16> (std::stoi(mnemomic));
                //binary = bin.to_string();
                break;
            case Parser::cType::C_COMMAND:
                std::cout << parser.command[0] << std::endl;
                binary = "111" + opcode.comp(parser.comp()) + opcode.dest(parser.dest()) + opcode.jump(parser.jump());
                break;
            case Parser::cType::L_COMMAND:
                mnemomic = parser.symbol();
                mnemomic = std::to_string(table.getAddress(mnemomic));
                bin = std::bitset<16> (std::stoi(mnemomic));
                binary = bin.to_string();
                //ofs << mnemomic << std::endl;
                break;
            case Parser::cType::IGNORE:
                break;
           }
            //ofs << binary << "\n";
            binary = "";
        }
    }

    

    return 0;
}