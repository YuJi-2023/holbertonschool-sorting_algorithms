#include "sort.h"
/**
  *swap - swap two integer
  *@array: input array
  *@i: the index of the first integer
  *@j: the index of the second integer
  *@size: size of the array
  *Return: void
  */
void swap(int *array, int i, int j, size_t size)
{
	int tmp;

	tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;
	print_array(array, size);
}

/**
  *partition - find the pivot of the part and put it to the right position.
  *@array: input array
  *@left: the index of the far left number
  *@right: the index of the far right number
  *@size: size of the array
  *Return: pivot (an integer)
  */
int partition(int *array, int left, int right, size_t size)
{
	int pivot;
	int i;
	int j;

	pivot = array[right];
	i = left - 1;
	j = left;
	while (j < right)
	{
		if (array[j] < pivot)
		{
			i = i + 1;
			if (i != j)
			{
				swap(array, i, j, size);
			}
		}
		j = j + 1;
	}

	if (array[i + 1] != pivot)
	{
		swap(array, i + 1, right, size);
	}
	return (i + 1);
}

/**
  *sort_arr - sorts an array of integers using recursion.
  *@array: input array
  *@left: the index of the far left number
  *@right: the index of the far right number
  *@size: size of the array
  *Return: void
  */
void sort_arr(int  *array, int left, int right, size_t size)
{
	int pivot;

	if (left < right)
	{
		pivot = partition(array, left, right, size);
		sort_arr(array, left, pivot - 1, size);
		sort_arr(array, pivot + 1, right, size);
	}
}

/**
  *quick_sort - sorts an array of integers in ascending order.
  *@array: input array
  *@size: size of the array
  *Return: void
  */
void quick_sort(int *array, size_t size)
{
	sort_arr(array, 0, size - 1, size);
}
