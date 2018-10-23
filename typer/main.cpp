#define _CRT_SECURE_NO_DEPRECATE
#include <string>
#include <cstdio>
#include <fstream>

int main(int argc, char* argv[])
{
	if (argc == 3 && std::string(argv[1]) == "typer")
	{
		int N;
		char const* file_out = argv[2];

		std::ifstream fin("input.txt");

		fin >> N;

		int* data = new int[N];

		for (int i = 0; i < N; ++i)
			fin >> data[i];

		freopen(file_out, "wb", stdout);
		fwrite(&N, sizeof(N), 1, stdout);
		fwrite(data, sizeof(*data), N, stdout);
	}
	if (argc == 5 && std::string(argv[1]) == "viewer")
	{
		int N;
		double time;
		char const* file_in = argv[2];
		char const* file_size = argv[3];
		
		freopen(file_size, "rb", stdin);
		fread(&N, sizeof(N), 1, stdin);
		fclose(stdin);

		freopen(file_in, "rb", stdin);
		

		fread(&time, sizeof(time), 1, stdin);

		int* data = new int[N];

		fread(data, sizeof(*data), N, stdin);

		std::ofstream fout(argv[4]);
		fout << time << " ";
		for (int i = 0; i < N; ++i)
			fout << data[i] << " ";
		fout << std::endl;
		fout.close();
	}
	return 0;
}
