#pragma once
#include "Auto.h"

class BinaryTree {
private:
    Auto* root;

    Auto* addAuto(Auto* root, string brand, string model) {
        if (root == nullptr) {
            return new Auto(brand, model);
        }
        if (brand < root->brand) {
            root->left = addAuto(root->left, brand, model);
        }
        else if (brand > root->brand) {
            root->right = addAuto(root->right, brand, model);
        }
        else {
            throw invalid_argument("Автомобиль уже существует\n");
        }
        return root;
    }

    Auto* removeAuto(Auto* root, string brand, string model) {
        if (root == nullptr) {
            return root;
        }
        if (brand < root->brand) {
            root->left = removeAuto(root->left, brand, model);
        }
        else if (brand > root->brand) {
            root->right = removeAuto(root->right, brand, model);
        }
        else {
            if (root->left == nullptr) {
                Auto* temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == nullptr) {
                Auto* temp = root->left;
                delete root;
                return temp;
            }
            else {
                Auto* temp = getMinValueNode(root->right);
                root->brand = temp->brand;
                root->model = temp->model;
                root->right = removeAuto(root->right, temp->brand, temp->model);
            }
        }

        return root;
    }

    Auto* getMinValueNode(Auto* node) {
        Auto* current = node;
        while (current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    Auto* findAuto(Auto* root, string brand, string model) {
        if (root == nullptr || (root->brand == brand && root->model == model)) {
            return root;
        }

        if (brand < root->brand && model < root->model) {
            return findAuto(root->left, brand, model);
        }

        return findAuto(root->right, brand, model);
    }

public:
    BinaryTree() {
        root = nullptr;
    }

    void addAuto(string brand, string model) {
        root = addAuto(root, brand, model);
    }

    void removeAuto(string brand, string model) {
        root = removeAuto(root, brand, model);
    }

    bool findAuto(string brand, string model) {
        return findAuto(root, brand, model) != nullptr;
    }
};