#include "binary_trees.h"

/**
 * tree_height - function to find the height of a tree
 * @tree: pointer to the tree
 * Return: height on success, 0 otherwise
 */
int tree_height(const binary_tree_t *tree)
{
	int left_size = 0;
	int right_size = 0;

	if (!tree)
		return (0);

	left_size += 1 + tree_height(tree->left);
	right_size += 1 + tree_height(tree->right);
	if (left_size > right_size)
		return (left_size);

	return (right_size);
}

/**
 * binary_tree_balance - find if a tree is balanced or not
 * @tree: pointer to the tree
 * Return: -1, 0, 2 accordingly
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	size_t left_side, right_side;

	if (tree == NULL)
		return (0);

	left_side = tree_height(tree->left);
	right_side = tree_height(tree->right);
	return (left_side - right_side);
}
