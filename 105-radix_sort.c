#include "sort.h"
#include <stdlib.h>


/**
 * radix_sort - Sorts an array of integers in ascending order
 * using the LSD Radix sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */

void radix_sort(int *array, size_t size)
{
	int max, exp;

	if (array == NULL || size < 2)
		return;

	max = getMax(array, size);

	for (exp = 1; max / exp > 0; exp *= 10)
		countSort(array, size, exp);
}

/**
 * getMax - Finds the maximum value in an array
 * @array: The array to find the maximum value in
 * @size: The size of the array
 * Return: The maximum value in the array
 */

int getMax(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	return (max);
}

/**
 * countSort - Sorts an array using the counting sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 * @exp: The current exponent value (1, 10, 100, ...)
 */

void countSort(int *array, size_t size, int exp)
{
	const int base = 10;
	int *output = malloc(size * sizeof(int));
	size_t i;
	int *count = NULL;

	if (output == NULL)
		return;

	count = calloc(base, sizeof(int));

	if (count == NULL)
	{
		free(output);
		return;
	}

	for (i = 0; i < size; i++)
		count[(array[i] / exp) % base]++;

	for (i = 1; i < (size_t)base; i++)
		count[i] += count[i - 1];

	for (i = size; i > 0; i--)
	{
		output[count[(array[i - 1] / exp) % base] - 1] = array[i - 1];
		count[(array[i - 1] / exp) % base]--;
	}

	for (i = 0; i < size; i++)
		array[i] = output[i];

	print_array(array, size);
	free(output);
	free(count);
}
