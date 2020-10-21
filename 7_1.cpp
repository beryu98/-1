#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
#define MAX_SACK_SZIE 5
#define MAX_NAME_SZIE 10

//2017111866 황지욱
//본인은 이 소스파일을 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다.

typedef struct {
	int id;
	char name[MAX_NAME_SZIE];
}element;

element stack[MAX_SACK_SZIE];
int top = -1;

element stackEmpty() {
	element s;
	fprintf(stderr, "stack is empty, cannot delete elemnt\n");
	exit(EXIT_FAILURE);
	
	return s;
}

element pop() {
	if (top == -1) {
		return stackEmpty();
	}
	return stack[top--];
}

void stackFull() {
	element s;

	fprintf(stderr, "stack is full, cannot add elemnt\n");
	fprintf(stderr, "current stack elemnets :\n");
	while (top > -1) {
		s = pop();
		printf("%d %s\n", s.id, s.name);
	}
	exit(EXIT_FAILURE);
}

void push(element item) {
	if (top >= MAX_SACK_SZIE - 1) {
		stackFull();
	}
	stack[++top] = item;
}


int main() {
	char st[30];
	char* s;
	char* c;
	element item;

	printf("<< stack operations where MAX_SACK_SZIE is 5\n");
	printf("push 1 Jung\n");
	printf("pop\n");
	printf("\n****************************************\n");

	while (1) {
		gets_s(st);
		s = strtok_s(st, " ", &c);

		if (strcmp(s, "push") == 0) {
			s = strtok_s(NULL, " ", &c);
			item.id = atoi(s);
			s = strtok_s(NULL, " ", &c);
			strcpy(item.name, s);
			push(item);
		}
		else if (strcmp(s, "pop") == 0) {
			pop();
		}
		else if (strcmp(s, "stop")) {
			break;
		}
		else {
			printf("wrong commnad! try again!\n");
		}
	}
}