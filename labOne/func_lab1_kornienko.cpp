#include <iostream> 
#include "lab1_kornienko.h"
using namespace std;

double Complex::getRe() {
    return (re);
} // ������ ��� ��������� ���������� "re"

double Complex::getIm() {
    return (im);
} // ������ ��� ��������� ���������� "im"

void Complex::setRe(double valueRe) {
    re = valueRe;
} // ������ ��� ��������� ���������� "re"

void Complex::setIm(double valueIm) {
    im = valueIm;
} // ������ ��� ��������� ���������� "im"

Complex Complex::operator * (Complex& com) {
    Complex result;
    double i, j;
    i = re * com.re - im * com.im;
    j = re * com.im + com.re * im;
    result.re = i;
    result.im = j;
    counter = counter - 2;
    return result;
} // ������������� ������� ��������� ����������� �����

Complex Complex::operator / (Complex& com) {
    Complex result;
    double i, j, k;
    k = com.re * com.re + com.im * com.im;
    i = (re * com.re + im * com.im) / k;
    j = (im * com.re - re * com.im) / k;
    result.re = i;
    result.im = j;
    counter = counter - 2;
    return result;
} // ������������� ������� ������� ����������� �����

Complex Complex::operator + (Complex& com) {
    Complex result;
    result.re = this->re + com.re;
    result.im = this->im + com.im;
    counter = counter - 2;
    return result;
} // ������������� ������� �������� ����������� �����

Complex Complex::operator - (Complex& com) {
    Complex result;
    result.re = this->re - com.re;
    result.im = this->im - com.im;
    counter = counter - 2;
    return result;
} // ������������� ������� ��������� ����������� �����

ostream& operator << (ostream& out, const Complex& com) {
    if (com.im < 0)
        out << com.re << " + i(" << com.im << ")\n";
    else
        out << com.re << " + i" << com.im << "\n";
    return out;
} // ������������� ������� ������ ����������� �����

istream& operator >> (istream& in, Complex& com) {
    cout << "������� �������������� ����� ������������ �����: ";
    in >> com.re;
    cout << "������� ��������� ������ ����� ������������ �����: ";
    in >> com.im;
    cout << endl;
    return in;
}  // ������������� ������� ����� ����������� �����

int Complex::counter = 0; // ������������� ������������ ����� ������ �������� ��������