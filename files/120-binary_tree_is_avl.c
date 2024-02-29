#include "binary_trees.h"

/**
 * max - Find the maximum of two numbers
 * @a: First number
 * @b: Second number
 *
 * Return: The maximum of a and b
 */
int max(int a, int b)
{
	return (a > b ? a : b);
}

/**
 * height - Calculates the height of a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: The height of the tree
 */
int height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (1 + max(height(tree->left), height(tree->right)));
}

/**
 * binary_tree_is_avl - Check if a binary tree is an AVL tree
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is ab AVL tree, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int left_height, right_height, balance_factor;

	if (tree == NULL)
		return (0);

	left_height = height(tree->left);
	right_height = height(tree->right);

	if (abs(left_height - right_height) > 1)
		return (0);

	if (!binary_tree_is_avl(tree->left) ||
			!binary_tree_is_avl(tree->right))
		return (0);

	return (1);
}

