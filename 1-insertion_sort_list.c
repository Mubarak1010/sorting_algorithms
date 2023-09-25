#include "sort.h"

/**
 * swap - program entry
 * @h: the head of the list
 * @n1: first node to be swapped
 * @n2: second node to be swapped
 */

void swap(listint_t **h, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;

	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;

	else
		*h = n2;

	(*n1)->prev = n2;
	*n1 = n2->prev;
}

/**
 * insertion_sort_list - program entry
 * @list: the list of elements
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *i, *insert, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (i = (*list)->next; i != NULL; i = tmp)
	{
		tmp = i->prev;
		insert = i->prev;

		while (insert != NULL && i->n < insert->n)
		{
			swap(list, &insert, i);
			print_list((const listint_t *)*list);
		}
	}
}
