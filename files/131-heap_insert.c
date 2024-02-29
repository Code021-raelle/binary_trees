#include "binary_trees.h"

/**
 * tree_height - Computes the height of a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: Height of the tree
 */
size_t tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = tree_height(tree->left);
	right_height = tree_height(tree->right);

	return (1 + (left_height > right_height ? left_height : right_height));
}

/**
 * heap_insert - Inserts a value in Max Binary Heap
 * @root: Double pointer to the root node of the Heap
 * @value: Value to store in the node to be inserted
 *
 * Return: Pointer to the created node or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node, *parent;
	int temp;

	if (root == NULL)
		return (NULL);

	new_node = binary_tree_node(NULL, value);
	if (new_node == NULL)
		return (NULL);

	if (*root == NULL)
		return (*root = new_node);

	parent = *root;
	while (parent->left != NULL)
		parent = parent->left;

	while (parent->parent != NULL && new_node->n > parent->n)
	{
		temp = parent->n;
		parent->n = new_node->n;
		new_node->n = temp;
		parent = parent->parent;
	}

	if (parent->left == NULL)
		parent->left = new_node;
	else
		parent->right = new_node;

	new_node->parent = parent;

	return (new_node);
}

