#pragma once
#include "Auto.h"

class IDispatcher {
public:
    virtual void update(const Auto& autoObj) = 0;
};