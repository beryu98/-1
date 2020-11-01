#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#define MAX_STACK_SIZE 100
#define MAX_EXPR_SIZE 100

//2017111866 황지욱
//본인은 이 소스파일을 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다.

typedef enum {
    lparen, rparen, plus, minus, times, divide, mod, eos, operand
} precedence;

precedence stack[MAX_STACK_SIZE];
char expr[MAX_EXPR_SIZE];
int top = -1;
int isp[] = { 0, 19, 12, 12 ,13, 13, 13, 0 };
int icp[] = { 20, 19, 12, 12, 13, 13, 13, 0 };
FILE* output;

precedence stackEmpty() {
    fprintf(stderr, "stack is empty, cannot delete elemnt\n");
    exit(EXIT_FAILURE);
}

precedence pop() {
    if (top == -1) {
        return stackEmpty();
    }
    return stack[top--];
}

void stackFull() {
    fprintf(stderr, "stack is full, cannot add elemnt\n");
    exit(EXIT_FAILURE);
}

void push(precedence item) {
    if (top >= MAX_STACK_SIZE - 1) {
        stackFull();
    }
    stack[++top] = item;
}

precedence getToken(char* symbol, int* n) {
    *symbol = expr[(*n)++];
    switch (*symbol) {
    case '(':
        return lparen;
    case ')':
        return rparen;
    case '+':
        return plus;
    case '-':
        return minus;
    case '/':
        return divide;
    case '*':
        return times;
    case '%':
        return mod;
    case '\0':
        return eos;
    default:
        return operand;
    }
}

void printToken(precedence token) {
    switch (token) {
    case plus:
        printf("+");
        fprintf(output, "+");
        break;
    case minus:
        printf("-");
        fprintf(output, "-");
        break;
    case divide:
        printf("/");
        fprintf(output, "/");
        break;
    case times:
        printf("*");
        fprintf(output, "*");
        break;
    case mod:
        printf("%%");
        fprintf(output, "%%");
        break;
    default:
        break;
    }
}



void postfix() {
    char symbol;
    precedence token;
    int n = 0;
    top = 0;
    stack[0] = eos;
    for (token = getToken(&symbol, &n); token != eos; token = getToken(&symbol, &n)) {
        if (token == operand) {
            printf("%c", symbol);
            fprintf(output, "%c", symbol);
        }
        else if (token == rparen) {
            while (stack[top] != lparen) {
                printToken(pop());
            }
            pop();
        }
        else {
            while (isp[stack[top]] >= icp[token]) {
                printToken(pop());
            }
            push(token);
        }
    }
    while ((token = pop()) != eos) {
        printToken(token);
    }
    printf("\n");
    fprintf(output, "\n");
}

int main() {
    int i = 0;
    FILE* input = fopen("c:\\input.txt", "r");
    output = fopen("c:\\output.txt", "w");

    printf("<<< infix to postfix >>>\n");
    printf("infix expression : ");
    if (input != NULL) {
        while (!feof(input)) {
            fscanf_s(input, "%c", &expr[i]);
            printf("%c", expr[i]);
            i++;
        }
        fclose(input);
    }
    printf("\npostfix expression : ");
    postfix();
    fclose(output);
}