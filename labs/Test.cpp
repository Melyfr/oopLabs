﻿#include "Complex.h"

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

void testTrigonometricView() {
	Complex test1(5, 30);
	assert(strcmp(test1(), "30,413813 * (cos 1,405648 + i * sin 1,405648)") == 0); // Тест перегруженного оператора <= (случай, когда <)комплексных чисел пройден

	test1.setRe(0);
	test1.setIm(0);
	assert(strcmp(test1(), "Триганометрический вид: 0, т.к. модуль комплексного числа = 0") == 0); // Тест перегруженного оператора <= (случай, когда <)комплексных чисел пройден
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

void testAll() {
	testMultiplication();
	testDividing();
	testEquality();
	testInequality();
	testGreater();
	testLess();
	testGreaterOrEquality();
	testLessOrEquality();
	testTrigonometricView();
	testAssignment();
}

