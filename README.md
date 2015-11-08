# collatz
This program determines the highest Collatz number from a to b where a,b are two positive integers. 

Consider the following operation on an arbitrary positive integer:

    If the number is even, divide it by two.
    If the number is odd, triple it and add one.

For instance, starting with n = 6, one gets the sequence 6, 3, 10, 5, 16, 8, 4, 2, 1.

n = 19, for example, takes longer to reach 1: 19, 58, 29, 88, 44, 22, 11, 34, 17, 52, 26, 13, 40, 20, 10, 5, 16, 8, 4, 2, 1.

# input

The input for this program is a .txt file of two ints, (a,b)

# output

The output is a list of the highest Collatz number from a to b, for each line in the input file.

# continuious integration

I used Travis CI to help me develop this program. 
