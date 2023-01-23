#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list in ascending order
 * using an insertion sort
 * @list: the given list to be sorted
 *
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current == NULL;
	listint_t *pick == NULL;

	if (!list || !(*list) || !(list->next))
		return;

	current = *list;
	while (current != NULL)
	{
		tmp = *list;
		while (tmp != current)
		{
			if (current->n < tmp->n)
			{
				current->prev->next = current->next;
				if (current->next)
					current->next->prev = current->prev;

				current->next = tmp;
				current->prev = tmp->prev;
				if (tmp->prev)
					temp->prev->next = current;

				tmp->prev = current;
				print_list(*list);
			}
			tmp = tmp->next;
		}
		current = current->next;
	}
}
