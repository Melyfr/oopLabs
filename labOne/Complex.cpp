#include "Complex.h"

Complex::Complex () {
    re = 0;
    im = 0;
    counter++;
} // Конструктор по умолчанию

Complex::Complex (double valueRe, double valueIm) {
    re = valueRe;
    im = valueIm;
    counter++;
} // Конструктор с параметрами

Complex::Complex (const Complex& com) {
    re = com.re;
    im = com.im;
    counter++;
} // Конструктор копирования

double Complex::getRe() {
    return (re);
} // Геттер для приватной переменной "re"

double Complex::getIm() {
    return (im);
} // Геттер для приватной переменной "im"

void Complex::setRe(double valueRe) {
    re = valueRe;
} // Сеттер для приватной переменной "re"

void Complex::setIm(double valueIm) {
    im = valueIm;
} // Сеттер для приватной переменной "im"

Complex Complex::operator * (Complex& com) {
    Complex result;
    double i, j;
    i = re * com.re - im * com.im;
    j = re * com.im + com.re * im;
    result.re = i;
    result.im = j;
    counter = counter - 2;
    return result;
} // Перегруженная функция умножения комплексных чисел

Complex Complex::operator / (Complex& com) {
    Complex result;
    if (com.re != 0 || com.im != 0) {
        double i, j, k;
        k = com.re * com.re + com.im * com.im;
        i = (re * com.re + im * com.im) / k;
        j = (im * com.re - re * com.im) / k;
        result.re = i;
        result.im = j;
        counter = counter - 2;
        return result;
    }
    else {
        result.re = 0;
        result.im = 0;
        return result;
    }
} // Перегруженная функция деления комплексных чисел

Complex Complex::operator + (Complex& com) {
    Complex result;
    result.re = this->re + com.re;
    result.im = this->im + com.im;
    counter = counter - 2;
    return result;
} // Перегруженная функция сложения комплексных чисел

Complex Complex::operator - (Complex& com) {
    Complex result;
    result.re = this->re - com.re;
    result.im = this->im - com.im;
    counter = counter - 2;
    return result;
} // Перегруженная функция вычитания комплексных чисел

ostream& operator << (ostream& out, const Complex& com) {
    if (com.im < 0)
        out << com.re << " + i(" << com.im << ")\n";
    else
        out << com.re << " + i" << com.im << "\n";
    return out;
} // Перегруженная функция вывода комплексных чисел

istream& operator >> (istream& in, Complex& com) {
    cout << "Введите действительную часть комплексного числа: ";
    in >> com.re;
    cout << "Введите множитель мнимой части комплексного числа: ";
    in >> com.im;
    cout << endl;
    return in;
}  // Перегруженная функция ввода комплексных чисел

bool Complex::operator == (Complex& com) {
    return (this->re == com.re && this->im == com.im);
} // Перегруженная функция равенства комплексных чисел

int Complex::counter = 0; // Инициализация статического члена класса подсчета объектов