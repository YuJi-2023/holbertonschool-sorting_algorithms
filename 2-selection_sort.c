#include "sort.h"
/**
  *selection_sort-sorts an array of integers in ascending order
  *@array: input array
  *@size: size of the array
  *Return: void
  */
void selection_sort(int *array, size_t size)
{
	size_t index, next;
	size_t position;
	int min;

	if (array == NULL || size < 2)
		return;
	index = 0;
	while (index < (size - 1))
	{
		position = index;
		next = index + 1;
		while (next < size)
		{
			if (array[position] > array[next])
			{
				position = next;
			}
			next = next + 1;
		}
		if (position != index)
		{
			min = array[index];
			array[index] = array[position];
			array[position] = min;
			print_array(array, size);
		}
		index = index + 1;
	}
}
