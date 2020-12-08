#pragma once
#define _CRT_SECURE_NO_WARNINGS 
#include <iostream> 
#include <assert.h>
#include <cmath> 
#include <fstream>
#include <stdio.h>
#include "Test.h" 
using namespace std;

class Complex {
public:
    Complex (); // Объявление конструктора по умолчанию
    Complex (double valueRe, double valueIm); // Объявление конструктора с параметрами
    Complex (const Complex& com);// Объявление конструктора копирования
    ~Complex();

    friend Complex operator + (Complex& com1, Complex& com2); // Объявление перегруженной функции сложения комплексных чисел
    Complex operator - (Complex& com); // Объявление перегруженной функции вычитания комплексных чисел
    Complex operator * (Complex& com); // Объявление перегруженной функции умножения комплексных чисел
    Complex operator / (Complex& com); // Объявление перегруженной функции деления комплексных чисел
    
    char* operator() ();

    Complex operator = (const Complex& com); // Объявление перегруженной функции присваивания комплексных чисел

    bool operator == (Complex& com); // Объявление перегруженного оператора == для комплексных чисел
    bool operator != (Complex& com); // Объявление перегруженного оператора != для комплексных чисел
    bool operator > (Complex& com); // Объявление перегруженного оператора > для комплексных чисел
    bool operator >= (Complex& com); // Объявление перегруженного оператора >= для комплексных чисел
    bool operator < (Complex& com); // Объявление перегруженного оператора < для комплексных чисел
    bool operator <= (Complex& com); // Объявление перегруженного оператора <= для комплексных чисел

    friend double module (Complex& com); // Объявление метода подсчета модуля комплексного числа для сравнения

    friend ostream& operator << (ostream& out, const Complex& com); // Объявление перегруженной функции вывода комплексных чисел
    friend istream& operator >> (istream& in, Complex& com); // Объявление перегруженной функции ввода комплексных чисел

    friend ofstream& operator << (ofstream& out, const Complex& com);

    double getRe (); // Объявление геттера для приватной переменной "re"
    double getIm ();  // Объявление геттера для приватной переменной "im"
    void setRe (double valueRe); // Объявление сеттера для приватной переменной "re"
    void setIm (double valueIm); // Объявление сеттера для приватной переменной "im"

    static int counter; // Объявление статического члена класса подсчета объектов

    void saveBinary(ofstream& save);
    void loadBinary(ifstream& load);

private:
    double re, im; // Переменные содержащие действительную и мнимую части комплексного числа

}; // Объявление класса для работы с комплексными числами

