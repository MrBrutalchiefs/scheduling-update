#ifndef SCHEDULING_BLOCK_H
#define SCHEDULING_BLOCK_H

#include <iostream>
#include <cstring>

using namespace std;

/**
 * Block Information Object
 * block type: 0-data, 1-parity
 * state: 0-old data, 1-new data
 */
class BlockInfo {
public:
    int id;
    int block_type;
    int state;
    string element;
    int64_t size;
    int64_t offset;
    string path;

    BlockInfo();
    BlockInfo(int id, int blockType, int state, const string &element, int64_t size, int64_t offset, string path);
};

class Block {
public:
    BlockInfo info;
    char* data = NULL;

    Block(BlockInfo &info);
    Block(BlockInfo &info, char* data);
    ~Block();
};

#endif
