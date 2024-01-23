#include "sort.h"
#include <stdio.h>

/**
 * print_list - Prints a doubly linked list of integers
 * @list: Pointer to the head of the doubly linked list
 */
void print_list(const listint_t *list)
{
	while (list != NULL)
	{
		printf("%d", list->n);
		if (list->next != NULL)
			printf(" <-> ");
		list = list->next;
	}
	printf("\n");
}

