#pragma once
#include "Auto.h"
#include <iostream>
#include <vector>

class AutoQueue
{
private:
    struct autoNode {
        Auto data;
        autoNode* next;
    };
    autoNode* head;
    autoNode* tail;

public:
    AutoQueue() : head(nullptr), tail(nullptr) {}

    void addToQueue(const Auto& newAuto) {
        autoNode* newNode = new autoNode{ newAuto, nullptr };
        if (tail == nullptr) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    Auto dequeue() {
        if (head == nullptr) {
            throw out_of_range("Очередь пуста");
        }
        Auto data = head->data;
        autoNode* temp = head;
        head = head->next;
        if (head == nullptr) {
            tail = nullptr;
        }
        delete temp;
        return data;
    }

    Auto getElementAtPosition(int position) {
        if (position < 0) {
            throw out_of_range("Номер не может быть отрицательным");
        }
        autoNode* current = head;
        int currentPosition = 0;
        while (current != nullptr) {
            if (currentPosition == position) {
                return current->data;
            }
            current = current->next;
            currentPosition++;
        }
        throw out_of_range("Номер превышает длину очереди");
    }

    vector<int> findAutoByCriteria(const std::string& brand, const std::string& model) {
        vector<int> positions;
        autoNode* current = head;
        int currentPosition = 0;
        while (current != nullptr) {
            if (current->data.brand == brand && current->data.model == model) {
                positions.push_back(currentPosition);
            }
            current = current->next;
            currentPosition++;
        }
        if (positions.empty()) {
            positions.push_back(-1);
        }
        return positions;
    }

    vector<Auto> getAutosByEnginePower(int power) {
        vector<Auto> autos;
        autoNode* current = head;
        while (current != nullptr) {
            if (current->data.enginePower == power) {
                autos.push_back(current->data);
            }
            current = current->next;
        }
        return autos;
    }
};