#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100

//2017111866 황지욱
//본인은 이 소스파일을 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다.

typedef enum {
	lparen, rparen, Plus, subtract, multiply, division, eos, operand
} precedence;

typedef struct tree* treePointer;
typedef struct tree {
	char data;
	treePointer left, right, next;
}tree;

typedef struct p {
	char data, LR, next, lv;
}p;

#define MALLOC(p,s) \
	if(!((p) = (treePointer) malloc(s))) {\
		fprintf(stderr, "insufficient memory");\
		exit (EXIT_FAILURE);\
	}
treePointer Tree;

int isp[] = { 0, 19, 12, 12, 13, 13, 10, 0 };//수정
int icp[] = { 20, 19, 12, 12, 13, 13, 10, 0 };//수정
void postfix(void);
precedence getToken(char* symbol, int* n, char* arr);
void printToken(precedence);

precedence stack[MAX_STACK_SIZE];
int top = -1;
void push(precedence item);
void stackFull();
precedence pop();
precedence stackEmpty();
void treep(char symbol);
void treemake(void);
void treepush(char symbol);
char expr[81];
char post[81];
int num = 0;
void treeprint(treePointer t);
FILE* fpI;
p prin[80];
int lv = 1;

int main(int argc, char *argv[]) {
	int ch = 1;

	if (argc == 1) {
		fprintf(stderr, "error");
	}

	else {
		if (!(fpI = fopen(*++argv, "r"))) {
			fprintf(stderr, "cannot open the file");
			exit(EXIT_FAILURE);
		}

		fgets(expr, 80, fpI);
		printf("<<<<<<<<<< infix to postfix >>>>>>>>>>>>>\n");
		printf("infix expression\t: %s\n", expr);
		postfix();
		printf("postfix expression\t: %s\n", post);

		fclose(fpI);

		treemake();
		num = 0;
		treeprint(Tree);

		printf("(ROOT, %c)\n", Tree->data);
		while (lv != ch) {
			for (int i = 0; i < num; i++) {
				if (prin[i].lv == ch)
					printf("(%c, %c, %c) ", prin[i].data, prin[i].LR, prin[i].next);
			}
			printf("\n");
			ch++;
		}
		return 0;
	}
}

void treemake(void) {
	char symbol;
	precedence token;
	int n = 0;

	for (token = getToken(&symbol, &n, post); token != eos; token = getToken(&symbol, &n, post)) {
		if (token == operand) {
			treep(symbol);
		}
		else {
			if (isp[Tree->data] <= icp[token])
				treepush(symbol);
		}
	}
}

void treeprint(treePointer t) {
	if (t->left != NULL && t->right != NULL) {
		p temp;

		temp.data = t->data;
		temp.LR = 'L';
		temp.lv = lv;
		temp.next = t->left->data;
		prin[num++] = temp;
		temp.LR = 'R';
		temp.next = t->right->data;
		prin[num++] = temp;

		++lv;
		treeprint(t->left);
		treeprint(t->right);
	}
}

void treep(char symbol) {
	treePointer temp;
	MALLOC(temp, sizeof(*temp));
	temp->data = symbol;
	temp->next = NULL;
	temp->left = NULL;
	temp->right = NULL;
	if (Tree == NULL)
		Tree = temp;
	else {
		temp->next = Tree;
		Tree = temp;
	}
}

void treepush(char symbol) {
	treePointer temp, t, left, right;
	t = Tree;
	MALLOC(right, sizeof(*right));
	right->data = t->data;
	right->left = t->left;
	right->right = t->right;
	right->next = t->next;
	
	t = t->next;
	MALLOC(left, sizeof(*left));
	left->data = t->data;
	left->left = t->left;
	left->right = t->right;
	left->next = t->next;

	t = t->next;
	MALLOC(temp, sizeof(*temp));
	temp->data = symbol;
	temp->left = left;
	temp->right = right;
	temp->next = t;

	Tree = temp;
}

void postfix(void) {
	char symbol;
	precedence token;
	int n = 0;
	top = -1;
	stack[++top] = eos;

	for (token = getToken(&symbol, &n, expr); token != eos; token = getToken(&symbol, &n, expr)) {
		if (token == operand) {
			post[num++] = symbol;
		}
		else if (token == rparen) {
			while (stack[top] != lparen)
				printToken(pop());
			pop();
		}
		else {
			while (isp[stack[top]] >= icp[token])
				printToken(pop());
			push(token);
		}
	}

	while ((token = pop()) != eos)
		printToken(token);
}

precedence getToken(char* symbol, int* n, char* arr) {
	*symbol = arr[(*n)++];
	switch (*symbol) {
	case '(': return lparen;
	case ')':  return rparen;
	case '+': return Plus;
	case '-': return subtract;
	case '*': return multiply;
	case '/': return division;
	case '\0': return eos;
	default: return operand;
	}
}

void printToken(precedence pre) {
	switch (pre) {
	case Plus:	post[num++] = '+';	break;
	case subtract:	post[num++] = '-';	break;
	case multiply:	post[num++] = '*';	break;
	case division:	post[num++] = '/';	break;
	default:;
	}
}

precedence pop() {
	if (top == -1)
		return stackEmpty();
	return stack[top--];
}

precedence stackEmpty() {
	precedence item;
	item = operand;
	return item;
}

void push(precedence item) {
	if (top >= MAX_STACK_SIZE - 1)
		stackFull();
	stack[++top] = item;
}

void stackFull() {
	precedence item;
	fprintf(stderr, "stack is full, cannot add int\n");
	exit(EXIT_FAILURE);
}