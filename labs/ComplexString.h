#pragma once
#include "Complex.h" 

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