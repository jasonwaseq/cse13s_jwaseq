#include "final.h"

#include <stdio.h>

int depth_of_value(int value, BinaryTree *tree) {
    if (!tree) return -1;

    if (tree->val == value) return 0;

    int left_depth = depth_of_value(value, tree->left);
    int right_depth = depth_of_value(value, tree->right);

    if (left_depth == -1 && right_depth == -1) return -1;

    int min_depth = (left_depth == -1) ? right_depth : (right_depth == -1) ? left_depth : (left_depth < right_depth ? left_depth : right_depth);

    return min_depth + 1;
}
