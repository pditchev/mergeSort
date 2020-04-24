#include <iostream>

void printArr(int arr[], int size)
{
	for (size_t i = 0; i < size; i++)
	{
		std::cout << arr[i] << ' ';
	}
	std::cout << std::endl;
}

void merge(int arr[], int l, int m, int r)
{
	int i = 0;
	int j = 0;
	int n = l - 1;
	int left_size = m - l + 1;
	int right_size = r - m;

	int* L = new int[left_size];
	int* R = new int[right_size];

	memcpy(L, arr + l, sizeof(arr[0]) * left_size);
	memcpy(R, arr + m + 1, sizeof(arr[0])* right_size);

	while (i < left_size && j < right_size)
	{
		if (L[i] <= R[j])
		{
			arr[++n] = L[i];
			++i;
		}
		else
		{
			arr[++n] = R[j];
			++j;
		}
	}

	while (i < left_size)
	{
		arr[++n] = L[i];
		++i;
	}
	while (j < right_size)
	{
		arr[++n] = R[j];
		++j;
	}
}

void mergeSort(int arr[], int l, int r)
{
	if (l < r)
	{
		int m = (l + r) / 2;

		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);
		merge(arr, l, m, r);
	}
}

int main(int argc, int argv[])
{
	int arr[] = { 4, 56, 23, 8, 35, 13, 10 };
	int arr_size = sizeof(arr) / sizeof(arr[0]);

	printArr(arr, arr_size);
	mergeSort(arr, 0, arr_size - 1);
	printArr(arr, arr_size);

	return 0;
}