#pragma once
#include "Complex.h" 

class ComplexDate : public Complex  {
public:
    ComplexDate() : Complex() {
        time_t now = time(0);
        date = localtime(&now);
    }

    ComplexDate(double valueRe, double valueIm) : Complex(valueRe, valueIm) {
        time_t now = time(0);
        date = localtime(&now);
    }

    ComplexDate(const ComplexDate& com) : Complex(com) {
        time_t now = time(0);
        date = localtime(&now);
    }

    ~ComplexDate();

    int getYear();
    int getMonth();
    int getDay();
    char* getDate();

private:
    tm* date;
};

