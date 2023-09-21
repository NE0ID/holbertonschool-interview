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
	listint_t **stack;
	listint_t *node;
	listint_t *tmp;
	listint_t *current;

	stack = malloc(sizeof(listint_t));
	if (stack == NULL)
		exit(EXIT_FAILURE);

	node = malloc(sizeof(listint_t));
	if (node == NULL)
		exit(EXIT_FAILURE);

	tmp = malloc(sizeof(listint_t));
	if (tmp == NULL)
		exit(EXIT_FAILURE);

	current = malloc(sizeof(listint_t));
	if (current == NULL)
		exit(EXIT_FAILURE);

	if (head == NULL)
		return (1);
	if (len_list(*head) == 1)
		return (1);

	node = *head;
	tmp = middle_ptr(head);

	while (node->next != middle_ptr(head))
	{
		push_stack(stack, node);
		node = node->next;
	}

	while (tmp->next != NULL)
	{
		if (stack != NULL)
		{
			current = pop_stack(stack);
			printf("%d - %d\n", current->n, tmp->n);
		}
		if (current->n != tmp->n)
			return (0);
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
				return (scnd_head->next);
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
 * push_stack - push a node into a stack
 *
 * @head: stack to check
 * @node: node to push
 *
 * Return: new stack or NULL on failure
 */
listint_t *push_stack(listint_t **stack, listint_t *node)
{
	listint_t *tmp;

	tmp = malloc(sizeof(listint_t));
	if (tmp == NULL)
		return (NULL);

	if (len_list(*stack) == 0)
	{
		*stack = node;
		return (*stack);
	}
	tmp = *stack;

	while (tmp->next != NULL)
	{
		if (tmp->next == NULL)
		{
			tmp->next->next = node;
			return (*stack);
		}
		tmp = tmp->next;
	}
	return (NULL);
}

/**
 * pop_stack - pop a node out of a stack
 *
 * @stack: stack to check
 *
 * Return: address of poped node or NULL on failure
 */
listint_t *pop_stack(listint_t **stack)
{
	listint_t *tmp;
	listint_t *current;

	tmp = malloc(sizeof(listint_t));
	if (tmp == NULL)
		return (NULL);

	current = malloc(sizeof(listint_t));
	if (current == NULL)
		return (NULL);

	if (len_list(*stack) == 0)
		return (NULL);

	tmp = *stack;
	while (tmp->next != NULL)
	{
		if (tmp->next->next == NULL)
		{
			current = tmp->next;
			tmp->next = NULL;
			return (current);
		}
		tmp = tmp->next;
	}
	return (NULL);
}
