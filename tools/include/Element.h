#ifndef SCHEDULING_ELEMENT_H
#define SCHEDULING_ELEMENT_H

#include <iostream>
#include <functional>
#include <algorithm>
#include <cstring>

using namespace std;

/**
 * Logical operation of binary elements
 */
class Element {
public:
    int w = 0;
    bool* bits = NULL;
    int one_num = 0;

    Element();
    Element(int w);
    Element(int w, string bits);
    Element(int w, bool* bits);
    Element(const Element &element);
    ~Element();

    int get_bit_length();
    int get_one_num();
    void set_bit(int i, int bit);
    int get_bit(int i);
    string print_bits();


    Element operator&(Element &e);
    Element operator|(Element &e);
    Element operator~();
    Element operator^(Element &e);
};

#endif
