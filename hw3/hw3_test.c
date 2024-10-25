#include "hw3.h"

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void should_be_exactly_equal(const char *message, int expected, int actual) {
  printf("%s\n", message);
  printf("%s: wanted %d, got %d\n",
         (expected == actual) ? "SUCCESS" : "FAILURE", expected, actual);
}

void str_should_be_exactly_equal(const char *message, char *expected,
                                 char *actual) {
  printf("%s\n", message);
  printf("%s: wanted \"%s\", got \"%s\"\n",
         !strcmp(expected, actual) ? "SUCCESS" : "FAILURE", expected, actual);
}

bool approximately_equal(double a, double b) {
  // difference is less than 0.001?
  return fabs(a - b) < 0.001;
}

void should_be_equal(const char *message, double expected, double actual) {
  printf("%s\n", message);
  printf("%s: wanted %f, got %f\n",
         approximately_equal(expected, actual) ? "SUCCESS" : "FAILURE",
         expected, actual);
}

int count_negative_helper(int cumulative, int nextval) {
  return cumulative + ((nextval < 0) ? 1 : 0);
}

void test_str_suffix(char *haystack, char *needle, bool expected) {
  printf("haystack: %s\n", haystack);
  printf("needle  : %s\n", needle);
  bool result = str_suffix(haystack, needle);
  printf("%s: do we think it's a suffix? %s\n",
         (result == expected) ? "SUCCESS" : "FAILURE", result ? "yes" : "no");
}

int main(void) {
  int test_array_1[] = {100, 5, 3, -12, 109, -100};
  int test_array_2[] = {-55, 3, -12, 109, -100, 12, -12, 7000, 12};

  printf("**********************\n");
  printf("tests for str_suffix\n");
  test_str_suffix("", "", true);
  test_str_suffix("long string here", "", true);
  test_str_suffix("long string here", "here", true);
  test_str_suffix("", "something other than nothing", false);
  test_str_suffix("unrelated strings", "completely different", false);
  // new ones
  test_str_suffix("long string here", "string", false);
  test_str_suffix("long string here", "long string", false);

  printf("\n**********************\n");
  printf("tests for str_repeat\n");

  char *repeat_result = NULL;

  repeat_result = str_repeat("hello", 3);
  str_should_be_exactly_equal("repeat hello 3 times", "hellohellohello",
                              repeat_result);
  free(repeat_result);

  repeat_result = str_repeat("hello ", 5);
  str_should_be_exactly_equal("repeat \"hello \" 5 times",
                              "hello hello hello hello hello ", repeat_result);
  free(repeat_result);

  repeat_result = str_repeat("welcome to computer science", 0);
  str_should_be_exactly_equal("repeat \"welcome to computer science\" 0 times",
                              "", repeat_result);
  free(repeat_result);

  printf("\n**********************\n");
  printf("tests for str_is_palindrome\n");

  should_be_exactly_equal("str_is_palindrome: \"Sit on a potato pan, Otis\"",
                          true, str_is_palindrome("Sit on a potato pan, Otis"));

  should_be_exactly_equal("str_is_palindrome: \"Mr. Owl ate my metal worm\"",
                          true, str_is_palindrome("Mr. Owl ate my metal worm"));

  should_be_exactly_equal("str_is_palindrome: \"Mr. Owl ate my metal worms\"",
                          false,
                          str_is_palindrome("Mr. Owl ate my metal worms"));

  should_be_exactly_equal("str_is_palindrome: \"bob\"", true,
                          str_is_palindrome("bob"));

  should_be_exactly_equal("str_is_palindrome: \"bobby\"", false,
                          str_is_palindrome("bobby"));

  printf("\n**********************\n");
  printf("tests for dot_product\n");
  float vec1[] = {1.0, 0, 0};
  float vec2[] = {0, 0, 1.0};
  float vec3[] = {2.0, 2.0, 2.0};

  should_be_equal("dot_product of vec1 and vec2", 0.0,
                  dot_product(vec1, vec2, 3));
  should_be_equal("dot_product of vec1 and vec3", 2.0,
                  dot_product(vec1, vec3, 3));
  should_be_equal("dot_product of vec2 and vec3", 2.0,
                  dot_product(vec2, vec3, 3));
  should_be_equal("dot_product of vec3 and vec3", 12.0,
                  dot_product(vec3, vec3, 3));

  printf("\n**********************\n");
  printf("tests for reduce\n");
  should_be_exactly_equal("reduce with count_negative on test_array_1", 2,
                          reduce(test_array_1, 6, count_negative_helper, 0));
  should_be_exactly_equal("reduce with count_negative on test_array_2", 4,
                          reduce(test_array_2, 9, count_negative_helper, 0));

  printf("\n**********************\n");
  printf("tests for maximum_with_reduce\n");
  should_be_exactly_equal("maximum of test_array_1", 109,
                          maximum_with_reduce(test_array_1, 6));
  should_be_exactly_equal("maximum of test_array_2", 7000,
                          maximum_with_reduce(test_array_2, 9));

  printf("\n**********************\n");
  printf("tests for sum_positive_with_reduce\n");
  should_be_exactly_equal("sum_positive of test_array_1", 217,
                          sum_positive_with_reduce(test_array_1, 6));
  should_be_exactly_equal("sum_positive of test_array_2", 7136,
                          sum_positive_with_reduce(test_array_2, 9));

  return 0;
}
