
# Monty language interpreter

## What is Monty?
Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. 
## Aim of this project
The goal of this project is to understand how stacks actually works in the process of creating an interpreter for Monty ByteCodes files.

### The following is the way that our program is compiled:
```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o monty
```

### How to use
- Clone our directory to your working space:
```bash
git clone https://github.com/Nachop51/monty.git
```
- Compile our Monty interpreter with: 
```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o monty
```
- Create the desired Monty bytecode file

- Execute the Monty interpreter with your filename as argument
```bash
./monty <path of your filename>
```
    
## Implemented commands

| Command            | Description                                                                                 |
| ----------------- | ---------------------------------------------------------------------------------------------|
| push | Pushes an element to the stack. Usage: push <int>                                                         |
| pall | Prints all the values on the stack, starting from the top of the stack. Usage: pall                       |
| pint | Prints the value at the top of the stack. Usage: pint                                                     |
| pop  | Removes the top element of the stack.                                                                     |
| swap | Swaps the top two elements of the stack.                                                                  |
| add  | Adds the top two elements of the stack.                                                                   |
| nop  | Doesn’t do anything.                                                                                      |
| sub  | Subtracts the top element of the stack from the second top element of the stack.                          |
| div  | Divides the second top element of the stack by the top element of the stack.                              |
| mul  | Multiplies the second top element of the stack with the top element of the stack.                         |
| mod  | Computes the rest of the division of the second top element of the stack by the top element of the stack. |
| #    | When '#' is the first character, it allows the user to comment the line.                                  |
| pchar| Prints the char at the top of the stack.                                                                  |
| pstr | Prints the string starting at the top of the stack.                                                       | 
| rotl | Rotates the stack to the top.                                                                             |
| rotr | Rotates the stack to the bottom.                                                                          |
| stack| Sets the format of the data to a stack (LIFO).                                                            |
| queue| Sets the format of the data to a queue (FIFO).                                                            |


### Authors

[Matías Martínez](https://github.com/MatiasMtz) & [Nacho Peralta](https://github.com/Nachop51) from Holberton School cohorte #17.


