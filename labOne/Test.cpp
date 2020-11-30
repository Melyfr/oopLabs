#include "Complex.h"

int main() {
	setlocale(0, "rus");

	Complex com1(14, 5);
	Complex com2(4, 5);
	Complex res(18,10);

	assert(com1 + com2 == res); // Тест перегруженного метода сложения комплексных чисел пройден

	res.setRe(10);
	res.setIm(0);
	assert(com1 - com2 == res); // Тест перегруженного метода вычитания комплексных чисел пройден

	res.setRe(31);
	res.setIm(90);
	assert(com1 * com2 == res); // Тест перегруженного метода умножения комплексных чисел пройден

	com2.setRe(2);
	com2.setIm(10);
	res.setRe(0.75);
	res.setIm(-1.25);
	assert(com1 / com2 == res); // Тест перегруженного метода деления комплексных чисел пройден

	cout << "Все тесты пройдены успешно";

	cin.get();
	cin.get();
}
