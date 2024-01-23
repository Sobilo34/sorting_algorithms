#include "sort.h"

/**
 * counting_sort - This is algorithm that sorts an array using Counting sort
 * @array: The array to be sorted
 * @size: The leength of the array
 */
void counting_sort(int *array, size_t size)
{
	int *count_list, highest = 0;
	size_t i, j = 0;

	/* If array is NULL or element is not more than 1 do nothing */
	if (array == NULL || size < 2)
		return;

	/* Look for the highest value in the array */
	for (i = 0; i < size; i++)
	{
		if (array[i] > highest)
		highest = array[i];
	}

	count_list = malloc((highest + 1) * sizeof(int));
	/* Check if memory allocation is successful */
	if (count_list == NULL)
	{
		return;
	}

	for (i = 0; i <= (size_t)highest; i++)
	{
		count_list[i] = 0;
	}

	/* Count the occurrences of each element in the array */
	for (i = 0; i < size; i++)
		count_list[array[i]]++;

	/* Print the counting array */
	print_array(count_list, highest + 1);

	/* Update the original array using the counting array */
	for (i = 0; i <= (size_t)highest; i++)
	{
		while (count_list[i] > 0)
		{
			array[j++] = i;
			count_list[i]--;
		}
	}

	/* Print the array afterward */
	print_array(array, size);

	/* Free the memory allocated to count_list */
	free(count_list);
}
