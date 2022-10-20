#include "parser.h"
#include <algorithm>

Parser::Parser(std::string path) {
    filestream = std::ifstream (path);
}

Parser::~Parser() {
    filestream.close();
}

bool Parser::hasMoreCommands () {
    return filestream.peek() != EOF;
}

void Parser::reset() {
    filestream.clear();
    filestream.seekg(0);
}

void Parser::advance () {
    std::getline(filestream, command);
}

Parser::cType Parser::commandType() {
    command.erase(std::remove_if(command.begin(), command.end(), ::isspace), command.end());
    if (command.size() <= 1 || command[0] == '/')
        return Parser::cType::IGNORE;
    else if (command[0] == '(')
        return Parser::cType::L_COMMAND;
    else if (command[0] == '@')
        return Parser::cType::A_COMMAND;
    else 
        return Parser::cType::C_COMMAND;
}

std::string Parser::symbol() {
       return command.substr(1, command.size() - 1); 
}

std::string Parser::dest() {
    std::string dest = "";
    if (command.find('=') != std::string::npos) {
        int idx = command.find('=');
        dest = command.substr(0, idx);
    }
    return dest;
}

std::string Parser::comp(){
    std::string comp = "";
    int sidx = 0;
    int fidx = command.size();
    if (command.find('=') != std::string::npos) 
        sidx = command.find('=') + 1  ;
    if (command.find(';') != std::string::npos) 
        fidx = command.find(';');
    comp = command.substr(sidx, fidx - sidx);
    return comp;
}

std::string Parser::jump() {
    std::string jump = "";
    if (command.find(';') != std::string::npos) {
        int idx = command.find(';');
        jump = command.substr(idx + 1, command.size() - idx - 1);
        }
    return jump;
}