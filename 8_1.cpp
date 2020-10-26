#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
#define MAX_NAME_SZIE 10

//2017111866 황지욱
//본인은 이 소스파일을 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다.

#define MALLOC(p,s) \
	if(!((p) = (element*) malloc(s))) {\
		fprintf(stderr, "insufficient memory");\
		exit (EXIT_FAILURE);\
	}

typedef struct {
	int id;
	char name[MAX_NAME_SZIE];
}element;

element* queue;
int capacity = 2;
int rear = 0;
int front = 0;

void copy(element* a, element* b, element* c) {
	int i;
	for (i = 0; a + i < b; i++) {
		c[i] = *(a + i);
	}
}
element queueEmpty() {
	element q;
	fprintf(stderr, "queue is empty, cannot delete elemnt\n");
	free(queue);
	exit(EXIT_FAILURE);
	return q;
}

element deleteq() {
	element item;
	if (front == rear) {
		return queueEmpty();
	}
	front = (front + 1) % capacity;
	return queue[front];
}

void queueFull() {
	int start;
	element* newQueue;
	MALLOC(newQueue, 2 * capacity * sizeof(*queue));

	start = (front + 1) % capacity;
	rear--;

	if (start < 2) {
		copy(queue + start, queue + start + capacity - 1, newQueue);
	}
	else {
		copy(queue + start, queue + capacity, newQueue);
		copy(queue, queue + rear + 1, newQueue + capacity - start);
	}

	front = 2 * capacity - 1;
	rear = capacity - 1;
	capacity *= 2;
	printf("queue capacity is doubled,\ncurrent queue capacity is %d\n", capacity);
	free(queue);
	queue = newQueue;
}

void addq(element item) {
	rear = (rear + 1) % capacity;
	if (front == rear) {
		queueFull();
	}
	queue[rear] = item;
}


int main() {
	char qu[30];
	char* q;
	char* c = NULL;
	element del;
	element item;
	MALLOC(queue, capacity * sizeof(*queue));


	printf("<< linear queue operations where the initial capacity is 2\n");
	printf("add 1 Jung\n");
	printf("delete\n");
	printf("\n****************************************\n");

	while (1) {
		gets_s(qu);
		q = strtok_s(qu, " ", &c);

		if (strcmp(q, "add") == 0) {
			q = strtok_s(NULL, " ", &c);
			item.id = atoi(q);
			q = strtok_s(NULL, " ", &c);
			strcpy(item.name, q);
			addq(item);
		}
		else if (strcmp(q, "delete") == 0) {
			del = deleteq();
			printf("deleted item : %d %s\n", del.id, del.name);
		}
		else if (strcmp(q, "quit") == 0) {
			free(queue);
			break;
		}
		else {
			printf("wrong commnad! try again!\n");
		}
	}
}