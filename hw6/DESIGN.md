# Homework 5: Design Document

  * author: Jason Waseq
  * date: November 23, 2024

## introduction

TODO: Write 5 functions that deal with strings, searching, and pointers. Also free up memory so that program has no memory leaks.

## function 1: score_letter:     

Purpose: Calculates the number of words in the vocabulary containing a given letter. This function iterates through the vocabulary and checks if each word contains the target letter.   

Pseudocode:   
Initialize a counter to 0.   
Loop through each word in the vocabulary:   
  If the word is not NULL and contains the letter:   
    Increment the counter.   
Return the counter.   

## function 2: score_word:   

Purpose: Computes the score of a word based on unique letter contributions. Each unique letter in the word contributes to the total score using a precomputed letter_scores array.     

Pseudocode:   
Initialize score to 0.   
Create a boolean array of size 26 to track seen letters.   
Loop through each letter in the word:   
  If the letter has not been seen:   
    Add its score from the `letter_scores` array to the total score.   
    Mark the letter as seen.   
Return the total score.   

## function 3: filter_vocabulary_gray:   

Purpose: Removes words containing a specified letter, corresponding to gray feedback in Wordle. Words with the letter are freed and their slots in the vocabulary array are set to NULL.   

Pseudocode:   
Initialize a counter for removed words to 0.    
Loop through each word in the vocabulary:   
  If the word is not NULL and contains the letter:   
    Free the word and set its slot to NULL.   
    Increment the counter.   
Return the counter.   

## function 4: filter_vocabulary_yellow:   

Purpose: Removes words that either do not contain the specified letter or have the letter in the given position, corresponding to yellow feedback.   

Pseudocode:    
Initialize a counter for removed words to 0.   
Loop through each word in the vocabulary:   
  If the word is not NULL:   
    Check if it fails the yellow feedback conditions:   
      - Does not contain the letter, or   
      - Contains the letter at the specified position.   
    If so, free the word and set its slot to NULL.   
    Increment the counter.   
Return the counter.   

## function 5: filter_vocabulary_green:    
Purpose: Removes words that do not have the specified letter in the given position, corresponding to green feedback.   

Pseudocode:   
Initialize a counter for removed words to 0.   
Loop through each word in the vocabulary:   
  If the word is not NULL and the letter at the specified position does not match:   
    Free the word and set its slot to NULL.   
    Increment the counter.   
Return the counter.    

## Memory Management Plan   
Memory is dynamically allocated for the vocabulary and individual words during the program execution. The plan ensures all memory is properly released:   
Freeing Filtered Words:   
In each filter_vocabulary_* function, words that no longer meet the criteria are freed, and their pointers are set to NULL to avoid dangling references.   
Final Cleanup:   
At the end of the program, the free_vocabulary function is called to free any remaining words and the vocabulary array itself.   
Temporary Allocations:   
Any temporary strings, such as those returned by get_guess, will be explicitly freed in the calling functions to prevent memory leaks.
