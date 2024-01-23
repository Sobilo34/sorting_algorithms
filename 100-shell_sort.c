#include "sort.h"

/**
 * shell_sort - This is to sort an array with shell sort
 * using Knuth sequence algorithm
 *
 * @array: The array to sort
 * @size: The length of the array
 */

void shell_sort(int *array, size_t size)
{
	size_t i, j, gap = 1;
	int temp;

	/* If array is NULL or element is not more than 1 do nothing */
	if (array == NULL || size < 2)
		return;

	/* Iitializes gap with the Knuth sequence */
	while (gap < size / 3)
		gap = gap * 3 + 1;

	/* Loop through until gap is <= 0 */
	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			j = i;

			while (j >= gap && array[j - gap] > temp)
			{
				swap(&array[j], &array[j - gap]);
				j -= gap;
			}

			array[j] = temp;
		}

		gap /= 3;

		/* Print array as expected */
		print_array(array, size);
	}
}


#include "sort.h"

/**
 * swap - This is to two elements in an array
 * @element1: The first element
 * @element2: The second element
 */
void swap(int *element1, int *element2)
{
	int temp = *element1;

	*element1 = *element2;
	*element2 = temp;
}
