#include "sort.h"

/**
 * selection_sort - Implement selection sort algorithm
 *
 * @array: An array of integers
 * @size: Number of elements in array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int min, temp;

	if (!array || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = array[i];
		for (j = i; j < size - 1; j++)
		{
			if (min > array[j + 1])
			{
				temp = array[j + 1];
				array[j + 1] = min;
				min = temp;
			}
		}

		array[i] = min;
		print_array(array, size);
	}
}
