#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100

//2017111866 황지욱
//본인은 이 소스파일을 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다.

typedef struct node* treePointer;
typedef struct node
{
	char data;
	treePointer leftChild, rightChild;
}node;
treePointer root = NULL;

#define MALLOC(p,s) \
	if(!((p) = (treePointer) malloc(s))) {\
		fprintf(stderr, "insufficient memory");\
		exit (EXIT_FAILURE);\
	}
typedef enum {
	lparen, rparen, logicand, logicor, logicnot, eos, operand
} precedence;

treePointer stack[MAX_STACK_SIZE];
int top = -1;
void push(treePointer item);
void stackFull();
treePointer pop();
treePointer stackEmpty();
treePointer createNode(char item);
void Free(treePointer* root);
char expr[81];
precedence getToken(char* symbol, int* n);
treePointer createBinTree();
void inorder(treePointer ptr);

int main(void)
{
	int result;
	FILE* fp;

	if ((fp = fopen("input.txt", "r")) == NULL){
		fprintf(stderr, "cannot open the file");
		exit(EXIT_FAILURE);
	}
	fgets(expr, 80, fp);
	fclose(fp);
	printf("input string (postfix expression) : %s\n", expr);

	printf("creating its binary tree\n");
	root = createBinTree();

	printf("%-20s : ", "inorder traversal");
	inorder(root);
	printf("\n");

	Free(&root);
}

treePointer createBinTree() {
	precedence token;
	char symbol;
	treePointer pNode, op1, op2;
	int n = 0;
	top = -1;
	token = getToken(&symbol, &n);
	while (token != eos) {
		if (token == operand) {
			pNode = createNode(symbol);
			push(pNode);
		}
		else {
			pNode = createNode(symbol);
			if (token == logicnot) {
				op1 = pop();
				pNode->rightChild = op1;
			}
			else {
				op1 = pop();
				op2 = pop();
				pNode->rightChild = op1;
				pNode->leftChild = op2;
			}
			push(pNode);
		}
		token = getToken(&symbol, &n);
	}
	return pop();
}

precedence getToken(char* symbol, int* n) {
	*symbol = expr[(*n)++];
	switch (*symbol) {
	case '(': return lparen;
	case ')':  return rparen;
	case '&': return logicand;
	case '|': return logicor;
	case '~': return logicnot;
	case '\0': return eos;
	default: return operand;
	}
}

void inorder(treePointer ptr){
	if (ptr)	{
		inorder(ptr->leftChild);
		printf("%c", ptr->data);
		inorder(ptr->rightChild);
	}
}

treePointer pop(){
	if (top == -1)
		return stackEmpty();\
	return stack[top--];
}

treePointer stackEmpty(){
	treePointer item;
	item = NULL;
	return item;
}

void push(treePointer item){
	if (top >= MAX_STACK_SIZE - 1)
		stackFull();
	stack[++top] = item;
}

void stackFull(){
	fprintf(stderr, "stack is full, cannot add item\n");
	exit(EXIT_FAILURE);
}

treePointer createNode(char data) {
	treePointer temp;
	MALLOC(temp, sizeof(*temp));
	temp->data = data;
	temp->leftChild = NULL;
	temp->rightChild = NULL;

	return temp;
}

void Free(treePointer* root) {
	if (*root) {
		Free((&(*root)->leftChild));
		Free((&(*root)->rightChild));
		free(*root);
	}
}