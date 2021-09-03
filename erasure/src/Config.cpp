#include "Config.h"

Matrix get_matrix_from_file(const char* file_name) {
    ifstream ifs(file_name, ios::in);
    string line;
    vector<vector<string>> temp_matrix;
    while(getline(ifs, line)) {
        vector<string> temp;
        boost::split(temp, line, boost::is_any_of(","), boost::token_compress_on);
        temp_matrix.push_back(temp);
    }

    Matrix matrix(temp_matrix.size(), temp_matrix[0].size());
    for (int i = 0; i < temp_matrix.size(); ++i) {
        for (int j = 0; j < temp_matrix[0].size(); ++j) {
            if(temp_matrix[i][j] == "0") {
                matrix.setElement(i, j, 0);
            } else {
                matrix.setElement(i, j, 1);
            }
        }
    }

    return matrix;
}

Setting get_erasure_setting(const char* config_name, const char* matrix_path) {
    TiXmlDocument doc;
    if(!doc.LoadFile(config_name)) {
        cerr << doc.ErrorDesc() << endl;
        exit(1);
    }

    TiXmlElement* root = doc.FirstChildElement();
    if(root == NULL) {
        cerr << "Failed to load file: No root element." << endl;
        doc.Clear();
        exit(1);
    }

    // Get Data Num
    TiXmlElement* elem = root->FirstChildElement();
    int k = atoi(elem->GetText());

    // Get Parity Num
    elem = elem->NextSiblingElement();
    int m = atoi(elem->GetText());

    // Get w-bit
    elem = elem->NextSiblingElement();
    int w = atoi(elem->GetText());

    // Get Block Size
    elem = elem->NextSiblingElement();
    string temp = elem->GetText();
    int64_t size = atol(temp.substr(0, temp.length() - 1).c_str());
    if(temp[temp.length() - 1] == 'K') {
        size *= 1024UL;
    } else if(temp[temp.length() - 1] == 'M') {
        size *= (1024UL * 1024UL);
    } else if(temp[temp.length() - 1] == 'G') {
        size *= (1024UL * 1024UL * 1024UL);
    }

    // Get Matrix
    elem = elem->NextSiblingElement();
    string matrix_file = matrix_path;
    matrix_file += ("/" + (string)elem->GetText() + ".matrix");
    Matrix matrix = get_matrix_from_file(matrix_file.c_str());

    // Get Disk Path
    elem = elem->NextSiblingElement();
    TiXmlElement* sub_elem = elem->FirstChildElement();
    int disk_num = atoi(sub_elem->GetText());
    vector<string> disk_path_list(disk_num);
    for (int i = 0; i < disk_num; ++i) {
        sub_elem = sub_elem->NextSiblingElement();
        disk_path_list[i] = sub_elem->GetText();
    }

    return Setting(k, m, w, size, matrix, disk_path_list);
}