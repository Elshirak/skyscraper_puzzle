# Skyskraper puzzle :jigsaw:

  This is one of projects in [Escole 42](https://www.42network.org/), full subject you can see in repo. Also, [here](https://www.puzzle-skyscrapers.com/)(4x4 Skyscrapers)
you can play to understand the rules.
  It represents a logic puzzle, the goal is to place skyscrapers in all grid cells in accordance with the rules:

- The height of skyscrapers is from 1 to grid size, i.e. 1 to 4 for 4x4 puzzles.
- You cannot place two skyscrapers of the same height in the same row or column.
- The numbers on the sides of the grid show how many skyscrapers you will see if look in the direction of the arrow. The absence of a number or zero means that for
there is no guidance for this direction.

For example, a simple 4x4 option:

```
     2   2   1   3
  -+---+---+---+---+-
3  |   |   |   |   |  2
  -+---+---+---+---+-
1  |   |   |   |   |  2
  -+---+---+---+---+-
2  |   |   |   |   |  3
  -+---+---+---+---+-
3  |   |   |   |   |  1
  -+---+---+---+---+-
     3   2   2   1
```

The result of solving the puzzle:

```
     2   2   1   3
  -+---+---+---+---+-
3  | 1 | 3 | 4 | 2 |  2
  -+---+---+---+---+-
1  | 4 | 2 | 1 | 3 |  2
  -+---+---+---+---+-
2  | 3 | 4 | 2 | 1 |  3
  -+---+---+---+---+-
3  | 2 | 1 | 3 | 4 |  1
  -+---+---+---+---+-
     3   2   2   1
```
***

# Implementation :mechanic:
First of all, the task was to create a program that **solves the following problem:**

- Given a map of 4x4, place boxes of height 1 to 4 on each available square in a way that every row and column sees the correct number of boxes from each the possible points of view (left/right for rows, up/down for columns).
- Each of the views (2 per row and 2 per column) will have a given value. Your program must place the boxes correctly, while making sure each row and column only has one box of each size.
- Your output will contain the first solution you encounter
- Here’s how we’ll launch your program : 
```bash
> ./puzzle "col1up col2up col3up col4up col1down col2down col3down col4down row1left row2left
row3left row4left row1right row2right row3right row4right"
```
"col1up" is the value for the left column upper point of view. Each of these represent a characters string of values ranged between ’1’ and ’4’. This is the ONLY acceptable input for your program. Any other input must be considered an error. Here’s an example of intended input/output for a valid set.
```bash
./puzzle "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2" | cat -e
1 2 3 4$
2 3 4 1$
3 4 1 2$
4 1 2 3$
```
In case of error or if you can’t find any solutions, display "Error" followed by a line break.

I'm allowed to use only _malloc_ and _print_ library functions. Also, I had a **requirements on code style** written [here](https://github.com/42School/norminette/blob/master/pdf/en.norm.pdf). There are some of them:
- Each function must be maximum 25 lines
- Each line must be at most 80 columns wide, one instruction per line

- A function can take 4 named parameters maximum
- You can’t declare more than 5 variables per function
- You cannot have more than 5 function-definitions in a .c file

- All includes must be at the beginning of the file, you cannot include a C file.
- Header files must be protected from double inclusions. 

This rules had huge effect on implementation itself. 
I decompose problem on subtasks:
1) Parse input values
2) Chek if they fit the conditions, otherwise throw an error
3) Initialize a matrix 6x6 and fill it with 0
4) Get non-repeatable strings four symbols each('1', '2', '3', '4'), there are only 4! = 24 different combinations for my task 
5) Pass a massive of strings to a recursive solver-function. It will return a filled matrix
6) Check is returned board the right answer. Yes -> print | No -> Continue solving
7) Print result matrix or if there is no solution -> print Error

GCC, Vim
***

# How to use :hammer_and_wrench:

Clone the repository
```bash
git clone git@github.com:Elshirak/skyscraper_puzzle.git
```
Compile the project, making object file "puzzle"
```bash
gcc *.c *.h -Wall -Wextra -Werror -o puzzle
```
Run the program
```bash
./puzzle "2 3 3 1 3 2 1 3 2 1 2 3 1 2 3 2"
```
The result should be
```bash
3 1 2 4
4 2 1 3
2 4 3 1
1 3 4 2
```
If you enter incorrect input data like this
```bash
./puzzle "2 0 3 4 7 2 13 2 1 -1 1 2 3 2" "EO...EO...EEEEEEEEEEEEEEEO"
```
The result will be
```bash
Error
```







