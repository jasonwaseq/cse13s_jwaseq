# Homework 1: Design Document

  * author: Jason Waseq

  * date: October 9, 2024

## introduction

In this homework, I will do the thing and solve important computer science
problems and probably win a Turing Award for doing so.

TODO(Jason): Structure different C programs across multiple files. Create 5 different functions, 
a function called area_of_disk which takes the radius of a disk, and returns its area, 
using A = Pi * r2, a function called area_of_ring which is given the outer radius of a disk 
and the inner radius of the hole in the disk and returns the
area of that disk, a function called bigger_minus_smaller
which figures out which of the two given numbers is greater and then
returns the greater number minus the lesser number, a function called
value_in_range which is given three numbers (a lower bound, a specific value, and an
upper bound) which returns true if the value is in the range
and false otherwise, a function called
sum_of_greater_squares which given three numbers a, b, and c, returns the sum of the
two greatest squares. In addition creating a program called caat.c. that will take in each
character from stdin one at a time using getchar() and output every
character to stdout using putchar(), but for any
vowel (aeiouAEIOU), outputs that character twice. 

## function 1: area_of_disk

Use the formula for the area of a circle: A = Pi * r2, Pi would be represented with the constant M_PI, 
which is defined in <math.h>. To square the radius, I would just multiply the radius by itself.

## function 2: area_of_ring

Use the formula for the area of a ring A = Pi * (Outer Radius - Inner Radius).
I would set a variable for Outer Radius - Inner radius.

## function 3: bigger_minus_smaller

Use an if statement that compares whether the first number is greater than the second number 
and if true returns the first number minus the second number 
and if false returns the second number minus the first number.

## function 4: value_in_range

Check if the specific value is greater than equal to the lower bound and less than equal to the upper bound then it will return true. 
If not, it will return a statement indicating the value was not in range.

## function 5: sum_of_greater_squares

Multiply each number by itself to to get its square, use if statement to see if first square is less than equal to second square 
and third square and if true return the second square plus the third square, 
and if false see if second square is less than equal to first square and third square 
and if true return first square plus third square and if false return the first square plus the second square.

## the caat program

Use getchar() to read in each character one at a time. Check if each character is equal to any vowel, 
and if true output that character twice, and if false just output it once.
