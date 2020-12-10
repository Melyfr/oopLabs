#pragma once
#define _CRT_SECURE_NO_WARNINGS 
#include <iostream> 
#include <assert.h>
#include <cmath> 
#include <fstream>
#include <stdio.h>
#include <ctime>
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

protected:
    double re, im; // Переменные содержащие действительную и мнимую части комплексного числа

}; // Объявление класса для работы с комплексными числами

class ComplexString : public Complex {
public:
    ComplexString() : Complex() {
        trigonometricView = new char[2];
	    printf(trigonometricView, " ");
    }

    ComplexString(double valueRe, double valueIm) : Complex(valueRe, valueIm) {
        trigonometricView = new char[2];
        strcpy(trigonometricView, " ");
    }

    ComplexString(const ComplexString& com) : Complex(com) {
        trigonometricView = new char[strlen(com.trigonometricView) + 1];
        strcpy(trigonometricView, com.trigonometricView);
    }

    ~ComplexString();

    char* getTrigonometricView();
    void setTrigonometricView(char* valueStr);

    void toTrigonometricView();
    char* operator() ();

private:
    char* trigonometricView;
};

class ComplexDate : public Complex {
public:
    ComplexDate() : Complex() {
        now = time(0);
        date = localtime(&now);
    }

    ComplexDate(double valueRe, double valueIm) : Complex(valueRe, valueIm) {
        now = time(0);
        date = localtime(&now);
    }

    ComplexDate(const ComplexString& com) : Complex(com) {
        now = time(0);
        date = localtime(&now);
    }

    ~ComplexDate();

    int getYear();
    int getMonth();
    int getDay();
    char* getDate();

private:
    tm* date;
    time_t now;
};

