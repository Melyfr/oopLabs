#include "Complex.h"

int main() {
    setlocale(0, "rus");

     // Complex com1, com2; // Инициализация двух объектов используя конструктор по умолчанию

    Complex com1(5, 14); // Инициализация первого объекта используя конструктор с параметрами
    // Complex com2(32, 2); // Инициализация второго объекта используя конструктор с параметрами

    Complex com2(com1); // Инициализация второго объекта используя конструктор копирования

    Complex com3(5, 30); // Инициализация третьего объекта используя конструктор с параметрами

    com1 = com3; // Присваивание объекту com1 значений объекта com3
    
    cout << "Комплексное число A:" << endl << com1 << endl << "Комплексное число B:" << endl << com2 << endl << "Комплексное число C:" << endl << com3 << endl; // Вывод объектов при помощи перегруженной функции вывода
    
    cout << "A + B: " << endl << com1 + com2 << endl;
    cout << "A - B:" << endl << com1 - com2 << endl;
    cout << "A * B:" << endl << com1 * com2 << endl;
    cout << "A / B:" << endl << com1 / com2 << endl;

    if (com1 != com3)
        cout << "Числа не равны" << endl;
    else
        cout << "Числа равны" << endl;

    if (com1 == com3)
        cout << "Числа равны" << endl;
    else
        cout << "Числа не равны" << endl;

    if (com1 != com3) {
        
        if (com1 > com3)
            cout << "Com1 > Com3" << endl;
        else
            cout << "Com1 < Com3" << endl;
    }
    else 
        cout << "Числа равны" << endl;

    if (com1 != com3) {
        if (com1 < com3)
            cout << "Com1 < Com3" << endl;
        else
            cout << "Com1 > Com3" << endl;
    }
    else
        cout << "Числа равны" << endl;

    if (com1 >= com3)
        cout << "Com1 >= Com3" << endl;
    else
        cout << "Com1 <= Com3" << endl;
    
    if (com1 <= com3)
        cout << "Com1 <= Com3" << endl;
    else
        cout << "Com1 >= Com3" << endl;

    cout << endl << com1.toTrigonometricView() << endl;

    cin.get();
    cin.get();
}