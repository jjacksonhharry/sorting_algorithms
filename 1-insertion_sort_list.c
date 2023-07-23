#include "sort.h"
#include <stdio.h>

/**
 * insertion_sort_list - function that sorts a doubly linked list of integers
 * @list: doubly linked list to sort
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current = NULL, *temp = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;
	while (current != NULL)
	{
		temp = current->prev;
		while (temp != NULL && temp->n > current->n)
		{
			temp->next = current->next;
			if (current->next != NULL)
				current->next->prev = temp;
			current->next = temp;
			current->prev = temp->prev;
			temp->prev = current;
			if (current->prev == NULL)
				*list = current;
			else
				current->prev->next = current;
			print_list(*list);
			temp = current->prev;
		}
		current = current->next;
	}
}
