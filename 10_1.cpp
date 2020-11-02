#include <stdio.h>
#include <stdlib.h>

//2017111866 황지욱
//본인은 이 소스파일을 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다.

typedef struct listNode* listPointer;

typedef struct listNode {
	int data;
	listPointer link;
}listNode;
listPointer first = NULL;

#define MALLOC(p,s) \
	if(!((p) = (listPointer) malloc(s))) {\
		fprintf(stderr, "insufficient memory");\
		exit (EXIT_FAILURE);\
	}


void insert(listPointer* first, listPointer* x, int data) {
	listPointer temp;
	MALLOC(temp, sizeof(*temp));
	temp->data = data;

	if (*first == NULL) {
		temp->link = NULL;
		*first = temp;
	}
	else {
		if ((*x)->link == NULL) {
			temp->link = NULL;
			(*x)->link = temp;
		}
		else if ((*x) == (*first)) {
			temp->link = (*first);
			(*first) = temp;
		}
		else {
			temp->link = (*x)->link;
			(*x)->link = temp;
		}
	}
}

void Delete (listPointer* first, listPointer trail, listPointer x) {
	if (trail) {
		trail->link = x->link;
	}
	else {
		*first = (*first)->link;
	}
	free(x);
}

void printList (listPointer first) {
	int c = 0;
	printf("The list contains : \n");
	for (; first; first = first->link) {
		printf("%4d", first->data);
		c++;
		if (c == 10) {
			printf("\n");
			c = 0;
		}
	}
	
}

listPointer find(int num) {
	listPointer x = first;

	while (1) {
		if (x == NULL || x->link == NULL) {
			return x;
		}
		else {
			if (x->data < num) {
				if ((x->link)->data > num) {
					return x;
				}
				else {
					x = x->link;
				}
			}
			else {
				return x;
			}
		}
	}
}

int main() {
	int num;
	listPointer x;
	FILE* input = fopen("input.txt", "r");

	while (!feof(input)) {
		fscanf(input, "%d", &num);
		x = find(num);
		insert(&first, &x, num);
	}
	fclose(input);
	
	printList(first);

	x = first;

	while (1) {
		if (x->data <= 50) {
			Delete(&first, 0, x);
			x = first;
		}
		else {
			break;
		}
	}
	printf("After deleting nodes with data less than and equal to 50\n");

	printList(first);

	while (1) {
		if (x != NULL) {
			Delete(&first, 0, x);
			x = first;
		}
		else {
			break;
		}
	}

}
	