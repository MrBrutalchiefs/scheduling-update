#include "Block.h"

BlockInfo::BlockInfo() {}

BlockInfo::BlockInfo(int id, int blockType, int state, const string &element, int64_t size, int64_t offset, string path) {
    this->id = id;
    this->block_type = blockType;
    this->state = state;
    this->element = element;
    this->size = size;
    this->offset = offset;
    this->path = path;
}

Block::Block(BlockInfo &info) {
    this->info = info;
    this->data = new char[info.size];
}

Block::Block(BlockInfo &info, char* data) {
    this->info = info;
    this->data = new char[info.size];
    memcpy(this->data, data, sizeof(data));
}

Block::~Block() {
    if(this->data != NULL) {
        delete [] this->data;
        this->data = NULL;
    }
}