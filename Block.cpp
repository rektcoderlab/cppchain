#include "Block.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <openssl/sha.h>

Block::Block(int idx, const std::string& data, const std::string& prevHash) {
    this->index = idx;
    this->data = data;
    this->previousHash = prevHash;
    this->timestamp = time(nullptr);
    this->nonce = 0;
    this->hash = calculateHash();
}

std::string Block::calculateHash() const {
    std::stringstream ss;
    ss << index << timestamp << data << previousHash << nonce;
    std::string input = ss.str();
    
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256((unsigned char*)input.c_str(), input.length(), hash);
    
    std::stringstream hashString;
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        hashString << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    }
    
    return hashString.str();
}

void Block::mineBlock(int difficulty) {
    std::string target(difficulty, '0');
    
    while(hash.substr(0, difficulty) != target) {
        nonce++;
        hash = calculateHash();
    }
    
    std::cout << "Block mined: " << hash << " (nonce: " << nonce << ")" << std::endl;
}

std::string Block::getHash() const {
    return hash;
}

std::string Block::getPreviousHash() const {
    return previousHash;
}

int Block::getIndex() const {
    return index;
}

std::string Block::getData() const {
    return data;
}

time_t Block::getTimestamp() const {
    return timestamp;
}

int Block::getNonce() const {
    return nonce;
}
