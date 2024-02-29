#include "binary_trees.h"

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int current_level = 0;
	int max_nodes = 0;
	int nodes = 0;

	if (tree == NULL)
		return (0);

	while (tree)
	{
		max_nodes = 1 << current_level;
		nodes = binary_tree_count(tree);

		if (nodes != max_nodes)
			return (0);

		current_level++;
		tree = tree->left;
	}

	return (1);
}

/**
 * binary_tree_count - Counts the number of nodes in a binary tree
 * @tree: Pointer to the root node of the tree to count
 *
 * Return: Number of nodes in the tree
 */
size_t binary_tree_count(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (
			1 + binary_tree_count(tree->left) + binary_tree_count(tree->right));
}

