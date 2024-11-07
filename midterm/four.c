#include "midterm.h"

#include <stdio.h>

// PROBLEM 3
void bubble_sort_customers(ShoeCustomer *customers, size_t n_customers) {
int swapped;
    for (size_t i = 0; i < n_customers - 1; i++) {
        swapped = 0;
        for (size_t j = 0; j < n_customers - i - 1; j++) {
            if (customers[j].num_purchases < customers[j+1].num_purchases) {
                ShoeCustomer temp = customers[j];
                customers[j] = customers[j+1];
                customers[j+1] = temp;
                swapped = 1;
            }
        }
        if (swapped == 0) break;
    }
}
