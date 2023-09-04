#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - insert a node in a sorted linked list
 *
 * @head: head of list to work on
 * @number: value of node to insert
 *
 * Return: the address of the new node, or NULL if it failed
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *node;
	listint_t *tmp;

	node = malloc(sizeof(listint_t));
	if (node == NULL)
		return (NULL);

	tmp = malloc(sizeof(listint_t));
	if (tmp == NULL)
		return (NULL);

	node->n = number;

	if (head == NULL)
	{
		*head = node;
		node->next = NULL;
		return (node);
	}

	tmp = *head;
	while (tmp->next != NULL)
	{
		if (tmp->n > node->n)
		{
			node->next = tmp;
			*head = node;
			return (node);
		}
		if (tmp->next->n > number)
		{
			node->next = tmp->next;
			tmp->next = node;
			return (node);
		}
		tmp = tmp->next;
	}
	tmp->next = node;
	return (node);
}
