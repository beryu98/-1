#include <stdio.h>
#include <stdlib.h>
#define MAX_STACKS 3 

//2017111866 Ȳ����
//������ �� �ҽ������� �ٸ� ����� �ҽ��� �������� �ʰ� ���� �ۼ��Ͽ����ϴ�.


typedef struct {
	int id;
	int grade;
} element;
typedef struct stack* stackPointer;

#define MALLOC(p,s) \
	if(!((p) = (stackPointer) malloc(s))) {\
		fprintf(stderr, "insufficient memory");\
		exit (EXIT_FAILURE);\
	}

typedef struct stack {
	element data;
	stackPointer link;
}Node;

stackPointer top[MAX_STACKS];

void push(int i, element item) {
	stackPointer temp;
	MALLOC(temp, sizeof(*temp));
	temp->data = item;
	temp->link = top[i];
	top[i] = temp;
}

element stackEmpty() {
	element a;
	a.id = -1;
	return a;
}
element pop(int i) {
	stackPointer temp = top[i];
	element item;
	if (!temp) {
		return stackEmpty();
	}
	item = temp->data;
	top[i] = temp->link;
	free(temp);
	return item;
}

int main() {
	int num, i;
	element item;
	FILE* input = fopen("input.txt", "r");

	while (!feof(input)) {
		fscanf(input, "%d %d %d", &num, &item.id, &item.grade);
		push(num, item);
	}
	fclose(input);
	printf("�����ȣ, �й�, ����\n");
	for (i = 0;i < MAX_STACKS; i++) {
		printf("***********************************\n");
		while (1) {
			item = pop(i);
			if (item.id == -1) {
				break;
			}
			printf("%5d %7d %5d\n", i, item.id, item.grade);
		}
	}
}