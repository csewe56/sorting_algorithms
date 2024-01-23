#include "deck.h"
#include <stdlib.h>

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @a: Pointer to the first node
 * @b: Pointer to the second node
 */
void swap_nodes(deck_node_t *a, deck_node_t *b)
{
	if (a->prev)
		a->prev->next = b;

	if (b->next)
		b->next->prev = a;

	a->next = b->next;
	b->prev = a->prev;

	a->prev = b;
	b->next = a;
}

/**
 * sort_deck - Sorts a deck of cards
 * @deck: Pointer to the head of the doubly linked list
 */
void sort_deck(deck_node_t **deck)
{	deck_node_t *current, *next;
	int swapped;

	if (deck == NULL || *deck == NULL)
		return;

	do {
		swapped = 0;
		current = *deck;

	while (current->next != NULL)
	{
		next = current->next;

		if (next->card->kind < current->card->kind
				|| (next->card->kind == current->card->kind
					&& next->card->value < current->card->value))
	{
		swap_nodes(current, next);

		if (*deck == current)
			*deck = next;

		swapped = 1;
	}
	else
	{
		current = current->next;
	}
	}
	} while (swapped);
}

