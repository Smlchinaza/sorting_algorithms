#include "sort.h"

void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2);  // Forward declaration

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending order using Cocktail shaker sort
 * @list: Double pointer to the head of the doubly linked list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *start = *list;
	listint_t *end = NULL;
	int swapped;

	if (list == NULL || *list == NULL)
	return;

	do {
		swapped = 0;
		while (start->next != end) {
			if (start->n > start->next->n) {
				swap_nodes(list, start, start->next);
				print_list(*list);
				swapped = 1;
			} else {
				start = start->next;
			}
		}
		end = start;
		while (start->prev != NULL) {
			if (start->n < start->prev->n) {
				swap_nodes(list, start->prev, start);
				print_list(*list);
				swapped = 1;
			} else {
				start = start->prev;
			}
		}
	} while (swapped);
}

/**
 * swap_nodes - Swaps two adjacent nodes in a doubly linked list
 * @list: Double pointer to the head of the doubly linked list
 * @node1: First node to be swapped
 * @node2: Second node to be swapped
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (node1->prev != NULL)
		node1->prev->next = node2;
	else
		*list = node2;

	if (node2->next != NULL)
		node2->next->prev = node1;

	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;
}
