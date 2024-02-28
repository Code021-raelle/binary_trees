#include "binary_trees.h"
#include "queue.h"

/**
 * binary_tree_levelorder - Traverses a binary tree using level-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	queue_t *queue = NULL;
	const binary_tree_t *temp;

	if (!tree || !func)
		return;

	queue = queue_push(queue, (void *)tree);

	while (!queue_empty(queue))
	{
		temp = (const binary_tree_t *)queue_front(queue);
		queue = queue_pop(queue);

		func(temp->n);

		if (temp->left)
			queue = queue_push(queue, (void *)temp->left);
		if (temp->right)
			queue = queue_push(queue, (void *)temp->right);
	}

	queue_delete(queue);
}

