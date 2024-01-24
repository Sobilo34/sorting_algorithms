#include "sort.h"

void cocktail_sort_list(listint_t **list);

/**
 * cocktail_sort_list - Implement Cocktail sorting algorithm
 *
 * @list: Doubly linked list
 */
void cocktail_sort_list(listint_t **list)
{
	bool swapped = true;
	listint_t *current, *start = NULL, *end = NULL;
	int temp, *current_n, *current_prev_next_n;

	if (*list == NULL || (*list)->next == NULL)
		return;

	current = *list;
	while (swapped)
	{
		swapped = false;
		while (current->next != end)
		{
			if (current->n > current->next->n)
			{
				current_n = (int *)&current->n;
				current_prev_next_n = (int *)&current->next->n;

				temp = *current_n;
				*current_n = *current_prev_next_n;
				*current_prev_next_n = temp;
				swapped = true;
				print_list(*list);
			}
			current = current->next;
		}
		if (!swapped)
			break;

		end = current;

		while (current->prev != start)
		{
			if (current->n < current->prev->n)
			{
				current_n = (int *)&current->n;
				current_prev_next_n = (int *)&current->prev->n;

				temp = *current_n;
				*current_n = *current_prev_next_n;
				*current_prev_next_n = temp;
				swapped = true;
				print_list(*list);
			}
			current = current->prev;
		}
		start = current->next;
	}
}
