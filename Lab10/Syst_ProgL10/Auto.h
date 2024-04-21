#pragma once
#include <string>
using namespace std;

class Auto {
private:
    string model;
public:
    Auto(const string& model) : model(model) {}

    const string& getName() const {
        return model;
    }
};