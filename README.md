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

# How to use :hammer_and_wrench:

Clone the repository
```bash
git clone git@github.com:Elshirak/skyscraper_puzzle.git
```
Compile the project, making object file "puzzle"
```bash
gcc *.c *.h -o puzzle
```
Run the program. Also you can change input variables.
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
If you input is incorrect or do not feets whith the rules
```bash
./puzzle "2 3 3 0 3 2 -1 3 2 12 3 1 2 3 2" "EO EO EEEEEEEO"
```
Result would be just
```bash
Error
```









