#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#define MAX_STACK_SIZE 100
#define MAX_EXPR_SIZE 100

//2017111866 황지욱
//본인은 이 소스파일을 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다.

int stack[MAX_STACK_SIZE];
char expr[MAX_EXPR_SIZE];
int top = -1;

typedef enum {
	lparen, rparen, plus, minus, times, divide, mod, eos, operand
} precedence;

int stackEmpty() {
	fprintf(stderr, "stack is empty, cannot delete elemnt\n");
	exit(EXIT_FAILURE);
	return 0;
}

int pop() {
	if (top == -1) {
		return stackEmpty();
	}
	return stack[top--];
}

void stackFull() {
	fprintf(stderr, "stack is full, cannot add elemnt\n");
	exit(EXIT_FAILURE);
}

void push(int item) {
	if (top >= MAX_STACK_SIZE - 1) {
		stackFull();
	}
	stack[++top] = item;
}

precedence getToken(char* symbol, int* n) {
	*symbol = expr[(*n)++];
	switch (*symbol) {
	case '(' :
		return lparen;
	case ')' :
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
	default :
		return operand;
	}
}

int eval() {
	precedence token;
	char symbol;
	int op1, op2;
	int n = 0;
	top = -1;
	token = getToken(&symbol, &n);
	while (token != eos) {
		if (token == operand) {
			push(symbol - '0');
		}
		else {
			op2 = pop();
			op1 = pop();
			switch (token) {
			case plus:
				push(op1 + op2);
				break;
			case minus:
				push(op1 - op2);
				break;
			case times:
				push(op1 * op2);
				break;
			case divide:
				push(op1 / op2);
				break;
			case mod:
				push(op1 % op2);
				break;
			}
		}
		token = getToken(&symbol, &n);
	}
	return pop();
}

int main() {
	int i = 0, n;
	FILE* input = fopen("c:\\input.txt", "r");
	printf("postfix expression : ");
	if (input != NULL) {
		while (!feof(input)) {
			fscanf_s(input, "%c", &expr[i]);
			printf("%c", expr[i]);
			i++;
		}
		fclose(input);
	}
	n = eval();
	printf("\nthe evaluation value : %d", n);
}
