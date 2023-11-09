#include <stdio.h>
#include <stdbool.h>

int ip = 0;
int sp = -1;
bool running = true;

int stack[256];

typedef enum {
    PUSH,
    POP,
    ADD,
    MUL,
    OUT,
    HALT,
    JMP,
    JMPT,
} InstructionSet;

// program goes here 
const int program[] = {
    PUSH, 1, 
    OUT,
    JMPT, 1,
};

int fetch() {
    return program[ip];
}

int eval(int instruction) {
    switch (instruction) {
        case HALT : {
            running = false;
            break;
        }
        case PUSH : {
            sp++;
            stack[sp] = program[++ip];
            break;
        }
        case POP : {
            sp--;
            break;
        }
        case OUT : {
            printf("%d\n", stack[sp]); 
            break;
        }
        case ADD : {
            int a = stack[sp--];
            int b = stack[sp--];

            int sum = a + b;

            sp++;
            stack[sp] = sum;
            break;
        }
        case MUL : {
            int a = stack[sp--];
            int b = stack[sp--];

            int product = a * b;

            sp++;
            stack[sp] = product;
            break;
        }
        case JMP : {
            ip = program[++ip];
            break;
        }
        case JMPT : {
            if (stack[sp] == 1) {
                ip = program[++ip];
            }
            break;
        }
    }    
}

int main() {
    while (running) {
        eval(fetch());
        ip++;
    }

    return 0;
}