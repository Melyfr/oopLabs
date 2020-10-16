#pragma once

class complex {
private:
    double re, im; // ѕеременные содержащие действительную и мнимую части комплексного числа

public:
    complex() {
        re = 0;
        im = 0;
    } //  онструктор обнулени€ переменных

    complex operator + (complex); // ќбъ€вление перегруженной функции сложени€ комплексных чисел
    complex operator - (complex); // ќбъ€вление перегруженной функции вычитани€ комплексных чисел
    complex operator * (complex&); // ќбъ€вление перегруженной функции умножени€ комплексных чисел
    complex operator / (complex&); // ќбъ€вление перегруженной функции делени€ комплексных чисел
    friend std::istream& operator >>(std::istream&, complex&); // ќбъ€вление перегруженной функции ввода комплексных чисел
    friend std::ostream& operator << (std::ostream&, const complex&); // ќбъ€вление перегруженной функции вывода комплексных чисел
}; // ќбъ€вление класса дл€ работы с комплексными числами