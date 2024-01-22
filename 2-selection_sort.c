#include "sort.h"

/**
 * selection_sort - Implement selection sort algorithm
 *
 * @array: An array of integers
 * @size: Number of elements in array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_index;
	int temp;

	if (!array || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_index = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[min_index] > array[j])
			{
				min_index = j;
			}
		}
		temp = array[min_index];
		array[min_index] = array[i];
		array[i] = temp;

		print_array(array, size);
	}
}
