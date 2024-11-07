#include "midterm.h"

#include <stdio.h>

ll_float *insert_increasing_order(ll_float *list, float val) {
    ll_float *new_node = malloc(sizeof(ll_float));
    if (new_node == NULL) return list;
    	new_node->value = val;
    	new_node->next = NULL;
    if (list == NULL || val < list->value) {
        new_node->next = list;
        return new_node;
    }
    ll_float *current = list;
    while (current->next != NULL && current->next->value < val) {
        current = current->next;
    }
    new_node->next = current->next;
    current->next = new_node;
    return list;
}
