#include "Blockchain.h"
#include <iostream>

Blockchain::Blockchain(int difficulty) {
    this->difficulty = difficulty;
    chain.push_back(createGenesisBlock());
}

Block Blockchain::createGenesisBlock() {
    return Block(0, "Genesis Block", "0");
}

void Blockchain::addBlock(const std::string& data) {
    Block latestBlock = getLatestBlock();
    Block newBlock(latestBlock.getIndex() + 1, data, latestBlock.getHash());
    
    std::cout << "Mining block " << newBlock.getIndex() << "..." << std::endl;
    newBlock.mineBlock(difficulty);
    
    chain.push_back(newBlock);
}

Block Blockchain::getLatestBlock() const {
    return chain.back();
}

bool Blockchain::isChainValid() const {
    for(size_t i = 1; i < chain.size(); i++) {
        const Block& currentBlock = chain[i];
        const Block& previousBlock = chain[i - 1];
        
        Block tempBlock = currentBlock;
        if(currentBlock.getHash() != tempBlock.getHash()) {
            std::cout << "Invalid hash at block " << i << std::endl;
            return false;
        }
        
        if(currentBlock.getPreviousHash() != previousBlock.getHash()) {
            std::cout << "Invalid previous hash at block " << i << std::endl;
            return false;
        }
        
        std::string target(difficulty, '0');
        if(currentBlock.getHash().substr(0, difficulty) != target) {
            std::cout << "Block " << i << " doesn't meet difficulty requirement" << std::endl;
            return false;
        }
    }
    
    return true;
}

void Blockchain::printChain() const {   
    for(size_t i = 0; i < chain.size(); i++) {
        const Block& block = chain[i];
        std::cout << "Block #" << block.getIndex() << std::endl;
        std::cout << "Timestamp: " << block.getTimestamp() << std::endl;
        std::cout << "Data: " << block.getData() << std::endl;
        std::cout << "Previous Hash: " << block.getPreviousHash() << std::endl;
        std::cout << "Hash: " << block.getHash() << std::endl;
        std::cout << "Nonce: " << block.getNonce() << std::endl;
        std::cout << "--------------------------------" << std::endl;
    }
    
    std::cout << "\nChain is " << (isChainValid() ? "VALID" : "INVALID") << "\n" << std::endl;
}

int Blockchain::getChainSize() const {
    return chain.size();
}
