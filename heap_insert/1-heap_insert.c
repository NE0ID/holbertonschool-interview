#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * push - push a node into a stack
 *
 * @head: stack
 * @trNode: node to insert
 *
 * Return: stack with inserted node
 */
stack_t *push(stack_t **head, binary_tree_t *trNode)
{
	stack_t *stNode, *tmp;

	stNode = malloc(sizeof(stack_t));
	if(stNode == NULL)
		return (NULL);
	
	stNode->node = trNode;

	if (*head == NULL)
	{
		*head = stNode;
		return (stNode);
	}

	tmp = *head;
	while (tmp->next)
	{
		if (tmp->next == NULL)
		{
			tmp->next = stNode;
			return (stNode);
		}
		tmp = tmp->next
	}
}

/**
 * pop - pop a node off a stack
 *
 * @head: stack
 *
 * Return: poped node
 */
stack_t *pop(stack_t **head)
{
	stack_t *tmp, *curr;

	if (*head == NULL)
		return (NULL);

	while (tmp->next)
	{
		if (tmp->next->next == NULL)
		{
			curr = tmp->next;
			tmp->next = NULL;
			return (curr);
		}

		tmp = tmp->next;
	}
}

/**
 * hasLeft - check if tree has left node
 *
 * @root: root of tree to check
 *
 * Return: 0 for false, 1 for true
 */
int hasLeft(binary_tree_t *node)
{
	if (node->left)
		return (1);
	return (0);
}

/**
 * hasRight - check if tree has right node
 *
 * @root: root of tree to check
 *
 * Return: 0 for false, 1 for true
 */
int hasRight(binary_tree_t *node)
{
	if (node->right)
		return (1);
	return (0);
}

/**
 * heap_insert - insert node at the end of heap
 *
 * @root: root of tree to check
 * @value: value of node to check
 *
 * Return: new heap (with inserted node)
 */
heap_t *heap_insert(heap_t **root, int value)
{
	stack_t **st;
	binary_tree_t *tmp, *node;


	node = binary_tree_node(NULL, value);

	if (*root == NULL)
	{
		*root = node;
		return (node);
	}

	tmp = *root;
	while (tmp->left)
	{
		if(
	}

/**
 * swap - swap two nodes according to checked values (max version)
 *
 * @root: root of tree to check
 * @node: first node to swap
 * @curr: second node to swap (the last inserted)
 */
void swap(binary_tree_t *node)
{
	binary_tree_t *tmp;

	tmp = node;

	while (tmp->parent)
	{
		if (tmp->n > tmp->parent->n)
		{
			if (tmp->parent->right)
				tmp->right = tmp->parent->right;
			tmp->left = tmp->parent;
			tmp->parent = tmp->parent->parent;
		}
	}
}
