#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: Height of the tree in edges, or 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_h = 0, right_h = 0;

	if (tree == NULL)
		return (0);

	if (tree->left)
		left_h = 1 + binary_tree_height(tree->left);
	if (tree->right)
		right_h = 1 + binary_tree_height(tree->right);

	return (left_h > right_h ? left_h : right_h);
}

/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: Balance factor (left height - right height), or 0 if NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left_h = 0, right_h = 0;

	if (tree == NULL)
		return (0);

	if (tree->left)
		left_h = (int)binary_tree_height(tree->left) + 1;
	if (tree->right)
		right_h = (int)binary_tree_height(tree->right) + 1;

	return (left_h - right_h);
}
