#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define TRUE 1
#define FALSE 0
#define MAX_STACK_SIZE 100
#define MAX 10

//2017111866 황지욱
//본인은 이 소스파일을 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다.

typedef enum {
	logicnot, logicand, logicor, tru, fals
} logical;

typedef struct node* treePointer;
typedef struct node{
	treePointer leftChild;
	logical data;
	short int value;
	treePointer rightChild;
}node;
treePointer root = NULL;

#define MALLOC(p,s) \
	if(!((p) = (treePointer) malloc(s))) {\
		fprintf(stderr, "insufficient memory");\
		exit (EXIT_FAILURE);\
	}

void postOrderEval(treePointer node);
treePointer stack[MAX_STACK_SIZE];
int top = -1, num = 0;
void push(treePointer item);
void stackFull();
logical getToken(char* symbol, int* n);
treePointer pop();
treePointer stackEmpty();
treePointer createNode(logical data, short int value);
treePointer createBinTree(short int *TF);
char expr[81];
char alpha[MAX];
void Free(treePointer* root);
void TFprint(char* alpha, short int* TF);

int main(void) {
	int i = 0, j, k = 0, n, p,lim;
	short int TF[MAX];
	FILE* fp;

	if ((fp = fopen("input.txt", "r")) == NULL) {
		fprintf(stderr, "cannot open the file");
		exit(EXIT_FAILURE);
	}
	fscanf(fp, "%d\n", &num);
	fgets(expr, 80, fp);
	fclose(fp);



	while(expr[i] != '\0') {
		if (expr[i] != '~' && expr[i] != '|' && expr[i] != '&') {
			for (j = 0; j < k + 1; j++) {
				if (alpha[j] == expr[i]) break;
				else if (alpha[j] != expr[i] && j == k) {
					alpha[k++] = expr[i];
					break;
				}
			}
		}
		i++;
	}

	lim = pow(2, num);

	for (i = 0; i < lim; i++) {
		n = i;
		for (j = num - 1; j > -1; j--) {
			p = pow(2, j);
			TF[j] = n / p;
			n = n % p;
		}

		root = createBinTree(TF);
		TFprint(alpha, TF);
		postOrderEval(root);
		if (root->value == TRUE) {
			printf(" = TRUE\n");
		}
		else if (root->value == FALSE) {
			printf(" = FALSE\n");
		}

		Free(&root);
	}
}
void TFprint(char *alpha, short int *TF) {
	int i;
	printf("[");
	for (i = 0; i < num; i++) {
		if (TF[i] == FALSE) printf("%c = FALSE ", alpha[i]);
		else if (TF[i] == TRUE) printf("%c =  TRUE ", alpha[i]);
	}
	printf("]");
}

treePointer createBinTree(short int *TF) {
	logical token;
	char symbol;
	treePointer pNode = NULL;
	treePointer op1, op2;
	int n = 0, i;
	top = -1;
	token = getToken(&symbol, &n);
	while (token != fals) {
		if (token == tru || token == fals) {
			for (i = 0; i < num; i++) {
				if (symbol == alpha[i]) {
					if (TF[i] == TRUE) pNode = createNode(tru, TF[i]);
					else if (TF[i] == FALSE) pNode = createNode(fals, TF[i]);
				}
			}
			push(pNode);
		}
		else {
			pNode = createNode(token, TRUE);
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

logical getToken(char* symbol, int* n) {
	*symbol = expr[(*n)++];
	switch (*symbol) {
	case '&': return logicand;
	case '|': return logicor;
	case '~': return logicnot;
	case '\0': return fals;
	default: return tru;
	}
}

treePointer pop() {
	if (top == -1)
		return stackEmpty();\
		return stack[top--];
}

treePointer stackEmpty() {
	treePointer item;
	item = NULL;
	return item;
}

void push(treePointer item) {
	if (top >= MAX_STACK_SIZE - 1)
		stackFull();
	stack[++top] = item;
}

void stackFull() {
	fprintf(stderr, "stack is full, cannot add item\n");
	exit(EXIT_FAILURE);
}

treePointer createNode(logical data, short int value) {
	treePointer temp;
	MALLOC(temp, sizeof(*temp));
	temp->data = data;
	temp->value = value;
	temp->leftChild = NULL;
	temp->rightChild = NULL;

	return temp;
}

void postOrderEval(treePointer node) {
	if (node) {
		postOrderEval(node->leftChild);
		postOrderEval(node->rightChild);
		switch (node->data) {
		case logicnot :
			if (node->rightChild->value == FALSE) node->value = TRUE;
			else node->value = FALSE;
			break;
		case logicand:
			if (node->rightChild->value == TRUE && node->leftChild->value == TRUE) node->value = TRUE;
			else node->value = FALSE;
			break;
		case logicor:
			if (node->rightChild->value == FALSE && node->leftChild->value == FALSE) node->value = FALSE;
			else node->value = TRUE;
			break;
		case tru :
			node->value = TRUE;
			break;
		case fals :
			node->value = FALSE;
			break;
		}
	}
}

void Free(treePointer* root) {
	if (*root) {
		Free((&(*root)->leftChild));
		Free((&(*root)->rightChild));
		free(*root);
	}
}