#pragma once

class Complex {
public:
    Complex() {
        re = 0;
        im = 0;
        counter++;
    } // ����������� �� ���������

    Complex(double valueRe, double valueIm) {
        re = valueRe;
        im = valueIm;
        counter++;
    } // ����������� � �����������

    Complex(const Complex& com) {
        re = com.re;
        im = com.im;
        counter++;
    } // ����������� �����������

    Complex operator + (Complex&); // ���������� ������������� ������� �������� ����������� �����
    Complex operator - (Complex&); // ���������� ������������� ������� ��������� ����������� �����
    Complex operator * (Complex&); // ���������� ������������� ������� ��������� ����������� �����
    Complex operator / (Complex&); // ���������� ������������� ������� ������� ����������� �����
    friend std::istream& operator >>(std::istream&, Complex&); // ���������� ������������� ������� ����� ����������� �����
    friend std::ostream& operator << (std::ostream&, const Complex&); // ���������� ������������� ������� ������ ����������� �����
    static int counter; // ���������� ������������ ����� ������ �������� ��������
    double getRe(); // ���������� ������� ��� ��������� ���������� "re"
    double getIm();  // ���������� ������� ��� ��������� ���������� "im"
    void setRe(double valueRe); // ���������� ������� ��� ��������� ���������� "re"
    void setIm(double valueIm); // ���������� ������� ��� ��������� ���������� "im"

private:
    double re, im; // ���������� ���������� �������������� � ������ ����� ������������ �����

}; // ���������� ������ ��� ������ � ������������ �������

