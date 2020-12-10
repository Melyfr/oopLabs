#include "ComplexString.h" 

ComplexString::~ComplexString() {
	delete trigonometricView;
}

void ComplexString::toTrigonometricView() {
    if (module(*this) != 0) {
        delete trigonometricView;
        trigonometricView = new char[28 + sizeof(module(*this)) + sizeof(atan(im / re)) * 2];
        sprintf(trigonometricView, "%f * (cos %f + i * sin %f)", module(*this), atan(im / re), atan(im / re));
    }
    else {
        delete trigonometricView;
        trigonometricView = new char[63];
        strcpy(trigonometricView, "Триганометрический вид: 0, т.к. модуль комплексного числа = 0");
    }
}

char* ComplexString::getTrigonometricView() {
    return trigonometricView;
}

void ComplexString::setTrigonometricView(char* valueStr) {
	delete trigonometricView;
    trigonometricView = new char(strlen(valueStr)+1);
}

char* ComplexString::operator() () {
    return trigonometricView;
}
