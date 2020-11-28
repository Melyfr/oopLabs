#pragma once

class Complex {
public:
    Complex() {
        re = 0;
        im = 0;
        counter++;
    } // Конструктор по умолчанию

    Complex(double valueRe, double valueIm) {
        re = valueRe;
        im = valueIm;
        counter++;
    } // Конструктор с параметрами

    Complex(const Complex& com) {
        re = com.re;
        im = com.im;
        counter++;
    } // Конструктор копирования

    Complex operator + (Complex&); // Объявление перегруженной функции сложения комплексных чисел
    Complex operator - (Complex&); // Объявление перегруженной функции вычитания комплексных чисел
    Complex operator * (Complex&); // Объявление перегруженной функции умножения комплексных чисел
    Complex operator / (Complex&); // Объявление перегруженной функции деления комплексных чисел
    friend std::istream& operator >>(std::istream&, Complex&); // Объявление перегруженной функции ввода комплексных чисел
    friend std::ostream& operator << (std::ostream&, const Complex&); // Объявление перегруженной функции вывода комплексных чисел
    static int counter; // Объявление статического члена класса подсчета объектов
    double getRe(); // Объявление геттера для приватной переменной "re"
    double getIm();  // Объявление геттера для приватной переменной "im"
    void setRe(double valueRe); // Объявление сеттера для приватной переменной "re"
    void setIm(double valueIm); // Объявление сеттера для приватной переменной "im"

private:
    double re, im; // Переменные содержащие действительную и мнимую части комплексного числа

}; // Объявление класса для работы с комплексными числами

