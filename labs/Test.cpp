#include "Complex.h"

void testMultiplication() {
	Complex test1(14, 5);
	Complex test2(4, 5);
	Complex res(31, 90);
	assert(test1 * test2 == res); // Тест перегруженного метода умножения комплексных чисел пройден
}

void testDividing() {
	Complex test1(14, 5);
	Complex test2(2, 10);
	Complex res(0.75, -1.25);
	assert(test1 / test2 == res); // Тест перегруженного метода деления комплексных чисел пройден

	test2.setRe(0);
	test2.setIm(0);
	res.setRe(0);
	res.setIm(0);
	assert(test1 / test2 == res); // В случае деления на 0 записывает во все поля комплексного числа 0, чтобы избежать ошибки, тест пройден
}

void testEquality() {
	Complex test1(5, 5);
	Complex test2(5, 5);
	assert(test1 == test2 == true); // Тест перегруженного оператора == комплексных чисел пройден
}

void testInequality() {
	Complex test1(6, 6);
	Complex test2(5, 5);
	assert(test1 != test2 == true); // Тест перегруженного оператора != комплексных чисел пройден
}

void testGreater() {
	Complex test1(6, 6);
	Complex test2(5, 5);
	assert(test1 > test2 == true); // Тест перегруженного оператора > комплексных чисел пройден
}

void testLess() {
	Complex test1(6, 6);
	Complex test2(5, 5);
	assert(test2 < test1 == true); // Тест перегруженного оператора < комплексных чисел пройден
}

void testGreaterOrEquality() {
	Complex test1(6, 6);
	Complex test2(5, 5);
	assert(test1 >= test2 == true); // Тест перегруженного оператора >= (случай, когда >) комплексных чисел пройден

	test1.setRe(5);
	test1.setIm(5);
	assert(test1 >= test2 == true); //  // Тест перегруженного оператора >= (случай, когда =) комплексных чисел пройден
}

void testLessOrEquality() {
	Complex test1(6, 6);
	Complex test2(5, 5);
	assert(test2 <= test1 == true); // Тест перегруженного оператора <= (случай, когда <)комплексных чисел пройден

	test1.setRe(5);
	test1.setIm(5);
	assert(test2 <= test1 == true); // Тест перегруженного оператора <= (случай, когда <)комплексных чисел пройден
}

void testAssignment() {
	Complex test1(15, 24);
	Complex test2(3, 13);
	test2 = test1;
	assert(test2 == test1);

	Complex test3(6, 75);
	test2.setRe(3);
	test2.setRe(13);
	test3 = test2 = test1;
	assert(test2 == test1);
	assert(test3 == test2);

	Complex test4(test1);
	test1 = test1;
	assert(test1 == test4);
}

void testSaveAndLoad() {
	Complex comS[5], comL[5];
	ofstream save("test.txt", ios_base::app);
	if (save.is_open()) {
		for (int i = 0; i < 5; i++) {
			comS[i] = Complex(i + 1, i + 1);
			save << comS[i].getRe() << " " << comS[i].getIm() << endl;
		}
		save.close();
	}

	ifstream load("test.txt", ios_base::in);
	if (load.is_open()) {
		for (int i = 0; i < 5; i++) {
			load >> comL[i];
			assert(comL[i] == comS[i]);
		}
		load.close();
	}

	fstream clearFile("test.txt", ios::out);
	clearFile.close();
}


void testSaveAndLoadBinary() {
	Complex comS[5], comL[5];
	ofstream saveB("testBinary.txt", ios_base::binary);
	if (saveB.is_open()) {
		for (int i = 0; i < 5; i++) {
			comS[i] = Complex(i + 1, i + 1);
			comS[i].saveBinary(saveB);
		}
		saveB.close();
	}

	ifstream loadB("testBinary.txt", ios_base::binary);
	if (loadB.is_open()) {
		for (int i = 0; i < 5; i++) {
			comL[i].loadBinary(loadB);
			assert(comL[i] == comS[i]);
		}
		loadB.close();
	}

	fstream clearFileB("testBinary.txt", ios::out);
	clearFileB.close();
}

void testTrigonometricView() {
	ComplexString test1(5, 30);
	test1.toTrigonometricView();
	assert(strcmp(test1(), "30,413813 * (cos 1,405648 + i * sin 1,405648)") == 0);

	test1.setRe(0);
	test1.setIm(0);
	test1.toTrigonometricView();
	assert(strcmp(test1(), "Триганометрический вид: 0, т.к. модуль комплексного числа = 0") == 0);
}

void testDate() {
	ComplexDate test1(5, 30);
	assert(test1.getYear() == 2020);
}

void testAll() {
	testMultiplication();
	testDividing();
	testEquality();
	testInequality();
	testGreater();
	testLess();
	testGreaterOrEquality();
	testLessOrEquality();
	testAssignment();
	testSaveAndLoad();
	testSaveAndLoadBinary();
	testTrigonometricView();
}

