#ifndef BLOCK_H
#define BLOCK_H

#include <string>
#include <ctime>

class Block {
private:
    int index;
    std::string data;
    std::string previousHash;
    std::string hash;
    time_t timestamp;
    int nonce;

    std::string calculateHash() const;

public:
    Block(int idx, const std::string& data, const std::string& prevHash);
    
    void mineBlock(int difficulty);
    std::string getHash() const;
    std::string getPreviousHash() const;
    int getIndex() const;
    std::string getData() const;
    time_t getTimestamp() const;
    int getNonce() const;
};

#endif
