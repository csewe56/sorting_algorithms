#ifndef DECK_H
#define DECK_H

#include <stddef.h>

/**
 * enum kind_e - Enumeration of card kinds
 * @SPADE: Spade
 * @HEART: Heart
 * @CLUB: Club
 * @DIAMOND: Diamond
 */
typedef enum kind_e
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} kind_t;

/**
 * struct card_s - Playing card
 * @value: Value of the card (From "Ace" to "King")
 * @kind: Kind of the card
 */
typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
 * struct deck_node_s - Deck of card node
 * @card: Pointer to the card of the node
 * @prev: Pointer to the previous node of the list
 * @next: Pointer to the next node of the list
 */
typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;

/**
 * sort_deck - Sorts a deck of cards
 * @deck: Pointer to the head of the doubly linked list
 */
void sort_deck(deck_node_t **deck);

#endif /* DECK_H */
