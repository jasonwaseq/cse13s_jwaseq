// A nice place for you to mess with the functions, while you're developing.

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "search_util.h"

int main(void) {
  char words[10][6] = {"stalk", "scrap", "shear", "batch", "motif",
                       "tense", "ultra", "vital", "ether", "nadir"};

  // make a dynamically-allocated vocabulary that you can mess with, including
  // freeing elements of it when necessary.
  char **vocabulary = calloc(10, sizeof(char *));
  for (int i = 0; i < 10; i++) {
    vocabulary[i] = strdup(words[i]);
  }
  size_t num_words = 10;

  // TODO(you): exercise all of your functions in here. Write some good test
  // cases!
 // Test score_letter
  printf("Score for letter 'a': %d\n", score_letter('a', vocabulary, num_words));

  // Test score_word
  int letter_scores[26] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
  printf("Score for word 'apple': %d\n", score_word("apple", letter_scores));

  // Test filter_vocabulary_gray
  printf("Words removed for gray filter on 'a': %lu\n",
         filter_vocabulary_gray('a', vocabulary, num_words));

  // Test filter_vocabulary_yellow
  printf("Words removed for yellow filter on 'e' at position 4: %lu\n",
         filter_vocabulary_yellow('e', 4, vocabulary, num_words));

  // Test filter_vocabulary_green
  printf("Words removed for green filter on 'p' at position 1: %lu\n",
         filter_vocabulary_green('p', 1, vocabulary, num_words));

  // ... OK we're done, clean up the vocabulary.
  free_vocabulary(vocabulary, num_words);

  return 0;
}
