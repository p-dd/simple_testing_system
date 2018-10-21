#pragma once
#define _CRT_SECURE_NO_DEPRECATE
#include <cstdio>
#include <cmath>
#include <string>
#include <fstream>

// Используется для взаимодействия с тестирующей системой
////////////////////////////////////////////////////////////////////////////////////////////
/*
// Checker может устанавливать вот эти три вердикта:
AC = Accepted = Решение выдаёт корректный результат на данном тесте
WA = Wrong Answer = Решение выдаёт некорректный результат на данном тесте
PE = Presentation Error = Ошибка формата выходных данных

// Остальные вердикты checker не может устанавливать
NO = No verdict = Вердикт отсутствует
CE = Compilation Error = Ошибка компиляции
ML = Memory Limit Exceeded = Превышено ограничение по памяти
TL = Time Limit Exceeded = Превышено ограничение по времени работы
RE = Runtime Error = Ошибка времени исполнения программы
IL = Idle Limit Exceeded = Превышено время простоя (бездействия) программы
DE = Deadly Error = Ошибка тестирующей системы
*/

enum verdict { NO = 1, AC, WA, CE, ML, TL, RE, IL, PE, DE };

class result
{
	std::ofstream fout;
public:

	enum ext_cls { NO = 1, VERDICT, MESSAGE, TIME, MEMORY };

	result()
	{
		fout.open("result.txt");
	}

	~result()
	{
		fout.close();
	}

	void write_type(ext_cls t)
	{
		fout << t;
	}

	// Сообщить тестирующей системе, что решение получило один из вердиктов verdict 
	void write_verdict(verdict v)
	{
		write_type(ext_cls::VERDICT); 
		fout << v;
	}

	// Написать сообщение от checker'a пользователю.  
	// Использовать только латинские буквы и знаки препинания
	void write_message(std::string str)
	{
		//write_type(ext_cls::MESSAGE); 
		fout << str;
	}

	// Сообщить тестирующей системе время работы программы участника, 
	//   вычисленное с помощью before_code
	// x имеет размерность 100 нс = 10 ^ (-7) сек
	void write_time(long long x)
	{
		write_type(ext_cls::TIME); 
		fout << x;
	}

	// Сообщить тестирующей системе, память затребованную программой участника
	void write_memory(unsigned long long x)
	{
		write_type(ext_cls::MEMORY); 
		fout << x;
	}
} checker_result;
