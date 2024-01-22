#include "sort.h"


/**
 *  partition_with_lomuto - This function is use to partition an
 *  array into two to sort it with quick sorting
 *  @array: The array to be sorted
 *  @lowerband: The first element/index of the array
 *  @upperband: The last element/index of the array
 *  Return: The Pivot of the partition
 */

int partition_with_lomuto(int array[], int lowerband, int upperband)
{
	/* Lomuto chooses the upperband as Pivot */
	/*size_t arr_size;*/
	int pivot = array[upperband];
	int i, j;

	/* Loop through the array from low to upperband - 1 index */
	for (j = lowerband; j < upperband; j++)
	{
		if (array[j] < pivot)
		{
			i++; /* Increment to the other indexes */
			if (i != j)
			{
				/* Swap i and j */
				swap(&array[i], &array[j]);
				/* Print after swap as expected by the question */
				print_array(array, arr_size);
			}
		}
	}

	/* Move the upperband which is the pivot to it correct position */
	i++;
	if (i != upperband)
	{
		swap(&array[i], &array[upperband]);
		/* Print array as expected */
		print_array(array, arr_size);
	}

	/* Then return the index where the pivot is currently */
	return (i);
}

/**
 * swap - This is a function that swaps two elements
 * @element1: The First element
 * @element2: The second element
 * Return: Void
 */

void swap(int *element1, int *element2)
{
	/* Save one element in temp and swap their locations */
	int temp = *element1;

	*element1 = *element2;
	*element2 = temp;
}

/**
 * quick_sort - This is to sort an array of integers in
 * ascending order using the Quick sort algorithm
 * @array: the array of elements to sort
 * @size: the length of the array.
 */

void quick_sort(int *array, size_t size)
{
	/* If array is NULL or the length is not more than 1 */
	if (array == NULL || size < 2)
		return;
	main_sort(array, 0, size - 1);
}

/**
 * main_sort - The main recursive function for the quick sort
 * @array: array of elements to sort
 * @lowerband: the firt index
 * @upperband: the size - 1 elements
 */

void main_sort(int *array, int lowerband, int upperband)
{
	int pivot;

	if (lowerband < upperband)
	{
		pivot = partition_with_lomuto(array, lowerband, upperband);
		main_sort(array, lowerband, pivot - 1);
		main_sort(array, pivot + 1, upperband);
	}
}
