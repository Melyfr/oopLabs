﻿#include "Complex.h"

int main() {
    setlocale(0, "rus");

     // Complex com1, com2; // Инициализация двух объектов используя конструктор по умолчанию

    Complex com1(5, 14); // Инициализация первого объекта используя конструктор с параметрами
    // Complex com2(32, 2); // Инициализация второго объекта используя конструктор с параметрами

    Complex com2(com1); // Инициализация второго объекта используя конструктор копирования

    
    cout << "Комплексное число A:" << endl << com1 << endl << "Комплексное число B:" << endl << com2 << endl; // Вывод объектов при помощи перегруженной функции вывода
    
    cout << "A + B:" << endl << com1 + com2 << endl;
    cout << "A - B:" << endl << com1 - com2 << endl;
    cout << "A * B:" << endl << com1 * com2 << endl;
    cout << "A / B:" << endl << com1 / com2 << endl;

    cin.get();
    cin.get();
}