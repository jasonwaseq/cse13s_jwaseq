# Homework 2: Design Document

  * author: Jason Waseq
  * date: October 16, 2024

## introduction

TODO: Write 5 functions that deal with numbers and arrays of numbers
and write a calculator program, which reads its input from a file.

## function 1: computing the next Collatz number

Compute the next Collatz number for a given input number by doing half the input number,if that number is even, or (3 times the number) + 1, if that number is odd. 
So if the number is divisible by 2 with no remainders, it is even and its half can be returned or else return (3 times number) + 1.

## function 2: counting Collatz steps to convergence

Repeatedly compute the next Collatz number, until you reach a value of 1. 
I will do an iterative approach that repeatedly computes the next Collatz number in a while loop that sets the 
returned number from the next Collatz number function to the input number until the input number==1, using a counter to count each step.
Return the counter.

## function 3: finding the maximum element of an array

Take an array of ints and its length, and return the maximum element of that array. 
Have a variable defined as the maximum dedicated to the first element of the array and then go through the array starting from the second element, 
comparing each one to the current maximum. If the array element is larger than the variable defined as the maximum then the variable is replaced with that array element.
Return the variable. 

## function 4: summing all of the positive elements of an array

Take an array of ints and its length, and return the sum of all of the elements of that array that are positive. 
A positive number variable is initialized to 0, and the function loops through the array, checking if each element is greater than 0. 
If it is, the element is positive and it is added to the positive number variable. Return the positive number variable after going through the entire array.r 

## function 5: counting the negative numbers in an array

Count up the number of negative elements in the given array. A counter is initialized to 0, and the function loops through the array, 
checking if each element is less than 0. If it is then the element is negative, and it adds 1 to the counter.

## the calculator program

The first line of the file contains the first number, and using strtol(), the string is converted to long and is stored in a running number variable. 
The second line is an arithmetic operator and it is stored in an operator variable. The third line is a number, 
and the program combines it with the running number variable using the previously stored operator. 
However, if there is a division sign, then it will check if the number read after the division sign is a 0, and if it's true then it prints ERROR and breaks. 
If not, then it prints the running number variable after going through all the lines in the file. 
If there are more lines of the file, then they are alternatingly operators and numbers, 
the running number is updated by combining it with the number that was just read from the file using the arithmetic operator that was before the number that was just read.
