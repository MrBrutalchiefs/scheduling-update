#include "Element.h"

Element::Element() {}

Element::Element(int w){
    this->w = w;
    this->bits = new bool[w];
    this->one_num = 0;
}

Element::Element(int w, string bits) {
    this->w = w;
    this->one_num = 0;
    this->bits = new bool[w];
    for (int i = 0; i < w; ++i) {
        if(bits[i] == '0') {
            this->bits[i] = 0;
        } else if(bits[i] == '1') {
            this->bits[i] = 1;
            this->one_num++;
        } else {
            throw "Bits Error!";
        }
    }
}

Element::Element(int w, bool* bits){
    this->w = w;
    this->one_num = 0;
    this->bits = new bool[w];
    for (int i = 0; i < w; ++i) {
        this->bits[i] = bits[i];
        if(bits[i] == 1) {
            this->one_num++;
        }
    }
}

Element::Element(const Element &element) {
    this->w = element.w;
    this->one_num = element.one_num;
    this->bits = new bool[this->w];
    memcpy(this->bits, element.bits, this->w * sizeof(bool));
}

Element::~Element() {
    if(this->bits != NULL) {
        delete [] this->bits;
        this->bits = NULL;
    }
}

int Element::get_bit_length() {
    return this->w;
}

int Element::get_one_num() {
    return this->one_num;
}

void Element::set_bit(int i, int bit) {
    this->bits[i] = (bool)bit;
}

int Element::get_bit(int i) {
    return this->bits[i];
}

string Element::print_bits() {
    string str="";
    for (int i = 0; i < this->w; ++i) {
        str += to_string(this->bits[i]);
    }
    return str;
}

Element Element::operator&(Element &e) {
    if(this->w != e.get_bit_length()) {
        throw "Inconsistent Bit Length!";
    }

    bool* result = new bool[this->w];
    transform(this->bits, this->bits + this->w, e.bits, result, bit_and<bool>());
    Element element(this->w, result);
    delete [] result;
    return element;
}

Element Element::operator|(Element &e) {
    if(this->w != e.get_bit_length()) {
        throw "Inconsistent Bit Length!";
    }

    bool* result = new bool[this->w];
    transform(this->bits, this->bits + this->w, e.bits, result, bit_or<bool>());
    Element element(this->w, result);
    delete [] result;
    return element;
}

Element Element::operator~() {
    bool* result = new bool[this->w];
    for (int i = 0; i < this->w; ++i) {
        if(this->bits[i] == 1) {
            result[i] = 0;
        } else {
            result[i] = 1;
        }
    }
    Element element(this->w, result);
    delete [] result;
    return element;
}

Element Element::operator^(Element &e) {
    if(this->w != e.get_bit_length()) {
        throw "Inconsistent Bit Length!";
    }

    bool* result = new bool[this->w];
    transform(this->bits, this->bits + this->w, e.bits, result, bit_xor<bool>());
    Element element(this->w, result);
    delete [] result;
    return element;
}