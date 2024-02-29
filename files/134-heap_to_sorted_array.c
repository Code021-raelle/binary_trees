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
 * swap - Swaps the values of two nodes
 * @a: Pointer to the first node
 * @b: Pointer to the second node.
 */
void swap(heap_t *a, heap_t *b)
{
	int temp;

	temp = a->n;
	a->n = b->n;
	b->n = temp;
}

/**
 * heapify_down - Restores the Max Heap property by moving the node downwards
 * @heap: Pointer to the root node of the heap.
 */
void heapify_down(heap_t *heap)
{
	heap_t *largest, *child;

	if (heap == NULL)
		return;

	largest = heap;
	if (heap->left && heap->left->n > largest->n)
		largest = heap->left;
	if (heap->right && heap->right->n > largest->n)
		largest = heap->right;

	if (largest != heap)
	{
		swap(heap, largest);
		heapify_down(largest);
	}
}

/**
 * heap_to_sorted_array - Converts a Binary Max Heap to a sorted array
 * @heap: Pointer to the root node of the heap to convert
 * @size: Address to store the size of the array
 *
 * Return: Pointer to the sorted array of integers.
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int *array;
	size_t i, height;

	if (heap == NULL || size == NULL)
		return (NULL);

	height = binary_tree_height(heap);
	array = malloc(sizeof(int) * (1 << height));
	if (array == NULL)
		return (NULL);

	for (i = 0; i < (1 << height); ++i)
	{
		array[i] = heap->n;
		if (i == (1 << height) - 1)
			break;
		swap(heap, heap->parent->right);
		heapify_down(heap->parent->right);
	}

	*size = (1 << height);
	return (array);
}

