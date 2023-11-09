# Simple VM

## Overview
- The stack is initialized as an array of 256 ints
- A stack pointer is created to maintain the index of the top item (it's not actually a pointer)
- Instructions, which are stored as 32bit integers, are procedurally executed one by one

## Instructions
1. (PUSH x) Pushes an item onto the stack and increments the stack pointer.
2. (POP) Decrements the stack pointer, no need to remove the item.
3. (ADD) Removes the top two values from the stack, and pushes their sum onto the stack.
4. (MUL) Removes the top two values from the stack, and pushes their product onto the stack.
5. (OUT) Prints the top item of the stack to standard output.
6. (COUT) Prints the top item of the stack to standard output, as a char.
7. (HALT) Completely terminates the VM.
8. (JMP x) Jumps to a chosen instruction in the program, instructions are indexed from 1.
9. (JMPT x) Jumps to a chosen instruction in the program if the top item of the stack is equal to 1(true).
