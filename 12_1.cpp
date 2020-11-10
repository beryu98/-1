#include <stdio.h>
#include <stdlib.h>

//2017111866 황지욱
//본인은 이 소스파일을 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다.

typedef struct node* treePointer;
typedef struct node {
	char data;
	treePointer leftChild, rightChild;
}node;
treePointer root;
treePointer avail = NULL;

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

void createBinTree() {
	treePointer node1, node2, node3;

	node1 = createNode('B');
	node2 = createNode('D');
	node3 = createNode('E');

	node1->leftChild = node2;
	node1->rightChild = node3;

	node2 = createNode('A');
	node3 = createNode('C');

	node2->leftChild = node1;
	node2->rightChild = node3;

	root = node2;
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
	if (*root){
		Free((&(*root)->leftChild));
		Free((&(*root)->rightChild));
		free(*root);
	}
}

int main() {
	printf("creating a binarytree\n\n");

	createBinTree();

	printf("three binary tree traversals");

	printf("\ninorder traversal : ");
	inorder(root);

	printf("\npreorder traversal : ");
	preorder(root);

	printf("\npostorder traversal : ");
	postorder(root);

	Free(&root);
}