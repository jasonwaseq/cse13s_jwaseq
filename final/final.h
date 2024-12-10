#pragma once

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Question one.
size_t row_index_with_lowest_sum(int **matrix, size_t rows, size_t cols);

// Question two.
typedef struct ll_int {
  int val;
  struct ll_int *next;
} ll_int;

size_t count_and_find_maximum(ll_int *list, int *maxval);

// Question three.
int apply_many_times(int (*func)(int), int x, size_t n);

// Question four.
typedef struct BinaryTree {
  int val;
  struct BinaryTree *left;
  struct BinaryTree *right;
} BinaryTree;

int depth_of_value(int value, BinaryTree *tree);

// Question five.
typedef struct WordCountTree {
  char *word;
  size_t count;
  struct WordCountTree *left;
  struct WordCountTree *right;
} WordCountTree;

WordCountTree *merge_trees(WordCountTree *tree1, WordCountTree *tree2);

// Idea for the UNUSED macro from Stack Overflow user mtvec. Thanks!
// https://stackoverflow.com/a/3599170
#define UNUSED(x) (void)(x)
