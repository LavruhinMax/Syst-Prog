#pragma once
#include "IDispatcher.h"
#include <iostream>
using namespace std;

class Taxi : public IDispatcher {
private:
    string name;
public:
    Taxi(const string& name) : name(name) {}

    void update(const Auto& autoObj) override {
        cout << "����� " << name << " �������� ��������� �� ���������� " << autoObj.getName() << endl;
    }
};