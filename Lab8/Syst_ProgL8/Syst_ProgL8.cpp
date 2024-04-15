#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
#include "Auto.h"
#include "AutoQueue.h"
using namespace std;


int main() {
    setlocale(LC_ALL, "Rus");
    AutoQueue queue;

    Auto auto1{"Toyota", "Corolla", 25000, 150 };
    Auto auto2{"Tesla", "Cybertruck", 40000, 300 };
    Auto auto3{"Nissan", "Murano", 50000, 350 };
    Auto auto4{"Renault", "Duster", 20000, 150 };
    Auto auto5{"Land Rover", "Discovery", 80000, 500 };

    cout << "1) Toyota Corolla\n";
    cout << "2) Tesla Cybertruck\n";
    cout << "3) Nissan Murano\n";
    cout << "4) Renault Duster\n";
    cout << "5) Land Rover Discovery\n";
    cout << "\n";

    queue.addToQueue(auto1);
    queue.addToQueue(auto2);
    queue.addToQueue(auto3);
    queue.addToQueue(auto4);
    queue.addToQueue(auto5);

    try {
        Auto firstAuto = queue.dequeue();
        cout << "Извлеченное из головы очереди авто: " << firstAuto.brand << " " << firstAuto.model << endl;
    }
    catch (const std::exception& e) {
        cout << "Исключение: " << e.what() << endl;
    }

    try {
        Auto autoAtPosition = queue.getElementAtPosition(3);
        cout << "Авто под номером 4: " << autoAtPosition.brand << " " << autoAtPosition.model << endl;
    }
    catch (const std::exception& e) {
        cout << "Исключение: " << e.what() << std::endl;
    }

    vector<int> positions = queue.findAutoByCriteria("Renault", "Duster");
    cout << "Номера авто с указанным свойством (Renault Duster):";
    for (int pos : positions) {
        cout << " " << pos;
    }
    cout << endl;

    vector<Auto> autosByPower = queue.getAutosByEnginePower(150);
    cout << "Авто с мощностью двигателя 150 лс:";
    for (const auto& autoData : autosByPower) {
        cout << " " << autoData.brand << " " << autoData.model;
    }
    cout << endl;

    system("pause");
    return 0;
}