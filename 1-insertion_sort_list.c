#include "sort.h"

#include "sort.h"

/**
 * print_list - Prints a list of integers
 *
 * @list: The list to be printed
 */
void print_list(const listint_t *list)
{
    int i;

    i = 0;
    while (list)
    {
        if (i > 0)
            printf(", ");
        printf("%d", list->n);
        ++i;
        list = list->next;
    }
    printf("\n");
}

/**
 * insertion_sort_list - sorts a doubly linked list in ascending order
 * using an insertion sort
 * @list: the given list to be sorted
 *
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current = NULL;
	listint_t *tmp = NULL;

	if (!list || !(*list) || !(*list)->next)
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
					tmp->prev->next = current;

				tmp->prev = current;
				print_list(*list);
			}
			tmp = tmp->next;
		}
		current = current->next;
	}
}
