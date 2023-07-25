#include <stdlib.h>
#include <string.h>
#include "deck.h"

int card_cmp(const void *a, const void *b)
{
	const card_t *card1 = *(const card_t **)a;
	const card_t *card2 = *(const card_t **)b;

	if (card1->kind != card2->kind)
		return card1->kind - card2->kind;
	else
		return strcmp(card1->value, card2->value);
}

void sort_deck(deck_node_t **deck)
{
	size_t i;
	card_t *cards[52];
	deck_node_t *node;

	if (deck == NULL || *deck == NULL)
		return;

	node = *deck;
	for (i = 0; i < 52; i++)
	{
		cards[i] = (card_t *)node->card;
		node = node->next;
	}

	qsort(cards, 52, sizeof(card_t *), card_cmp);

	node = *deck;
	for (i = 0; i < 52; i++)
	{
		node->card = cards[i];
		node = node->next;
	}
}
