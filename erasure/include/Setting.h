#ifndef SCHEDULING_SETTING_H
#define SCHEDULING_SETTING_H

#include <iostream>
#include <vector>

#include "Matrix.h"

using namespace std;

/**
 * Erasure code configuration parameters
 */
class Setting {
public:
    int k;
    int m;
    int w;
    int64_t block_size;
    vector<string> storage_path;
    Matrix matrix;

    Setting();
    Setting(int k, int m, int w, int64_t block_size, Matrix &matrix, vector<string> storage_path);
};

#endif
