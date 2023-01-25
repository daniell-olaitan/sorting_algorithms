#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list in ascending order
 * using an insertion sort
 * @list: the given list to be sorted
 *
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current = NULL, *pick = NULL, *tmp = NULL;

	if (!list || !(*list) || !(*list)->next)
		return;

	current = (*list)->next;
	while (current)
	{
		pick = current;
		current = current->next;
		while (pick->prev && pick->n < pick->prev->n)
		{
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

			print_list(*list);
		}
	}
}
