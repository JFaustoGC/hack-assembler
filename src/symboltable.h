#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include <unordered_map>
#include <string>

class Symboltable
{
private:
    

public:
    std::unordered_map<std::string, int> table;
    Symboltable();
    void addEntry(std::string symbol, int address);
    bool contains(std::string symbol);
    int getAddress(std::string symbol);
};



#endif