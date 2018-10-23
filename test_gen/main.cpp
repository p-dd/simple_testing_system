#define _CRT_SECURE_NO_DEPRECATE
#include <cstdio>
#include <random>
#include <ctime>
#include <chrono>

using namespace std;

int main(int argc, char * argv[])
{
	freopen(argv[1], "wb", stdout);
	
	default_random_engine generator(chrono::system_clock::now().time_since_epoch().count());
	
	uniform_real_distribution <double> distribution(-10, 10);

	int n = 5;

	fwrite(&n, sizeof(n), 1, stdout);

	int* cur = new int[n];

	for (int i = 0; i < n; i++)
	{
		cur[i] = static_cast<int>(distribution(generator));
	}

	fwrite(cur, sizeof(*cur), n, stdout);

	return 0;
}
