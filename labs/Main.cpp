#include "Complex.h"

int main() {
    setlocale(0, "rus");

    /* // Complex com1, com2; // Инициализация двух объектов используя конструктор по умолчанию

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
        s
    cout << endl << com1() << endl;

    testAll();*/
   
   const int h = 3;

   Complex test[h];
   for (int i = 0; i < h; i++) {
       cout << "Введите test" << i << endl;
       cin >> test[i];
       test[i].save();
       test[i].saveBinary();
       cout << endl;
   }
   
    
    Complex com[h];
    for (int i=0; i < h; i++) {
        com[i].load(i);
        cout << com[i];
    }
    
    cout << endl;

    Complex comB[h];
    for (int i = 0; i < h; i++) {
        comB[i].load(i);
        cout << comB[i];
    }


    cin.get();
    cin.get();
}