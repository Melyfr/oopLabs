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

Complex::~Complex() {

}

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

Complex operator + (Complex& com1, Complex& com2) {
    Complex result;
    result.re = com1.re + com2.re;
    result.im = com1.im + com2.im;
    return result;
} // Перегруженная функция сложения комплексных чисел

Complex Complex::operator - (Complex& com) {
    Complex result;
    result.re = this->re - com.re;
    result.im = this->im - com.im;
    counter = counter - 2;
    return result;
} // Перегруженная функция вычитания комплексных чисел

Complex Complex::operator = ( const Complex& com) {
    re = com.re;
    im = com.im;
    return *this;
} // Перегруженная функция присваивания комплексных чисел

ostream& operator << (ostream& out, const Complex& com) {
    out << com.re << " + i(" << com.im << ")\n";
    return out;
} // Перегруженная функция вывода комплексных чисел

istream& operator >> (istream& in, Complex& com) {
    in >> com.re;
    in >> com.im;
    return in;
} // Перегруженная функция ввода комплексных чисел

ofstream& operator << (ofstream& out, const Complex& com) {
    out << com.re << " " << com.im << endl;
    return out;
} // Перегруженная функция вывода комплексных чисел


double module(Complex& com) {
    double module = sqrt(pow(com.re, 2) + pow(com.im, 2));
    return (module);
}

bool Complex::operator > (Complex& com) {
    return(module(*this) > module(com));
}

bool Complex::operator >= (Complex& com) {
    return(module(*this) >= module(com));
}

bool Complex::operator < (Complex& com) {
    return(module(*this) < module(com));
}

bool Complex::operator <= (Complex& com) {
    return(module(*this) <= module(com));
}

bool Complex::operator == (Complex& com) {
    return (this->re == com.re && this->im == com.im);
} // Перегруженная функция равенства комплексных чисел

bool Complex::operator != (Complex& com) {
    return (this->re != com.re || this->im != com.im);
}

char* Complex::operator()() {
    if (module(*this) != 0) {
    char* trigonometricView = new char [28 + sizeof(module(*this)) + sizeof(atan(im / re))*2];
    sprintf(trigonometricView, "%f * (cos %f + i * sin %f)", module(*this), atan(im / re), atan(im / re));
    return (trigonometricView);
    }
    else {
        char* trigonometricView = new char[63];
        strcpy(trigonometricView, "Триганометрический вид: 0, т.к. модуль комплексного числа = 0");
        return (trigonometricView);
    }
}

void Complex::saveBinary(ofstream& save) {
    if (save.is_open()) {
        save.write((char*)this, sizeof(*this));
    }
}

void Complex::loadBinary(ifstream& load) {
    if (load.is_open()) {
        load.read((char*)this, sizeof(*this));
    }
}


int Complex::counter = 0; // Инициализация статического члена класса подсчета объектов