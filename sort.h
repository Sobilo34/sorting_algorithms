#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>

/**
 * struct listint_s - This is a doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void swap_nodes(listint_t **list, listint_t *node1
, listint_t *node2);
int partition_with_lomuto(int array[], int lowerband,
		int upperband, size_t arr_size);
void swap(int *element1, int *element2);
void quick_sort(int *array, size_t size);
void main_sort(int *array, int lowerband,
		int upperband, size_t size);
void shell_sort(int *array, size_t size);
void counting_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void quick_sort_hoare(int *array, size_t size);
void main_sort_hoare(int *array, int lowerband, int upperband, size_t size);
void swap_print(int *array, int i, int j, size_t size);
int partition_with_hoare(int *array, int upperband,
		int lowerband, size_t arr_size);
int gethighest(int *arr, size_t arr_size);
void my_count_sort(int *arr, size_t arr_size, int exp_val);
void radix_sort(int *arr, size_t arr_size);

#endif
