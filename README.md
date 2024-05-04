# Push swap (42Berlin - 42Cursus) <img src="https://github.com/devicons/devicon/blob/master/icons/linux/linux-original.svg" title="Linux" alt="Linux Logo" width="50" height="60" align="right" /> <img src="https://github.com/devicons/devicon/blob/master/icons/c/c-original.svg" title="C" alt="C Logo" width="55" height="55" align="right" />&nbsp; 

This repository contains the implementation of the Pushswap algorithm using the Mechanical Turk approach. Pushswap is a sorting algorithm specifically designed for integer arrays. The Turk variant leverages the concept of outsourcing computational tasks to humans, mimicking the historical practice where a human chess player would make moves dictated by a "Turk" automaton.

## Introduction
Pushswap is a sorting algorithm that operates on two stacks, named `A` and `B`. The algorithm sorts the `A` stack in ascending order using a set of operations defined for stack manipulation. The Mechanical Turk version of Pushswap involves outsourcing the decision-making process of selecting optimal moves to human participants, who provide instructions based on the current state of the stacks.

## Usage
To utilize Pushswap Mechanical Turk, follow these steps:
1. Clone the repository to your local machine:
git clone https://github.com/VernihoraIvan/42BerlinPush_Swap.git
3. Navigate to the cloned directory:
4. Run the Pushswap algorithm that uses Turk algo to sort the stack:
./push_swap <integer_array>
4. Replace `<integer_array>` with the array you want to sort.

# First of all, I want to share the useful resources for this project :

1. You need to be familiar with the linked list structure.

https://www.youtube.com/watch?v=uBZHMkpsTfg&list=PLfqABt5AS4FmXeWuuNDS3XGENJO1VYGxl

2. The next step is to understand the concept of a working sorting algorithm.

https://medium.com/@ayogun/push-swap-c1f5d2d41e97

3. Then I highly recommend you to watch the video from Oceano about Push_Swap.

https://www.youtube.com/watch?v=OaG81sDEpVk&t=2945s

4. Also you need to know how to search the memory leaks in your program, for that test I used the Valgrind.

https://valgrind.org/docs/manual/mc-manual.html


# What we need to do here, shortly :

Sort a random list of integers using the smallest number of moves, 2 stacks, and a limited set of operations.
You start with two empty stacks: a and b. You are given a random list of integers via command line arguments. 

Only these moves are allowed:

sa : swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements).

sb : swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements).

ss : sa and sb at the same time.

pa : push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.

pb : push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.

ra : rotate a - shift up all elements of stack a by 1. The first element becomes the last one.

rb : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.

rr : ra and rb at the same time.

rra : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.

rrb : reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.

rrr : rra and rrb at the same time.

At the end, stack b must empty and all integers must be in stack a, sorted in ascending order. 
