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
} // ������������� ������� ��������� ����������� �����

complex complex::operator / (complex& com) {
    complex result;
    double i, j, k;
    k = com.re * com.re + com.im * com.im;
    i = (re * com.re + im * com.im) / k;
    j = (im * com.re - re * com.im) / k;
    result.re = i;
    result.im = j;
    return result;
} // ������������� ������� ������� ����������� �����

complex complex::operator + (complex com) {
    complex result;
    result.re = this->re + com.re;
    result.im = this->im + com.im;
    return result;
} // ������������� ������� �������� ����������� �����

complex complex::operator - (complex com) {
    complex result;
    result.re = this->re - com.re;
    result.im = this->im - com.im;
    return result;
} // ������������� ������� ��������� ����������� �����

ostream& operator << (ostream& out, const complex& com) {
    if (com.im < 0)
        out << com.re << " + i(" << com.im << ")\n";
    else
        out << com.re << " + i" << com.im << "\n";
    return out;
} // ������������� ������� ������ ����������� �����

istream& operator >> (istream& in, complex& com) {
    cout << "������� �������������� ����� ������������ �����: ";
    in >> com.re;
    cout << "������� ��������� ������ ����� ������������ �����: ";
    in >> com.im;
    cout << endl;
    return in;
}  // ������������� ������� ����� ����������� �����

int main() {
    setlocale(0, "rus");
    complex com1, com2; // �������� ���� �������� �������� � ���� ���������� ����� ��� �������� �������
    cin >> com1 >> com2; // ������� �������� � ������� ��� ������ ������������� ������� �����
    cout << endl << "����������� ����� A:" << endl << com1 << endl << "����������� ����� B:" << endl << com2 << endl; // ����� �������� ��� ������ ������������� ������� ������
    
    cout << "A + B: " << endl << com1 + com2 << endl;
    cout << "A - B:" << endl << com1 - com2 << endl;
    cout << "A * B:" << endl << com1 * com2 << endl;
    cout << "A / B:" << endl << com1 / com2 << endl;

    cout << endl;

    cin.get();
    cin.get();
}