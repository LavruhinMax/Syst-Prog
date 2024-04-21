#include <iostream>
#include <string>
#include <vector>
#include "Auto.h"
#include "IDispatcher.h"
#include "Dispatcher.h"
#include "Taxi.h"
using namespace std;



int main() {
    setlocale(LC_ALL, "Rus");
    Dispatcher dispatcher;
    Taxi taxi1("№ 072");
    Taxi taxi2("№ 018");

    dispatcher.addObserver(&taxi1);
    dispatcher.addObserver(&taxi2);

    Auto auto1("Nissan Almera");
    Auto auto2("Volkswagen Polo");
    Auto auto3("Dacia Logan");

    dispatcher.notify(auto1);
    dispatcher.notify(auto2);
    dispatcher.notify(auto3);

    return 0;
}