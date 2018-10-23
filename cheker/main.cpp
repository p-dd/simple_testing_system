#define _CRT_SECURE_NO_DEPRECATE
#include <cstdio>
#include <cmath>
#include <string>
#include "result.h"
using namespace std;

int main(int argc, char* argv[])
{
	const string way = string(argv[3]);
	result checker_result(way);
	// Открываем файл входных данных, файл выходных данных и ответ участника
	FILE * bui = fopen(argv[1], "rb");
	FILE * buo = fopen(argv[2], "rb");
	FILE * bua = fopen(argv[4], "rb");

	int n;
	// Считываем размерность матриц
	fread(&n, sizeof(n), 1, bui);

	// Выделяем память для матрицы ответа жюри и ответа участника
	int * ans = new int[n], *res = new int[n];
	double ans_time, res_time;

	// Считываем время работы программы участника и матрицу участника
	fread(&res_time, sizeof(res_time), 1, buo);
	fread(res, sizeof(*res), n, buo);

	fread(&ans_time, sizeof(ans_time), 1, bua);

	fread(ans, sizeof(*ans), n, bua);

	// Вычисляем ошибку, как квадрат нормы разности решений
	bool mistake = false;
	for(int i = 0; i < n; ++i)
	{
		if (ans[i] != res[i])
		{
			mistake = true;
			break;
		}
	}

	// Проверяем, что ошибка мала, тогда сообщаем, что решение корректно, иначе - некорректно.
	if (!mistake)
	{
		checker_result.write_message("AC. Numbers are equal.");
		//checker_result.write_verdict(verdict::AC);
	}
	else
	{
		checker_result.write_message("WA. Output is not correct.");
		//checker_result.write_verdict(verdict::WA);
	}

	// Записываем время в правильной размерности (интервалы по 100 нс = 10 ^ (-7) сек).
	//checker_result.write_time(res_time * 1e7);

	fclose(buo);

	return 0;
}