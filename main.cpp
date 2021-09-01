#include <iostream>
#include "tsl/robin_map.h"

using namespace tsl;
using namespace std;

int main(int argc, char** argv) {
    robin_map<int, string> map_test;
    map_test[0] = "AAA";
    map_test[1] = "BBB";
    map_test[2] = "CCC";

    cout << map_test[0] << map_test[1] << map_test[2] << endl;
}
