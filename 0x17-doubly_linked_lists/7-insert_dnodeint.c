#include "lists.h"
/**
 * insert_dnodeint_at_index - inserts a new node at a given position.
 * @hd: pointer to head of the list
 * @idx: index to add at, starting from 0
 * @n: value of new node
 * Return: new node or null
 **/
dlistint_t *insert_dnodeint_at_index(dlistint_t **hd, unsigned int idx, int n)
{	unsigned int count;
	dlistint_t *tmp, *new, *aux_prev;

	if (hd == NULL && idx > 0)
		return (NULL);
	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);
	new->n = n, new->prev = new->next = NULL;

	if (idx == 0)
	{
		if (*hd)
		{
			new->next = *hd;
			(*hd)->prev = new, *hd = new;
		}
		else
			*hd = new;
		return (new);
	}
	count = 1, tmp = (*hd)->next;
	while (tmp)
	{
		if (idx == count)
		{
			tmp->prev->next = new, new->prev = tmp->prev;
			new->next = tmp, tmp->prev = new;
			return (new);
		}
		count++;
		aux_prev = tmp;
		tmp = tmp->next;
	}
	if (tmp == NULL && count == idx)
	{
		aux_prev->next = new, new->prev = aux_prev;
		return (new);
	}
	free(new);
	return (NULL);
}
