#include "Complex.h"

int main() {
    setlocale(0, "rus");

     // Complex com1, com2; // ������������� ���� �������� ��������� ����������� �� ���������

    Complex com1(5, 14); // ������������� ������� ������� ��������� ����������� � �����������
    // Complex com2(32, 2); // ������������� ������� ������� ��������� ����������� � �����������

    Complex com2(com1); // ������������� ������� ������� ��������� ����������� �����������

    
    cout << "����������� ����� A:" << endl << com1 << endl << "����������� ����� B:" << endl << com2 << endl; // ����� �������� ��� ������ ������������� ������� ������
    
    cout << "A + B:" << endl << com1 + com2 << endl;
    cout << "A - B:" << endl << com1 - com2 << endl;
    cout << "A * B:" << endl << com1 * com2 << endl;
    cout << "A / B:" << endl << com1 / com2 << endl;

    cin.get();
    cin.get();
}