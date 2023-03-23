#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    return a / b;
}

int main() {
    int a, b;
    char op;
    int result;

    // 연산자와 함수를 매핑하는 배열
    int (*operations[])(int, int) = { add, subtract, multiply, divide };
    char operators[] = { '+', '-', '*', '/' };

    printf("Enter an expression: ");
    scanf("%d %c %d", &a, &op, &b);

    // 연산자에 대응하는 함수를 배열에서 찾아서 실행
    for (int i = 0; i < sizeof(operators); i++) {
        if (op == operators[i]) {
            result = (*operations[i])(a, b);
            printf("%d %c %d = %d\n", a, op, b, result);
            return 0;
        }
    }

    printf("Invalid operator\n");
    return 1;
}