#ifndef PARSER_H
#define PARSER_H

#include <fstream>
#include <string>

class Parser
{
private:
    
    std::ifstream filestream;
    
public:

    enum cType{A_COMMAND, C_COMMAND, L_COMMAND, IGNORE};

    Parser(std::string path);
    ~Parser();
    bool hasMoreCommands();
    void advance();
    void reset();
    cType commandType();
    std::string symbol();
    std::string dest();
    std::string comp();
    std::string jump();

    std::string command;
};


#endif