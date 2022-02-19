#pragma once
#include <vector>
#include "driver.h"
using namespace std;

class Decoder {
    vector<int> pins;
public:
    Decoder (vector<int> _pins);
    ~Decoder ();
    void decode (int pin_index);
}