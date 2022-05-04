

#include <iostream>


void SortArray(int* arr, int count);
bool IsArraySorted(const int* arr, int count);

int main(int argc, char** argv)
{
	const int NUM_ITEMS = 8;
	int numbers[NUM_ITEMS] = { 13, 1, 7, 5, 11, 9, 15, 3 };


	SortArray(numbers, NUM_ITEMS);

	// Test: all values should be sorted in ascending order
	if (IsArraySorted(numbers, NUM_ITEMS)) std::cout << "Pass: the array is sorted" << std::endl;
	else std::cout << "Fail: the array is not sorted" << std::endl;

	return 0;
}

bool IsArraySorted(const int* arr, int count)
{	
	for (int i = 0; i < count - 1; i++)
	{
		if (arr[i] > arr[i + 1])
			return false;
	}

	return true;
}


void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void SortArray(int* arr, int count)
{

	bool sorted = false; //set to false to ensure the while loop starts up
	while (!sorted)
	{
		sorted = true;
		for (int i = 0; i < count - 1 ; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				swap(arr[i], arr[i + 1]);
				sorted = false;
			}
		}
	}

	//needed to check why the test was failing turns out I was doing it backwards.. fixed through changing '<' to '>' 
	// 
			//for (int i = 0; i < count; i++)
			//{
			//	std::cout << arr[i] << std::endl;
			//}

}
