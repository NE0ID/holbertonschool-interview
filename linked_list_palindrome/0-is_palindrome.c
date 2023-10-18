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
	int i;
	int size = middle_len(*head);
	int arr[size];
	listint_t *node;
	listint_t *tmp;

	if (head == NULL)
		return (1);
	if (len_list(*head) == 1)
		return (1);

	node = *head;
	tmp = middle_ptr(head);
	i = 0;

	while ((node != middle_ptr(head)) && i <= size)
	{
		arr[i] = node->n;
		node = node->next;
		i++;
	}

	while ((tmp) && i >= 0)
	{
		i--;
		if (arr[i] != tmp->n)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

/**
 * middle_len - find the pointer of the middle of the list
 *
 * @h: head of list to count
 *
 * Return: middle length of a list
 */
int middle_len(const listint_t *h)
{
	int len;

	len = len_list(h);

	if ((len % 2) != 0)
		len = (len + 1);
	return (len);
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
				return (scnd_head->next);
		}
		if (i == (len / 2))
			return (scnd_head);
		scnd_head = scnd_head->next;
		i++;
	}
	return (NULL);
}
