#ifndef SORTING_H
#define SORTING_H

#include <stddef.h>

/**
 * struct listint_s - Doubly linked list node
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
void swap_int(int *array, size_t a, size_t b);
void swap_int1(int *array, int a, int b);
void recursive_quick_sort(int *array, size_t size, int start, int end);
size_t partition(int *array, size_t size, int start, int end);
listint_t *create_listint(const int *array, size_t size);
void swap_integers(int *a, int *b);
void swap_nodes(listint_t **list, listint_t **node1, listint_t **node2);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);
void heap_sort(int *array, size_t size);
void sort_deck(deck_node_t **deck);


#endif /*MAIN_H*/
