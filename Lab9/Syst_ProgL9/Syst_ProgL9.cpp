#include <iostream>
#include <string>
using namespace std;
#include "BinaryTree.h"

int main()
{
    setlocale(LC_ALL, "Rus");
    BinaryTree tree;


    tree.addAuto("Toyota", "Corolla");
    tree.addAuto("Honda", "CR-V");
    tree.addAuto("Volkswagen", "Passat");
    tree.addAuto("Renault", "Koleos");
    tree.addAuto("Volvo", "X60");

    cout << "\n1: Добавление авто\n";
    cout << "2: Поиск авто\n";
    cout << "3: Удаление авто\n";

    cout << endl;
    string Brand = ""; string Model;
    int choice; cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "Введите марку авто: ";
        cin >> Brand;
        cout << "Введите модель авто: ";
        cin >> Model;
        tree.addAuto(Brand, Model);
        cout << "Добавлено\n";
        break;

    case 2:
        cout << "Введите марку авто: ";
        cin >> Brand;
        cout << "Введите модель авто: ";
        cin >> Model;
        if(tree.findAuto(Brand, Model)) cout << "Есть\n"; else cout << "Нет\n";
        break;

    case 3:
        cout << "Введите марку авто: ";
        cin >> Brand;
        cout << "Введите модель авто: ";
        cin >> Model;
        tree.removeAuto(Brand, Model); cout << Brand << " " << Model << " удален\n";
        break;

    default: "Неверный ввод";
    }

    system("pause");
    return 0;
}
