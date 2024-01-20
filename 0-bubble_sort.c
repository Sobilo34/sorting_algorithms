#include "sort.h"

/**
 * bubble_sort - Sort Array using bubble sort algorithm
 *
 * @array: An array of integers
 * @size: Number of elements in array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;

	if (!array || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		bool is_swapped = false;

		for (j = 0; j < (size - i - 1); j++)
		{
			if (array[j] > array[j + 1])
			{
				int temp = array[j + 1];

				array[j + 1] = array[j];
				array[j] = temp;
				print_array(array, size);
				is_swapped = true;
			}
		}

		if (!is_swapped)
			break;
	}
}
