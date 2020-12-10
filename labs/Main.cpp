#include "Complex.h"
#include "ComplexDate.h" 
#include "ComplexString.h" 

int main() {
    setlocale(0, "rus");
   
    ComplexString com1(51, -3);
    com1.toTrigonometricView();
    cout << com1;
    cout << com1.getTrigonometricView() << endl;
    cout << com1() << endl;

    cout << endl;
    ComplexDate com2(13, 74);
    cout << com2;
    cout << com2.getDate();

    testAll();

    cin.get();
    cin.get();
}