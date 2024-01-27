#include "sort.h"
#include <stdlib.h>

/**
 * my_count_sort - This is a functin that sorts an array
 * using the counting sort algorithm
 * @arr: The array to be sorted
 * @arr_size: The length of the array
 * @exp_val: The current exponent value (1, 10, 100, ...)
 */

void my_count_sort(int *arr, size_t arr_size, int exp_val)
{
	const int base = 10;
	int *result = malloc(arr_size * sizeof(int));
	size_t index;
	int *count_arr = NULL;

	if (result == NULL)
		return;

	count_arr = calloc(base, sizeof(int));

	if (count_arr == NULL)
	{
		free(result);
		return;
	}

	for (index = 0; index < arr_size; index++)
		count_arr[(arr[index] / exp_val) % base]++;

	for (index = 1; index < (size_t)base; index++)
		count_arr[index] += count_arr[index - 1];

	for (index = arr_size; index > 0; index--)
	{
		result[count_arr[(arr[index - 1] / exp_val) % base] - 1] = arr[index - 1];
		count_arr[(arr[index - 1] / exp_val) % base]--;
	}

	for (index = 0; index < arr_size; index++)
		arr[index] = result[index];

	print_array(arr, arr_size);
	free(result);
	free(count_arr);
}


/**
 * radix_sort - This is radix sort algorithm that sorts
 * an array of integers in ascending order
 * @arr: The array to be sorted
 * @arr_size: The length of the array
 */

void radix_sort(int *arr, size_t arr_size)
{
	int high, exp_val;

	/* If the array is empty or index is not more than 1*/
	if (arr == NULL || arr_size < 2)
	{
		return;
	}

	high = gethighest(arr, arr_size);

	for (exp_val = 1; high / exp_val > 0; exp_val *= 10)
	{
		my_count_sort(arr, arr_size, exp_val);
	}
}

/**
 * gethighest - This is the function that gets the highest
 * value in an array of integer
 * @arr: The array to find the highest val
 * @arr_size: The length of the array
 * Return: The highest value in array
 */

int gethighest(int *arr, size_t arr_size)
{
	int high = arr[0];
	size_t index;

	for (index = 1; index < arr_size; index++)
	{
		if (arr[index] > high)
		{
			high = arr[index];
		}
	}

	return (high);
}
