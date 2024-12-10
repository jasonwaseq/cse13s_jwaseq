#include "final.h"

#include <stdio.h>

size_t count_and_find_maximum(ll_int *list, int *maxval) {
    if (!list || !maxval) return 0;
    int max_value = list->val;
    size_t max_count = 0;
    for (ll_int *current = list; current != NULL; current = current->next) {
        if (current->val > max_value) {
            max_value = current->val;
            max_count = 1;
        } else if (current->val == max_value) {
            max_count++;
        }
    }
    *maxval = max_value;
    return max_count;
}
