#include "sort.h"

/**
 * cocktail_sort_list - unction that sorts a doubly linked list of integers
 * @list: The doubly linked list to be sorted
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *start = NULL, *end = NULL, *tmp = NULL;
	int swapped = 0;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	start = *list;
	end = NULL;

	do {
		swapped = 0;
		while (start->next != end)
		{
			if (start->n > start->next->n)
			{
				tmp = start->next;
				start->next = tmp->next;
				if (tmp->next != NULL)
					tmp->next->prev = start;
				tmp->prev = start->prev;
				if (start->prev != NULL)
					start->prev->next = tmp;
				else
					*list = tmp;
				start->prev = tmp;
				tmp->next = start;
				print_list(*list);
				swapped = 1;
			}
			else
			{
				start = start->next;
			}
		}
		end = start;
		while (end->prev != NULL)
		{
			if (end->n < end->prev->n)
			{
				tmp = end->prev;
				end->prev = tmp->prev;
				if (tmp->prev != NULL)
					tmp->prev->next = end;
				else
					*list = end;
				tmp->next = end->next;
				if (end->next != NULL)
					end->next->prev = tmp;
				end->next = tmp;
				tmp->prev = end;
				print_list(*list);
				swapped = 1;
			}
			else
			{
				end = end->prev;
			}
		}
	} while (swapped);
}
