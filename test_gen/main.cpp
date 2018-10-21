#define _CRT_SECURE_NO_DEPRECATE
#include <cstdio>
#include <random>
#include <ctime>
#include <chrono>

using namespace std;

int n_tests[] = { 1, 2, 2, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 100, 200, 300, 400, 500, 600, 700, 800, 900, 1000 };

int main(int argc, char * argv[])
{
	// перенаправляем поток stdout в файл matr.in
	freopen("mas.in", "wb", stdout);
	
	std::default_random_engine generator(static_cast<unsigned int>(time(nullptr)));

	std::normal_distribution<double> distribution(100, 10);

	int n = 5;
	// если передали номер теста в аргументах командной строки, то берём размер из n_tests
	if (argc > 1)
		n = n_tests[atoi(argv[1])];
	// записываем в бинарном виде размерность матриц
	fwrite(&n, sizeof(n), 1, stdout);
	// создаём временный массив для строки матрицы
	int* cur = new int[n];
	// генерируем первую матрицу
	for (int i = 0; i < n; i++)
	{
		cur[i] = static_cast<int>(distribution(generator));
	}
	fwrite(cur, sizeof(*cur), n, stdout);

	return 0;
}
