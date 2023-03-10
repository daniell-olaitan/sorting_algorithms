#include "sort.h"

void swap_nodes(listint_t **list, listint_t *prev);

/**
 * cocktail_sort_list - implements cocktail sort algorithm
 * @list: the list of int to be sorted
 *
 */
void cocktail_sort_list(listint_t **list)
{
	int swap = 1;
	listint_t *current = NULL, *pick = NULL, *tmp = NULL;

	if (!list || !(*list) || !(*list)->next)
		return;

	while (1)
	{
		swap = 0;
		current = (*list)->next;
		while (current)
		{
			pick = current->prev;
			if (current->next == NULL)
				tmp = current;

			current = current->next;
			if (pick->n > pick->next->n)
			{
				swap_nodes(list, pick->next);
				swap = 1;
				print_list(*list);
			}
		}
		if (!swap)
			break;

		swap = 0;
		current = tmp->prev;
		while (current)
		{
			pick = current->next;
			current = current->prev;
			if (pick->n < pick->prev->n)
			{
				swap_nodes(list, pick);
				swap = 1;
				print_list(*list);
			}
		}
		if (!swap)
			break;
	}
}

/**
 * swap_nodes - swaps two nodes of an integer list
 * @list: the given list
 * @pick: the current node
 *
 */
void swap_nodes(listint_t **list, listint_t *pick)
{
	listint_t *tmp;

	if (pick->prev->prev)
		pick->prev->prev->next = pick;
	else
		*list = pick;

	if (pick->next)
		pick->next->prev = pick->prev;

	pick->prev->next = pick->next;
	tmp = pick->prev->prev;
	pick->prev->prev = pick;
	pick->next = pick->prev;
	pick->prev = tmp;
}
