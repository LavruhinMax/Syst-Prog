#pragma once
#include <vector>
#include "IDispatcher.h"

class Dispatcher {
private:
    vector<IDispatcher*> observers;
public:
    void addObserver(IDispatcher* observer) {
        observers.push_back(observer);
    }

    void removeObserver(IDispatcher* observer) {
    }

    void notify(const Auto& autoObj) {
        for (IDispatcher* observer : observers) {
            observer->update(autoObj);
        }
    }
};
