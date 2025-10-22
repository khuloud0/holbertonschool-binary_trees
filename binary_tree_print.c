#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Original Holberton function to print a binary tree visually */
static int _height(const binary_tree_t *tree)
{
    int height_l;
    int height_r;

    if (!tree)
        return (0);
    height_l = _height(tree->left);
    height_r = _height(tree->right);
    if (height_l >= height_r)
        return (1 + height_l);
    return (1 + height_r);
}

static void print_tree(const binary_tree_t *tree, int offset, int depth, char **s)
{
    char b[6];
    int width, left, right, is_left, i;

    if (!tree)
        return;
    width = sprintf(b, "(%03d)", tree->n);
    left = _height(tree->left) * 2;
    right = _height(tree->right) * 2;
    is_left = (tree->parent && tree->parent->left == tree);
    for (i = 0; i < width; i++)
        s[depth][offset + left + i] = b[i];
    if (depth && is_left)
    {
        for (i = 0; i < left + width / 2; i++)
            s[depth - 1][offset + left + width / 2 - i - 1] = '-';
        s[depth - 1][offset + left + width / 2] = '.';
    }
    else if (depth && !is_left)
    {
        for (i = 0; i < right + width / 2; i++)
            s[depth - 1][offset + width / 2 + i] = '-';
        s[depth - 1][offset + left + width / 2] = '.';
    }
    print_tree(tree->left, offset, depth + 1, s);
    print_tree(tree->right, offset + left + width, depth + 1, s);
}

void binary_tree_print(const binary_tree_t *tree)
{
    char **s;
    int height, i;

    if (!tree)
        return;
    height = _height(tree) * 2;
    s = malloc(sizeof(*s) * height);
    for (i = 0; i < height; i++)
    {
        s[i] = malloc(255);
        memset(s[i], ' ', 255);
        s[i][254] = '\0';
    }
    print_tree(tree, 0, 0, s);
    for (i = 0; i < height; i++)
    {
        printf("%s\n", s[i]);
        free(s[i]);
    }
    free(s);
}
