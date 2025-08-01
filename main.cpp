#include <vector>
#include <iostream>

// Вычисление следующего элемента последовательности
int64_t next_x(int x, int a, int c, int m) {
	return (int64_t(a) * x + c) % m;
}

int modinv(int a, int m) {
	for (int i = 1; i < m; ++i) {
		if ((a * i) % m == 1) {
			return i;
		}
	}
	return -1; // Нет обратного по модулю
}

int main() {
	const int MAX_M = 65535;
	int x0, x1, x2, x3;

#ifdef _DEBUG
	x0 = 157;
	x1 = 5054;
	x2 = 25789;
	x3 = 13214;
	std::cout
		<< "x0 = " << x0 << '\n'
		<< "x1 = " << x1 << '\n'
		<< "x2 = " << x2 << '\n'
		<< "x3 = " << x3 << '\n'
		<< '\n';
#else
	std::cout << "Введите x0: "; std::cin >> x0;
	std::cout << "Введите x1: "; std::cin >> x1;
	std::cout << "Введите x2: "; std::cin >> x2;
	std::cout << "Введите x3: "; std::cin >> x3;
	std::cout << '\n';
#endif


	std::cout
		<< "Результаты:\n"
		<< "a\tc\tm\tx4\n";

	for (int m = 2; m <= MAX_M; ++m) {
		// Разность между x2, x1 по модулю m
		int numerator = (x2 - x1 + m) % m;

		int denom = (x1 - x0 + m) % m;
		if (denom == 0) continue;

		int inv = modinv(denom, m);
		if (inv == -1) continue;

		// Находим a, c
		int a = (numerator * inv) % m;
		int c = (x1 - a * x0) % m;
		if (c < 0) c += m;

		// Выводим результаты, предварительно проверив
		if (
			(next_x(x0, a, c, m) == x1)
			&& (next_x(x1, a, c, m) == x2)
			&& (next_x(x2, a, c, m) == x3)
			) {

			std::cout
				<< a << '\t'
				<< c << '\t'
				<< m << '\t'
				<< next_x(x3, a, c, m) << '\t'
				<< '\n';
		}
	}

	return 0;
}