#define _CRT_SECURE_NO_WARNINGS
//파싱

#include <stdio.h>
#include <ctype.h>

int main() {
    char c;
    int num = 0, result = 0;
    char op = '+';

    while ((c = getchar()) != '\n') {
        if (isdigit(c)) {
            //문자열을 숫자로 바꾸기
            num = num * 10 + (c - '0');
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/') {
            switch (op) {
            case '+':
                result += num;
                break;
            case '-':
                result -= num;
                break;
            case '*':
                result *= num;
                break;
            case '/':
                result /= num;
                break;
            }
            num = 0;
            op = c;
        }
    }

    switch (op) {
    case '+':
        result += num;
        break;
    case '-':
        result -= num;
        break;
    case '*':
        result *= num;
        break;
    case '/':
        result /= num;
        break;
    }

    printf("%d\n", result);
    return 0;
}
