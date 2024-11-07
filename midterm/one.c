#include "midterm.h"

long long *fibonacci_numbers(size_t n) {
    if (n == 0) return NULL;
    	long long *fib = malloc(n * sizeof(long long));
    if (fib == NULL) return NULL;
    	fib[0] = 0;
    if (n > 1) {
        fib[1] = 1;
        for (size_t i = 2; i < n; i++) {
            fib[i] = fib[i-1] + fib[i-2];
        }
    }
    return fib;
}
