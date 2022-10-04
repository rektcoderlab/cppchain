# Simple C++ Blockchain

## Requirements

- C++ compiler with C++11 support (g++, clang++, or MSVC)
- CMake 3.10 or higher
- OpenSSL library

### Installing OpenSSL

**macOS:**
```bash
brew install openssl
```

**Ubuntu/Debian:**
```bash
sudo apt-get install libssl-dev
```

**Windows:**
- Download and install OpenSSL from https://slproweb.com/products/Win32OpenSSL.html
- Or use vcpkg: `vcpkg install openssl`

## Building the Project

1. Create a build directory:
```bash
mkdir build
cd build
```

2. Generate build files with CMake:
```bash
cmake ..
```

3. Build the project:
```bash
cmake --build .
```

## Running the Blockchain

After building, run the executable:

```bash
./blockchain
```

## How It Works

### Block Class
Each block contains:
- **Index**: Position in the blockchain
- **Timestamp**: When the block was created
- **Data**: Transaction or information stored in the block
- **Previous Hash**: Hash of the previous block (linking blocks together)
- **Hash**: Current block's hash (calculated from index, timestamp, data, previous hash, and nonce)
- **Nonce**: Number used in proof-of-work mining

### Blockchain Class
Manages the chain of blocks with:
- **Genesis Block**: The first block in the chain
- **Add Block**: Mines and adds new blocks to the chain
- **Validation**: Checks if the chain is valid by verifying:
  - Each block's hash is correct
  - Each block properly links to the previous block
  - Each block meets the difficulty requirement

### Proof of Work (Mining)
Mining involves finding a nonce value that produces a hash starting with a specific number of zeros (difficulty). The higher the difficulty, the longer it takes to mine a block.

Example with difficulty 3:
- Hash must start with "000..."
- Requires trying many nonce values until a valid hash is found

## Example Output

```
========================================
   Simple C++ Blockchain Demo
========================================

Creating blockchain with difficulty: 3

--- Adding Block 1 ---
Mining block 1...
Block mined: 000a1b2c3d... (nonce: 12345)

--- Adding Block 2 ---
Mining block 2...
Block mined: 000f5e4d3c... (nonce: 67890)

========== Blockchain ==========

Block #0
Timestamp: 1234567890
Data: Genesis Block
Previous Hash: 0
Hash: 5f4dcc3b5aa765d61d8327deb882cf99...
Nonce: 0
--------------------------------

... (more blocks)

Chain is VALID

========================================
Validating blockchain...
✓ Blockchain is VALID!
========================================

Total blocks in chain: 4
```

## License

This project is open source and available under the MIT License.