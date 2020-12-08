#include "Complex.h"

int main() {
    setlocale(0, "rus");
   
    Complex com1(53,-23), com2;

    ofstream save("test.txt", ios_base::app);
    if (save.is_open()) {
        save << com1.getRe() << " " << com1.getIm() << endl;
        save.close();
    }

    ifstream load("test.txt", ios_base::in);
    if (load.is_open()) {
        load >> com2;
        load.close();
        cout << com2 << endl;
    }

    com1.setRe(12);
    com1.setIm(35);

    ofstream saveB("testBinary.txt", ios_base::binary);
    com1.saveBinary(saveB);
    save.close();

    ifstream loadB("testBinary.txt", ios_base::binary);
    com2.loadBinary(loadB);
    cout << com2 << endl;
    load.close();
    
    fstream clearFile("test.txt", ios::out);
    clearFile.close();

    fstream clearFileB("testBinary.txt", ios::out);
    clearFileB.close();

    testAll();

    cin.get();
    cin.get();
}