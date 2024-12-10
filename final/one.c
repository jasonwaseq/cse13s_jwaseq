#include "final.h"
#include <stdio.h>
#include <limits.h>

size_t row_index_with_lowest_sum(int **matrix, size_t rows, size_t cols) {
    size_t min_index = 0;
    int min_sum = INT_MAX;
    for (size_t i = 0; i < rows; ++i) {
        int row_sum = 0;
        for (size_t j = 0; j < cols; ++j) {
            row_sum += matrix[i][j];
        }
        if (row_sum < min_sum) {
            min_sum = row_sum;
            min_index = i;
        }
    }
    return min_index;
}
