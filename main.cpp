#include <iostream>
#include "Blockchain.h"

int main() {
    std::cout << "   Simple C++ Blockchain" << std::endl;
    
    std::cout << "Creating blockchain with difficulty: 3\n" << std::endl;
    Blockchain myBlockchain(3);
    
    std::cout << "\n--- Adding Block 1 ---" << std::endl;
    myBlockchain.addBlock("First transaction: Alice sends 10 BTC to Bob");
    
    std::cout << "\n--- Adding Block 2 ---" << std::endl;
    myBlockchain.addBlock("Second transaction: Bob sends 5 BTC to Charlie");
    
    std::cout << "\n--- Adding Block 3 ---" << std::endl;
    myBlockchain.addBlock("Third transaction: Charlie sends 2 BTC to Alice");
    
    myBlockchain.printChain();
    
    std::cout << "Validating blockchain..." << std::endl;
    if(myBlockchain.isChainValid()) {
        std::cout << "Blockchain is VALID!" << std::endl;
    } else {
        std::cout << "Blockchain is INVALID!" << std::endl;
    }    
    std::cout << "Total blocks in chain: " << myBlockchain.getChainSize() << std::endl;
    
    return 0;
}
