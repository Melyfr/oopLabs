#pragma once
#define _CRT_SECURE_NO_WARNINGS 
#include <iostream> 
#include <assert.h>
#include <cmath> 
#include "Test.h" 
using namespace std;

class Complex {
public:
    Complex (); // Объявление конструктора по умолчанию
    Complex (double valueRe, double valueIm); // Объявление конструктора с параметрами
    Complex (const Complex& com);// Объявление конструктора копирования

    friend Complex operator + (Complex&, Complex&); // Объявление перегруженной функции сложения комплексных чисел
    Complex operator - (Complex&); // Объявление перегруженной функции вычитания комплексных чисел
    Complex operator * (Complex&); // Объявление перегруженной функции умножения комплексных чисел
    Complex operator / (Complex&); // Объявление перегруженной функции деления комплексных чисел
    
    char* operator() ();

    Complex operator = (const Complex&); // Объявление перегруженной функции присваивания комплексных чисел

    bool operator == (Complex&); // Объявление перегруженного оператора == для комплексных чисел
    bool operator != (Complex&); // Объявление перегруженного оператора != для комплексных чисел
    bool operator > (Complex&); // Объявление перегруженного оператора > для комплексных чисел
    bool operator >= (Complex&); // Объявление перегруженного оператора >= для комплексных чисел
    bool operator < (Complex&); // Объявление перегруженного оператора < для комплексных чисел
    bool operator <= (Complex&); // Объявление перегруженного оператора <= для комплексных чисел

    friend double module (Complex&); // Объявление метода подсчета модуля комплексного числа для сравнения

    friend std::ostream& operator << (std::ostream&, const Complex&); // Объявление перегруженной функции вывода комплексных чисел

    double getRe (); // Объявление геттера для приватной переменной "re"
    double getIm ();  // Объявление геттера для приватной переменной "im"
    void setRe (double valueRe); // Объявление сеттера для приватной переменной "re"
    void setIm (double valueIm); // Объявление сеттера для приватной переменной "im"

    static int counter; // Объявление статического члена класса подсчета объектов

private:
    double re, im; // Переменные содержащие действительную и мнимую части комплексного числа

}; // Объявление класса для работы с комплексными числами

