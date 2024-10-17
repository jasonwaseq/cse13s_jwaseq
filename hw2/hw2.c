/*
 * All of your code for these five functions goes in here. These are for you to
 * finish. The code for the calculator is separate. Feel free to include more
 * headers or define helper functions if you want, but you can do this homework
 * without doing either.
 */

#include "hw2.h"

int next_collatz_number(int n) {
if (n % 2 == 0) {
        return n / 2;
    } else {
        return 3 * n + 1;
    }
}

int count_collatz_steps(int n) {
int counter  = 0;
    while (n != 1) {
        n = next_collatz_number(n);
        counter++;
    }
    return counter;
}

int maximum(int *nums, int len) {
 if (len <= 0) {
        return -1; 
    }
    int maximum = nums[0]; 
    for (int i = 1; i < len; i++) {
        if (nums[i] > maximum) {
            maximum = nums[i]; 
        }
    }
    return maximum;
}

int sum_positive(int *nums, int len) {
int sum_of_positives = 0; 
    for (int i = 0; i < len; i++) {
        if (nums[i] > 0) {
            sum_of_positives += nums[i]; 
        }
    }
    return sum_of_positives;
}

int count_negative(int *nums, int len) {
int counter = 0;
    for (int i = 0; i < len; i++) {
        if (nums[i] < 0) {
            counter++;
        }
    }
    return counter;
}
