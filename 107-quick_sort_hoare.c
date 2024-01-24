#include "sort.h"

void swap_print(int *array, int i, int j, size_t size);

/**
 * quick_sort_hoare - Sorts an array of integers in ascending order
 * using the Quick sort algorithm with the Hoare partition scheme
 * @array: The array to be sorted
 * @size: The size of the array
 */

void quick_sort_hoare(int *array, size_t size)
{
	/* If array is NULL or the length is not more than 1 */
	if (array == NULL || size < 2)
		return;

	main_sort_hoare(array, 0, size - 1, size);
}

/**
 * main_sort_hoare - The main recursive function for quick_sort_hoare
 * @array: The array to be sorted
 * @lowerband: The first index
 * @upperband: The last index
 * @size: The size of the array
 */

void main_sort_hoare(int *array, int lowerband, int upperband, size_t size)
{
	int pivot;

	if (lowerband < upperband)
	{
		pivot = partition_with_hoare(array, lowerband, upperband, size);
		main_sort_hoare(array, lowerband, pivot, size);
		main_sort_hoare(array, pivot + 1, upperband, size);
	}
}

/**
 * partition_with_hoare - Partitions an array using the Hoare scheme
 * @array: The array to be sorted
 * @lowerband: the first index
 * @upperband: The last index
 * @size: The size of the array
 * Return: The pivot of the partition
 */

int partition_with_hoare(int *array, int lowerband, int upperband, size_t arr_size)
{
	int pivot = array[upperband];
	int i = lowerband - 1;
	int j = upperband + 1;

	while (array[i] < pivot)
	{
			i++;
	}

	while (array[j] > pivot)
	{
		j--;
	}

	if (i >= j)
	{
		return (j);
	}

	swap_print(array, i, j, arr_size);

	return (i);
}


/**
 * swap_print - This is to swaps two elements in an array and prints the array
 * @array: The array containing the elements
 * @i: The index of the first element to be swapped
 * @j: The index of the second element to be swapped
 * @size: The size of the array
 */

void swap_print(int *array, int i, int j, size_t size)
{
	int temp;

	if (i != j)
	{
		temp = array[i];
		array[i] = array[j];
		array[j] = temp;
		print_array(array, size);
	}
}
