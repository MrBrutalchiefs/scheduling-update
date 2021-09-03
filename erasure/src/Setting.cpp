#include "Setting.h"

Setting::Setting() {}

Setting::Setting(int k, int m, int w, int64_t block_size, Matrix &matrix, vector<string> storage_path) {
    this->k = k;
    this->m = m;
    this->w = w;
    this->block_size = block_size;
    this->matrix = matrix;
    this->storage_path = storage_path;
}