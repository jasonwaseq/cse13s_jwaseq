#include "final.h"

#include <stdio.h>

#include <string.h>

static WordCountTree *insert_word(WordCountTree *tree, const char *word, size_t count) {
    if (!tree) {
        WordCountTree *node = (WordCountTree *)malloc(sizeof(WordCountTree));
        node->word = strdup(word);
        node->count = count;
        node->left = node->right = NULL;
        return node;
    }

    int cmp = strcmp(word, tree->word);
    if (cmp < 0) {
        tree->left = insert_word(tree->left, word, count);
    } else if (cmp > 0) {
        tree->right = insert_word(tree->right, word, count);
    } else {
        tree->count += count;
    }
    return tree;
}

static void traverse_and_merge(WordCountTree *source, WordCountTree **target) {
    if (!source) return;
    *target = insert_word(*target, source->word, source->count);
    traverse_and_merge(source->left, target);
    traverse_and_merge(source->right, target);
}

WordCountTree *merge_trees(WordCountTree *tree1, WordCountTree *tree2) {
    WordCountTree *merged = NULL;
    traverse_and_merge(tree1, &merged);
    traverse_and_merge(tree2, &merged);
    return merged;
}
