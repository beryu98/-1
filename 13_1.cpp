#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100
#define MAX_EXPR_SIZE 100

//2017111866 황지욱
//본인은 이 소스파일을 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다.

typedef struct node* treePointer;
typedef struct node {
	char data;
	treePointer leftChild, rightChild;
}node;
treePointer root;

treePointer stack[MAX_STACK_SIZE];
char expr[MAX_EXPR_SIZE];
int top = -1;

typedef enum {
	lparen, rparen, plus, minus, times, divide, mod, eos, operand
} precedence;

#define MALLOC(p,s) \
	if(!((p) = (treePointer) malloc(s))) {\
		fprintf(stderr, "insufficient memory");\
		exit (EXIT_FAILURE);\
	}

treePointer createNode(char data) {
	treePointer temp;
	MALLOC(temp, sizeof(*temp));
	temp->data = data;
	temp->leftChild = NULL;
	temp->rightChild = NULL;

	return temp;
}

treePointer stackEmpty() {
	fprintf(stderr, "stack is empty, cannot delete elemnt\n");
	exit(EXIT_FAILURE);
	return 0;
}

treePointer pop() {
	if (top == -1) {
		return stackEmpty();
	}
	return stack[top--];
}

void stackFull() {
	fprintf(stderr, "stack is full, cannot add elemnt\n");
	exit(EXIT_FAILURE);
}

void push(treePointer item) {
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

treePointer createBinTree() {
	precedence token;
	char symbol;
	treePointer item, op1, op2;
	int n = 0;
	top = -1;
	token = getToken(&symbol, &n);
	while (token != eos) {
		if (token == operand) {
			item = createNode(symbol);
			push(item);
		}
		else {
			item = createNode(symbol);
			op1 = pop();
			op2 = pop();
			item->rightChild = op1;
			item->leftChild = op2;
			push(item);
		}
		token = getToken(&symbol, &n);
	}
	return pop();
}

void inorder(treePointer ptr) {
	if (ptr) {
		inorder(ptr->leftChild);
		printf("%c", ptr->data);
		inorder(ptr->rightChild);
	}
}

void preorder(treePointer ptr) {
	if (ptr) {
		printf("%c", ptr->data);
		preorder(ptr->leftChild);
		preorder(ptr->rightChild);
	}
}

void postorder(treePointer ptr) {
	if (ptr) {
		postorder(ptr->leftChild);
		postorder(ptr->rightChild);
		printf("%c", ptr->data);
	}
}

void Free(treePointer* root) {
	if (*root) {
		Free((&(*root)->leftChild));
		Free((&(*root)->rightChild));
		free(*root);
	}
}

int main() {
	int i = 0;
	FILE* input = fopen("input.txt", "r");

	printf("the length of input string should be less than 80\n");
	printf("input string <postfix expression> : ");

	if (input != NULL) {
		while (!feof(input)) {
			fscanf_s(input, "%c", &expr[i]);
			printf("%c", expr[i]);
			i++;
		}
		fclose(input);
	}
	root = createBinTree();
	
	printf("\ncreating its binary tree\n\n");

	printf("\ninorder traversal : ");
	inorder(root);

	printf("\npreorder traversal : ");
	preorder(root);

	printf("\npostorder traversal : ");
	postorder(root);

	Free(&root);
}
