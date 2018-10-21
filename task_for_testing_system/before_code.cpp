#define _CRT_SECURE_NO_DEPRECATE
#include <string>
#include <ctime>
#include <cstdio>
#include <iostream>
#include <chrono>

void mergeSort(int* mas, int size);

int main(int argc, char* argv[])
{
	int N;
	char const* file_in = argv[1];
	char const* file_out = argv[2];

	freopen(file_in, "rb", stdin);
	freopen(file_out, "wb", stdout);

	fread(&N, sizeof(N), 1, stdin);

	int* data = new int[5];
	
	fread(data, sizeof(*data), N, stdin);

	clock_t start, end;

	start = clock();

	mergeSort(data, N);

	end = clock();

	double time = (double)((end - start) / CLOCKS_PER_SEC);

	fwrite(&time, sizeof(time), 1, stdout);
	fwrite(data, sizeof(*data), N, stdout);

	return 0;
}