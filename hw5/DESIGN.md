# Homework 5: Design Document

  * author: Jason Waseq
  * date: November 15, 2024

## introduction

TODO: Write 4 functions that deal with strings, searching, words, and I/O. 
Also free up memory so that program has no memory leaks.

## Function 1: score_guess
Purpose: Checks if the player's guess matches the secret word exactly.
The function also fills in the result string with a scoring format for each letter:   
'g': letter matches exactly in the correct position.   
'y': letter exists in the secret word but is in a different position.   
'x': letter does not appear in the secret word.   
Parameters:   
char *secret: The secret word chosen by the program.   
char *guess: The player's guessed word.   
char *result: Output string to store the scoring for each letter in the guess.   
Returns: true if the guess is an exact match with the secret word; otherwise, false.   

Pseudocode:   
for each character in guess:   
    if character matches secret in the same position:    
        set result to 'g'    
    else if character exists in secret but in a different position:    
        set result to 'y'    
    else:    
        set result to 'x'    
if all characters in result are 'g':    
    return true   
else:   
    return false   

## Function 2: valid_guess
Purpose: Checks if the player's guess is a valid word from the vocabulary list.   
Parameters:   
char *guess: The player's guess.   
char **vocabulary: The list of valid words.   
size_t num_words: Number of words in the vocabulary.   
Returns: true if the guess exists in the vocabulary, false otherwise.   

Pseudocode:   
for each word in vocabulary:   
    if word matches guess:   
        return true   
return false   

## Function 3: load_vocabulary
Purpose: Loads a list of 5-letter words from a file into memory, returning an array of strings (char**). 
It also sets the number of words read via *num_words.   
Parameters:   
char *filename: The file containing vocabulary words.   
size_t *num_words: Pointer to store the number of words loaded.   
Returns: char** containing vocabulary words, dynamically allocated.   

Pseudocode:   
open file for reading   
initialize an empty array of strings (char**)   
for each line in file:   
    read word   
    allocate memory for word   
    add word to array   
    increase num_words   
close file   
return array of words   

## Function 4: free_vocabulary
Purpose: Frees memory allocated for each word in the vocabulary and the vocabulary array itself.   
Parameters:   
char **vocabulary: Array of strings containing the vocabulary.   
size_t num_words: Number of words in the vocabulary.   

Pseudocode:   
for each word in vocabulary:   
    free(word)   
free(vocabulary)   

## Memory Management Plan
Load and Free Vocabulary:   
In load_vocabulary, each word is dynamically allocated with strdup. 
This requires that free_vocabulary frees each word individually before freeing the vocabulary array itself.   
Result String in score_guess:   
The result buffer in score_guess is passed from main, so no extra memory allocation is required inside the function.
