#include "binary_trees.h"

/**
 * binary_tree_height_balance - measures height of a binary tree
 * @tree: pointer to the root node
 *
 * Return: height, or 0 if tree is NULL
 */
size_t binary_tree_height_balance(const binary_tree_t *tree)
{
	size_t left_height = 0, right_height = 0;

	if (tree == NULL)
		return (0);

	if (tree->left)
		left_height = 1 + binary_tree_height_balance(tree->left);
	if (tree->right)
		right_height = 1 + binary_tree_height_balance(tree->right);

	return (left_height > right_height ? left_height : right_height);
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node
 *
 * Return: balance factor (left height - right height)
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left_height = 0, right_height = 0;

	if (tree == NULL)
		return (0);

	if (tree->left)
		left_height = (int)binary_tree_height_balance(tree->left);
	if (tree->right)
		right_height = (int)binary_tree_height_balance(tree->right);

	return (left_height - right_height);
}
