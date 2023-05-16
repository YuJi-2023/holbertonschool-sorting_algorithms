#include "sort.h"
/**
  *bubble_sort-sorts an array of integers in ascending order using the Bubble
  *@array: input array
  *@size: size of the array
  *Return: void
  */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int tmp;

	if (array == NULL || size < 2)
		return;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - 1)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				print_array(array, size);
			}
			j = j + 1;
		}
		i = i + 1;
	}
}
