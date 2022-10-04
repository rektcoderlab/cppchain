#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include <vector>
#include "Block.h"

class Blockchain {
private:
    std::vector<Block> chain;
    int difficulty;

    Block createGenesisBlock();

public:
    Blockchain(int difficulty = 2);
    
    void addBlock(const std::string& data);
    bool isChainValid() const;
    void printChain() const;
    int getChainSize() const;
    Block getLatestBlock() const;
};

#endif
