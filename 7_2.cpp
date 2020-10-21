#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
#define MAX_QUEUE_SZIE 5
#define MAX_NAME_SZIE 10

//2017111866 황지욱
//본인은 이 소스파일을 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다.

typedef struct {
	int id;
	char name[MAX_NAME_SZIE];
}element;

element queue[MAX_QUEUE_SZIE];
int rear = -1;
int front = -1;

element queueEmpty() {
	element q;
	fprintf(stderr, "queue is empty, cannot delete elemnt\n");
	exit(EXIT_FAILURE);
	return q;
}

element deleteq() {
	if (front == rear) {
		return queueEmpty();
	}
	return queue[++front];
}

void queueFull() {
	element q;
	if (front == -1) {
		fprintf(stderr, "queue is full, cannot add elemnt\n");
		fprintf(stderr, "current queue elemnets :\n");
		while (front != rear) {
			q = deleteq();
			printf("%d %s\n", q.id, q.name);
		}
		exit(EXIT_FAILURE);
	}
	else {
		int i = front + 1, j = 0;
		front = -1;
		rear = rear - i;
		fprintf(stderr, "array shifting\n");
		for (; i <= MAX_QUEUE_SZIE - 1; i++) {
			queue[j++] = queue[i];
		}
		
	}

}

void addq(element item) {
	if (rear == MAX_QUEUE_SZIE - 1) {
		queueFull();
	}
	queue[++rear] = item;
}

int main() {
	char qu[30];
	char* q;
	char* c;
	element item;

	printf("<< linear queue operations where MAX_QUEUE_SZIE is 5\n");
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
			deleteq();
		}
		else if (strcmp(q, "stop")) {
			break;
		}
		else {
			printf("wrong commnad! try again!\n");
		}
	}


}