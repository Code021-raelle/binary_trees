#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height
 *
 * Return: Height of the tree, 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height = 0, right_height = 0;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	if (left_height >= right_height)
		return (left_height + 1);
	else
		return (right_height + 1);
}

/**
 * binary_tree_is_leaf - Checks if a node is a leaf
 * @node: Pointer to the node to check
 *
 * Return: 1 if node is a leaf, 0 otherwise.
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);

	if (node->left == NULL && node->right == NULL)
		return (1);

	return (0);
}

/**
 * heap_extract - Extracts the root node of a Max Binary Heap
 * @root: Double pointer to the root node of the Heap
 *
 * Return: Value stored in the root node or 0 on failure.
 */
int heap_extract(heap_t **root)
{
	heap_t *last_node, *tmp;
	int value;
	size_t height, level = 0;
	char *binary_path = NULL;

	if (root == NULL || *root == NULL)
		return (0);

	value = (*root)->n;
	height = binary_tree_height(*root);

	if (height == 1)
	{
		free(*root);
		*root = NULL;
		return (value);
	}

	binary_path = malloc(height + 1);
	if (binary_path == NULL)
		return (0);

	tmp = *root;
	while (!binary_tree_is_leaf(tmp))
	{
		if (tmp->left && !tmp->right)
			tmp = tmp->left;
		else if (!tmp->left && tmp->right)
			tmp = tmp->right;
		else if (binary_tree_height(tmp->left) >
				binary_tree_height(tmp->right))
			tmp = tmp->left;
		else
			tmp = tmp->right;

		binary_path[level++] = (tmp->parent &&
				tmp->parent->left == tmp) ? 'L' : 'R';
	}
	binary_path[level] = '\0';

	tmp = *root;
	while (level > 1)
	{
		if (binary_path[--level] == 'L')
			tmp = tmp->left;
		else
			tmp = tmp->right;
	}

	if (binary_path[level] == 'L')
	{
		last_node = (*root)->right;
		(*root)->n = tmp->left->n;
		free(tmp->left);
		tmp->left = NULL;
	}
	else
	{
		last_node = (*root)->left;
		(*root)->n = tmp->right->n;
		free(tmp->right);
		tmp->right = NULL;
	}

	free(binary_path);
	return (value);
}

