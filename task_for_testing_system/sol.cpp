#include <algorithm>
#include <memory>
#include <iterator>
using namespace std;

void mergeSort(int* mas, int size)
{
	if (size > 1)
	{
		const int leftSize = size / 2;
		const int rightSize = size - leftSize;

		mergeSort(&mas[0], leftSize);
		mergeSort(&mas[leftSize], rightSize);

		int left_ind = 0, right_ind = leftSize, index = 0;
		unique_ptr<int[]> tmp_array(new int[size]);

		while (left_ind < leftSize || right_ind < size)
		{
			if (mas[left_ind] < mas[right_ind])
			{
				tmp_array[index++] = mas[left_ind];
				left_ind++;
			}
			else
			{
				tmp_array[index++] = mas[right_ind];
				right_ind++;
			}

			if (left_ind == leftSize)
			{
				std::copy(std::make_move_iterator(&mas[right_ind]),
					std::make_move_iterator(&mas[size]),
					&tmp_array[index]);
				break;
			}
			if (right_ind == size)
			{
				std::copy(std::make_move_iterator(&mas[left_ind]),
					std::make_move_iterator(&mas[leftSize]),
					&tmp_array[index]);
				break;
			}
		}

		copy(std::make_move_iterator(&tmp_array[0]),
			std::make_move_iterator(&tmp_array[size]),
			mas);
	}
}
