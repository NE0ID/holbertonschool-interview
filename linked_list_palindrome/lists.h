#ifndef LISTS_H
#define LISTS_H

#include <stddef.h>
/**
 * struct listint_s - singly linked list
 * @n: integer
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 * for Holberton project
 */
typedef struct listint_s
{
    int n;
    struct listint_s *next;
} listint_t;

/* Given function prototypes */

size_t print_listint(const listint_t *h);
listint_t *add_nodeint_end(listint_t **head, const int n);
void free_listint(listint_t *head);

/* My prototypes */

int is_palindrome(listint_t **head);
int len_list(const listint_t *h);
listint_t *middle_ptr(listint_t **head);
listint_t *push_stack(listint_t **stack, listint_t *node);
listint_t *pop_stack(listint_t **stack);

#endif /* LISTS_H */
