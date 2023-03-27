#define _CRT_SECURE_NO_WARNINGS
//해시 -> 담에는 SHA_256사용해보자

#include <stdio.h>
#include <stdlib.h>

typedef int (*operation)(int, int);

int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }
int divide(int a, int b) { return a / b; }

int hash_operator(char op) {
    switch (op) {
    case '+': return 0;
    case '-': return 1;
    case '*': return 2;
    case '/': return 3;
    default: return -1;  // invalid operator
    }
}

int main() {
    char op;
    int operand1, operand2, result;
    operation operations[4] = { add, subtract, multiply, divide };

    printf("Enter: ");
    scanf("%d%c%d", &operand1,&op,&operand2);

    int operator_index = hash_operator(op);

    if (operator_index == -1 || operand2 == 0) {
        printf("error!\n");
        exit(1);
    }

    result = operations[operator_index](operand1, operand2);
    printf("Result: %d\n", result);
}