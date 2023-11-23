#ifndef __BINARY_TREES_H__
#define __BINARY_TREES_H

#include <stddef.h>

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
typedef struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
} binary_tree_t;

typedef struct binary_tree_s heap_t;

/**
 * struct stack_tree_s - stack tree node
 * @node: stocked binary_tree_t node
 * @next: next stack node
 */
typedef struct stack_tree_s
{
	struct stack_tree_s *head;
	struct binary_tree_s *node;
	struct stack_tree_s *next;
} stack_t;
/* Prototypes (example functions) */
void binary_tree_print(const binary_tree_t *);

/* Prototypes (my functions) */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
int hasLeft(binary_tree_t *node);
int hasRight(binary_tree_t *node);
heap_t *heap_insert(heap_t **root, int value);
void swap(binary_tree_t *node);

#endif /* __BINARY_TREES_H__ */
