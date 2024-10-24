# Homework 3: Design Document

  * author: Jason Waseq

  * date: October 23, 2024

## introduction

TODO: Write 7 functions that deal with strings, arrays, and function pointers.

## function 1: strings: is one string a suffix of the other?

Do an iterative approach by comparing characters from the end of both strings. First check if the length of needle is greater than haystack, returning false if it is.
If needle is shorter or equal in length, it compares characters from the end of both strings moving backwards. If all characters match, the function returns true, and false if not a match.

## function 2: strings: repeat a string n times

First calculate the length of the input string and allocate memory to store the specified repetitions of the string plus a null terminator. 
Use a loop to copy the string into the allocated memory the specified amount of times and add a null terminator at the end then return the finalized constructed string. 
If the user called str_repeat("hello", 3), I would  allocate 5 characters 3 times plus a null terminator so a total of 16 bytes of memory need to be allocated.

## function 3: strings: is this string a palindrome?

Using two pointers, one starting at the beginning of the string and the other at the end. 
It compares the characters at these 2 positions, ignoring non-letter characters and treating capital letters as lowercase. 
If all the characters match as the pointers move towards the center, the string is a palindrome; otherwise, it's false.

## function 4: arrays: compute the dot product of two arrays

Go through each corresponding pair of elements from both arrays, multiplying them together, and adding the sum of these products to a total count. 
The final result is returned as the dot product.

## function 5: reduce

Reduce will look like int reduce(int *nums, int len, int (*f)(int,int), int initial). 
initial is the initial value of the cumulative value, and f is a pointer to a function that takes two ints and returns an int -- the new value for the cumulative function.

## function 6: finding the maximum element of an array with reduce

Find the max value in an array of integers by using a helper function that returns the greater of two integers. 
It first initializes the max value with the first element of the array, then compares each element using the helper function, updating the max value when needed. 
A good initial cumulative value would be 0.

## function 7: summing all of the positive elements of an array with reduce

Calculate the sum of all positive integers in an array by using a helper function which returns the sum of two integers if both are positive, otherwise, it returns the positive integer or zero. 
The main function goes through the array, applying the helper function to sum up the total sum of positive values.


