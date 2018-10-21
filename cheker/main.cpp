#define _CRT_SECURE_NO_DEPRECATE
#include <cstdio>
#include <cmath>
#include <string>
#include "result.h"
using namespace std;

int main(int argc, char* argv[])
{

	// ��������� ���� ������� ������, ���� �������� ������ � ����� ���������
	FILE * bui = fopen(argv[1], "rb");
	FILE * buo = fopen(argv[2], "rb");

	int n;
	// ��������� ����������� ������
	fread(&n, sizeof(n), 1, bui);

	// �������� ������ ��� ������� ������ ���� � ������ ���������
	int * ans = new int[n], *res = new int[n];
	double ans_time, res_time;

	// ��������� ����� ������ ��������� ��������� � ������� ���������
	fread(&res_time, sizeof(res_time), 1, buo);
	fread(res, sizeof(*res), n, buo);

	std::ifstream fin(R"(E:\SoftGrader\simple_testing_system\answer.txt)");

	fin >> ans_time;

	int* data = new int[n];

	for (int i = 0; i < n; ++i)
		fin >> ans[i];

	// ��������� ������, ��� ������� ����� �������� �������
	bool mistake = false;
	for(int i = 0; i < n; ++i)
	{
		if (ans[i] != res[i])
		{
			mistake = true;
			break;
		}
	}

	// ���������, ��� ������ ����, ����� ��������, ��� ������� ���������, ����� - �����������.
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

	// ���������� ����� � ���������� ����������� (��������� �� 100 �� = 10 ^ (-7) ���).
	//checker_result.write_time(res_time * 1e7);

	fclose(buo);

	return 0;
}