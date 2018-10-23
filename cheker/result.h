#pragma once
#define _CRT_SECURE_NO_DEPRECATE
#include <cstdio>
#include <cmath>
#include <string>
#include <fstream>

/*
// Checker ����� ������������� ��� ��� ��� ��������:
AC = Accepted = ������� ����� ���������� ��������� �� ������ �����
WA = Wrong Answer = ������� ����� ������������ ��������� �� ������ �����
PE = Presentation Error = ������ ������� �������� ������

// ��������� �������� checker �� ����� �������������
NO = No verdict = ������� �����������
CE = Compilation Error = ������ ����������
ML = Memory Limit Exceeded = ��������� ����������� �� ������
TL = Time Limit Exceeded = ��������� ����������� �� ������� ������
RE = Runtime Error = ������ ������� ���������� ���������
IL = Idle Limit Exceeded = ��������� ����� ������� (�����������) ���������
DE = Deadly Error = ������ ����������� �������
*/

enum verdict { NO = 1, AC, WA, CE, ML, TL, RE, IL, PE, DE };

class result
{
	std::ofstream fout;
public:

	enum ext_cls { NO = 1, VERDICT, MESSAGE, TIME, MEMORY };

	result(std::string path)
	{
		fout.open(path);
	}

	~result()
	{
		fout.close();
	}

	void write_type(ext_cls t)
	{
		fout << t;
	}
 
	void write_verdict(verdict v)
	{
		write_type(ext_cls::VERDICT); 
		fout << v;
	}


	void write_message(std::string str)
	{
		//write_type(ext_cls::MESSAGE); 
		fout << str;
	}

	// �������� ����������� ������� ����� ������ ��������� ���������, 
	//   ����������� � ������� before_code
	// x ����� ����������� 100 �� = 10 ^ (-7) ���
	void write_time(long long x)
	{
		write_type(ext_cls::TIME); 
		fout << x;
	}

	// �������� ����������� �������, ������ ������������� ���������� ���������
	void write_memory(unsigned long long x)
	{
		write_type(ext_cls::MEMORY); 
		fout << x;
	}
};
