/*
 * All of your code for hw3 goes in here. Your goal is to finish these
 * functions.
 */

#include "hw3.h"
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool str_suffix(char *haystack, char *needle) {
int haystack_len = 0;
int needle_len = 0;
    while (haystack[haystack_len] != '\0') {
        haystack_len++;
    }
    while (needle[needle_len] != '\0') {
        needle_len++;
    }
    if (needle_len > haystack_len) {
        return false;
    }
    for (int i = 0; i < needle_len; i++) {
        if (haystack[haystack_len - needle_len + i] != needle[i]) {
            return false; 
        }
    }
    return true;
}

char *str_repeat(char *s, int n) {
int len = strlen(s);
   if (n == 0 || len == 0) {
	char *out = malloc(1);
   if (out != NULL) {
	out[0] = '\0';
   }
	return out;
}
char *out = malloc(n * len + 1);
   if (out == NULL) {
	return NULL;
}
char *current_position = out;
   for (int i = 0; i < n; i++) {
	strcpy(current_position, s);
	current_position += len;
}
	out[n * len] = '\0';
    return out;
}

bool str_is_palindrome(char *s) {
int left = 0;
int right = strlen(s) - 1;
    while (left < right) {
        while (left < right && !((s[left] >= 'a' && s[left] <= 'z') || (s[left] >= 'A' && s[left] <= 'Z'))) {
            left++;
        }
        while (left < right && !((s[right] >= 'a' && s[right] <= 'z') || (s[right] >= 'A' && s[right] <= 'Z'))) {
            right--;
        }
        char left_char = (s[left] >= 'A' && s[left] <= 'Z') ? (s[left] + ('a' - 'A')) : s[left];
        char right_char = (s[right] >= 'A' && s[right] <= 'Z') ? (s[right] + ('a' - 'A')) : s[right];
        if (left_char != right_char) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

float dot_product(float *vec_a, float *vec_b, int length) {
float out = 0.0;  
    for (int i = 0; i < length; i++) {
        out += vec_a[i] * vec_b[i];
    }

    return out;
}

int reduce(int *nums, int length, int (*f)(int, int), int initial) {
 int out = initial; 
    for (int i = 0; i < length; i++) {
        out = f(out, nums[i]);  
    }

    return out; ;
}

// These two functions will end up as a *single call to reduce*, but you'll have
// to write a new helper function for each of them. Those helper functions will
// be quite short though!

int maximum_helper(int current_max, int next_num) {
    if (next_num > current_max) {
        return next_num; 
    } else {
        return current_max;
    }
}

int maximum_with_reduce(int *nums, int length) {
    return reduce(nums, length, maximum_helper, nums[0]);
}

int sum_positive_helper(int current_sum, int next_num) {
if (next_num > 0) {
     return current_sum + next_num;
    } else {
        return current_sum; 
    }
}

int sum_positive_with_reduce(int *nums, int length) {
    return reduce(nums, length, sum_positive_helper, 0);
}
