#pragma once
#include <iostream> 
#include <assert.h>
using namespace std;

class Complex {
public:
    Complex (); // ���������� ������������ �� ���������
    Complex (double valueRe, double valueIm); // ���������� ������������ � �����������
    Complex (const Complex& com);// ���������� ������������ �����������

    Complex operator + (Complex&); // ���������� ������������� ������� �������� ����������� �����
    Complex operator - (Complex&); // ���������� ������������� ������� ��������� ����������� �����
    Complex operator * (Complex&); // ���������� ������������� ������� ��������� ����������� �����
    Complex operator / (Complex&); // ���������� ������������� ������� ������� ����������� �����

    friend std::istream& operator >> (std::istream&, Complex&); // ���������� ������������� ������� ����� ����������� �����
    friend std::ostream& operator << (std::ostream&, const Complex&); // ���������� ������������� ������� ������ ����������� �����

    double getRe (); // ���������� ������� ��� ��������� ���������� "re"
    double getIm ();  // ���������� ������� ��� ��������� ���������� "im"
    void setRe (double valueRe); // ���������� ������� ��� ��������� ���������� "re"
    void setIm (double valueIm); // ���������� ������� ��� ��������� ���������� "im"

    bool operator == (Complex& com); // ���������� ������������� ������� ��������� ����������� �����

    static int counter; // ���������� ������������ ����� ������ �������� ��������

private:
    double re, im; // ���������� ���������� �������������� � ������ ����� ������������ �����

}; // ���������� ������ ��� ������ � ������������ �������

