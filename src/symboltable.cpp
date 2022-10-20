#include "symboltable.h"

Symboltable::Symboltable() {
    table = 
    {
        {"SP", 0}, {"LCL", 1}, {"ARG", 2}, {"THIS", 3}, {"THAT", 4},
        {"R0", 0}, {"R1", 1}, {"R2", 2}, {"R3", 3},
        {"R0", 4}, {"R1", 5}, {"R2", 6}, {"R3", 7},
        {"R0", 8}, {"R1", 9}, {"R2", 10}, {"R3", 11},
        {"R0", 12}, {"R1", 13}, {"R2", 14}, {"R3", 15},
        {"SCREEN", 16384,}, {"KBD", 24576}
    };
}

void Symboltable::addEntry(std::string symbol, int address) {
    table.insert({symbol, address});
}

bool Symboltable::contains(std::string symbol) {
    return (table.find(symbol) != table.end());
}

int Symboltable::getAddress(std::string symbol) {
    return table.at(symbol);
}