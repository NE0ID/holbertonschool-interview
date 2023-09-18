#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

/**
 * is_palindrome - check if given list is a palindrome
 *
 * @head: head of list to check
 *
 * Return: 0 if it is not, 1 if it is
 */
int is_palindrome(listint_t **head)
{
	if (head == NULL)
		return (1);
	if (len_list(*head) == 0)
		return (1);

	if (comparing_nodes(head) == 0)
			return (0);
	return (1);
}

/**
 * comparing_nodes - compare values of nodes
 *
 * @node: node to check
 *
 * Return: 0 if values are different, 1 if values are the same
 */
int comparing_nodes(listint_t **head)
{
	listint_t *node;
	listint_t *tmp;
	int i;
	int *stock = 0;

	node = malloc(sizeof(listint_t));
	tmp = malloc(sizeof(listint_t));
	if (tmp == NULL)
		exit(EXIT_FAILURE);

	node = *head;
	tmp = middle_ptr(head);
	i = 0;

	while (i <= middle_len(head))
	{
		stock[i] = node->n;
		node = node->next;
		i++;
	}

	while (tmp->next != NULL)
	{
		while (i > 0)
		{
			if (stock[i] != tmp->n)
				return (0);
			i--;
		}
		tmp = tmp->next;
	}
	return (1);
}

/**
 * middle_ptr - find the pointer of the middle of the list
 *
 * @head: head of list to act on
 *
 * Return: middle pointer of a list
 */
listint_t *middle_ptr(listint_t **head)
{
	listint_t *scnd_head;
	int i;
	int len;

	scnd_head = malloc(sizeof(listint_t));
	if(scnd_head == NULL)
		return (NULL);

	scnd_head = *head;
	i = 0;
	len = len_list(*head);

	while (scnd_head->next != NULL)
	{
		if (len % 2 != 0)
		{
			if ((i == (len + 1) / 2))
				return (scnd_head);
		}
		if (i == (len / 2))
			return (scnd_head);
		scnd_head = scnd_head->next;
		i++;
	}
	return (NULL);
}

/**
 * len_list - count size of list
 *
 * @h: pointer to head of list
 *
 * Return: number of nodes / size of list
 */
int len_list(const listint_t *h)
{
    const listint_t *current;
    int n; /* number of nodes */

    current = h;
    n = 0;
    while (current != NULL)
    {
        current = current->next;
        n++;
    }

    return (n);
}

/**
 * middle_len - get middle length of list
 *
 * @head: list to check
 *
 * Return: the middle length of the list
 */
int middle_len(listint_t **head)
{
	return (len_list(middle_ptr(head)));
}
