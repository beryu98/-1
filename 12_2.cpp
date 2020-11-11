#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 100

//2017111866 황지욱
//본인은 이 소스파일을 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다.

typedef struct node* treePointer;
typedef struct node {
	char data;
	treePointer leftChild, rightChild;
}tNode;

int front = -1;
int rear = -1;

treePointer root;
treePointer queue[MAX_QUEUE_SIZE];

void insert(treePointer* pRoot, treePointer pNode);

#define MALLOC(p,s) \
	if(!((p) = (treePointer) malloc(s))) {\
		fprintf(stderr, "insufficient memory");\
		exit (EXIT_FAILURE);\
	}

int deleteEmpty() {
	if (front == rear) {
		return true;
	}
		
	else {
		return false;
	}
}

int queueFull() {
	if (rear + 1 == front) {
		return true;
	}
	else {
		return false;
	}
}

void addq(treePointer node) {
	if (queueFull()) {
		printf("Queue is Full\n");
		exit(EXIT_FAILURE);
	}
	else {
		queue[++rear] = node;
	}

}

treePointer deleteq() {
	if (deleteEmpty()) {
		printf("Queue is Empty\n");
		exit(EXIT_FAILURE);
	}
	else {
		return queue[++front];
	}
}

treePointer getFornt() {
	return queue[front + 1];
}

treePointer createNode(char data) {
	treePointer temp;
	MALLOC(temp, sizeof(*temp));
	temp->data = data;
	temp->leftChild = NULL;
	temp->rightChild = NULL;

	return temp;
}

int hasBothChild(treePointer pNode) {
	if (pNode->leftChild == NULL) {
		return 0;
	}
	else if (pNode->rightChild == NULL) {
		return 1;
	}
	else {
		return 2;
	}
}

void insert(treePointer* pRoot, treePointer pNode) {
	int i;
	treePointer temp;
	
	if (*pRoot == NULL) {
		*pRoot = pNode;
	}

	else {
		temp = getFornt();
		i = hasBothChild(temp);
		if (i == 0) {
			temp->leftChild = pNode;
		}
		else if (i == 1) {
			temp->rightChild = pNode;
		}
		else {
			deleteq();
		}
	}
	addq(pNode);
}

void createBinTree(FILE* input) {
	char data;
	treePointer node;

	while (!feof(input)) {
		fscanf(input, "%c", &data);
		node = createNode(data);
		insert(&root, node);
	}
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

void Free(treePointer* root){
	if (*root){
		Free((&(*root)->leftChild));
		Free((&(*root)->rightChild));
		free(*root);
	}
}


int main() {

	FILE* input = fopen("input.txt", "r");

	createBinTree(input);
	fclose(input);

	printf("three binary tree traversals");

	printf("\ninorder traversal : ");
	inorder(root);

	printf("\npreorder traversal : ");
	preorder(root);

	printf("\npostorder traversal : ");
	postorder(root);

	Free(&root);
}