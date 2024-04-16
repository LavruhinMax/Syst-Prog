#pragma once
#include<string>
#include<iostream>

struct Auto {
    string brand;
    string model;
    Auto* left;
    Auto* right;

    Auto(string brand, string model) {
        this->brand = brand;
        this->model = model;
        this->left = nullptr;
        this->right = nullptr;
        cout << brand << " " << model << endl;
    }
};