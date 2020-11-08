#include <stdio.h>
#include <stdlib.h>

//2017111866 황지욱
//본인은 이 소스파일을 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다.

typedef struct node* nodePointer;

typedef struct node {
	nodePointer llink;
	int data;
	nodePointer rlink;
} node;

nodePointer header = NULL;
nodePointer empty;

#define MALLOC(p,s) \
	if(!((p) = (nodePointer) malloc(s))) {\
		fprintf(stderr, "insufficient memory");\
		exit (EXIT_FAILURE);\
	}

void dinsert(nodePointer node, nodePointer newnode) {
	newnode->llink = node;
	newnode->rlink = node->rlink;
	node->rlink->llink = newnode;
	node->rlink = newnode;
}

void ddelete(nodePointer node, nodePointer deleted) {
	if (node == deleted) {
		printf("Deletion of header node not permitted.\n");
	}
	else {
		deleted->llink->rlink = deleted->rlink;
		deleted->rlink->llink = deleted->llink;
		free(deleted);
	}
}

void forward(nodePointer header) {
	nodePointer node = header->rlink;
	int count = 0;

	printf("forward\n");
	while(1) {
		if (node == header) {
			printf("\n\n");
			break;
		}
		if (count == 10) {
			printf("\n");
			count = 0;
		}
		printf(" %d", node->data);
		node = node->rlink;
		count++;
	}
}

void backward(nodePointer header) {
	nodePointer node = header->llink;
	int count = 0;
	printf("backward\n");
	while (1) {
		if (node == header) {
			printf("\n\n");
			break;
		}
		if (count == 10) {
			printf("\n");
			count = 0;
		}
		printf(" %d", node->data);
		node = node->llink;
		count++;
	}
}

void inputPoly(int num, nodePointer* list, nodePointer* header) {
	nodePointer newnode;
	MALLOC(newnode, sizeof(*newnode));
	newnode->data = num;

	dinsert((*header)->llink, newnode);
}

int main() {
	int num;
	nodePointer node1, node2;
	FILE* input = fopen("input.txt", "r");

	MALLOC(empty, sizeof(*empty));
	empty->rlink = empty;
	empty->llink = empty;
	header = empty;

	while (!feof(input)) {
		fscanf(input, "%d ", &num);
		inputPoly(num, &empty, &header);
	}
	fclose(input);

	printf("After creating a doubly linked circular list with a head node : \n");
	forward(header);
	backward(header);

	node1 = header->rlink;
	while (1) {
		if (node1->data <= 50) {
			node2 = node1->rlink;
			ddelete(header, node1);
			node1 = node2;
		}
		else {
			node1 = node1->rlink;
			if (node1->rlink == header) {
				break;
			}
		}
	}

	printf("After deleting numbers less than and equal to 50 : \n");
	forward(header);
	backward(header);

	node1 = header->rlink;
	while (1) {
		node2 = node1->rlink;
		ddelete(header, node1);
		node1 = node2;
		if (node1 == header) {
				break;
		}
	}

	printf("After deleting all nodes except for the header node: \n");
	forward(empty->llink);
	backward(header);
	free(empty);
}


