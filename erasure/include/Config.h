#ifndef SCHEDULING_CONFIG_H
#define SCHEDULING_CONFIG_H

#include<boost/algorithm/string.hpp>
#include<iostream>
#include<fstream>
#include<vector>

#include "Setting.h"
#include "tinyxml.h"

using namespace std;

Matrix get_matrix_from_file(const char* file_name);

Setting get_erasure_setting(const char* config_name, const char* file_name);

#endif
