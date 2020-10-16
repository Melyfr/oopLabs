#include <iostream> 
#include "lab1_kornienko.h"
using namespace std;

complex complex::operator * (complex& com) {
    complex result;
    double i, j;
    i = re * com.re - im * com.im;
    j = re * com.im + com.re * im;
    result.re = i;
    result.im = j;
    return result;
} // Перегруженная функция умножения комплексных чисел

complex complex::operator / (complex& com) {
    complex result;
    double i, j, k;
    k = com.re * com.re + com.im * com.im;
    i = (re * com.re + im * com.im) / k;
    j = (im * com.re - re * com.im) / k;
    result.re = i;
    result.im = j;
    return result;
} // Перегруженная функция деления комплексных чисел

complex complex::operator + (complex com) {
    complex result;
    result.re = this->re + com.re;
    result.im = this->im + com.im;
    return result;
} // Перегруженная функция сложения комплексных чисел

complex complex::operator - (complex com) {
    complex result;
    result.re = this->re - com.re;
    result.im = this->im - com.im;
    return result;
} // Перегруженная функция вычитания комплексных чисел

ostream& operator << (ostream& out, const complex& com) {
    if (com.im < 0)
        out << com.re << " + i(" << com.im << ")\n";
    else
        out << com.re << " + i" << com.im << "\n";
    return out;
} // Перегруженная функция вывода комплексных чисел

istream& operator >> (istream& in, complex& com) {
    cout << "Введите действительную часть комплексного числа: ";
    in >> com.re;
    cout << "Введите множитель мнимой части комплексного числа: ";
    in >> com.im;
    cout << endl;
    return in;
}  // Перегруженная функция ввода комплексных чисел

int main() {
    setlocale(0, "rus");
    complex com1, com2; // Создание двух объектов хранящих в себе комплесные числа для проверки функций
    cin >> com1 >> com2; // Задания значений в объекты при помощи перегруженной функции ввода
    cout << endl << "Комплексное число A:" << endl << com1 << endl << "Комплексное число B:" << endl << com2 << endl; // Вывод объектов при помощи перегруженной функции вывода
    
    cout << "A + B: " << endl << com1 + com2 << endl;
    cout << "A - B:" << endl << com1 - com2 << endl;
    cout << "A * B:" << endl << com1 * com2 << endl;
    cout << "A / B:" << endl << com1 / com2 << endl;

    cout << endl;

    cin.get();
    cin.get();
}