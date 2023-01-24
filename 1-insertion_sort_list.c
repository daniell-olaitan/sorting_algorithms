#include "sort.h"

#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list in ascending order
 * using an insertion sort
 * @list: the given list to be sorted
 *
 */
void insertion_sort_list(listint_t **list)
{
	bool swap = false;
	listint_t *current = NULL;
	listint_t *tmp = NULL;

	if (!list || !(*list) || !(*list)->next)
		return;

	current = (*list)->next;
	while (current)
	{
		tmp = current->prev;
		if (tmp && current->n > tmp->n)
		{
			aux = current->next;
			
			{
				current->prev->next = current->next;
				if (current->next)
					current->next->prev = current->prev;

				current->next = tmp;
				current->prev = tmp->prev;
				if (tmp->prev)
					tmp->prev->next = current;
				else
					*list = current;

				tmp->prev = current;
				print_list(*list);
			}
			tmp = tmp->next;
		}
	}
}
