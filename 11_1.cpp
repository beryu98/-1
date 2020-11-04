#include <stdio.h>
#include <stdlib.h>
#define COMPARE(a,b) (a > b ? 1 : a == b ? 0 : -1)

//2017111866 황지욱
//본인은 이 소스파일을 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다.


typedef struct polyNode* polyPointer;

#define MALLOC(p,s) \
	if(!((p) = (polyPointer) malloc(s))) {\
		fprintf(stderr, "insufficient memory");\
		exit (EXIT_FAILURE);\
	}

typedef struct polyNode {
	int coef;
	int expon;
	polyPointer link;
}polyNode;
polyPointer a, b;

void insert(polyPointer* first, polyPointer x, int coef, int expon) {
	polyPointer temp;
	MALLOC(temp, sizeof(*temp));
	temp->coef = coef;
	temp->expon = expon;

	if (*first == NULL) {
		temp->link = NULL;
		*first = temp;
	}
	else {
		if (x->link == NULL) {
			if (x->expon > temp->expon) {
				temp->link = NULL;
				x->link = temp;
			}
			else {
				temp->link = *first;
				*first = temp;
			}
		}
		else {
			temp->link = *first;
			*first = temp;
		}
	}
}

void printList (polyPointer first) {
	for (; first; first = first->link) {
		if (first->coef > 0) {
			printf(" + %dx^%d", first->coef, first->expon);
		}
		else if (first->coef < 0) {
			printf(" - %dx^%d", -(first->coef), first->expon);
		}
	}
	printf("\n");
}

void attach(int coefficient, int exponent, polyPointer* ptr) {
	polyPointer temp;
	MALLOC(temp, sizeof(*temp));
	temp->coef = coefficient;
	temp->expon = exponent;
	(*ptr)->link = temp;
	*ptr = temp;
}

polyPointer padd (polyPointer a, polyPointer b) {
	polyPointer c, rear, temp;
	int sum;
	MALLOC(rear, sizeof(*rear));
	c = rear;

	while (a && b) {
		switch (COMPARE(a->expon, b->expon)) {
			case -1 :
				attach(b->coef, b->expon, &rear);
				b = b->link;
				break;
			case 0 :
				sum = a->coef + b->coef;
				if (sum) {
					attach(sum, a->expon, &rear);
				}
				a = a->link;
				b = b->link;
				break;
			case 1 :
				attach(a->coef, a->expon, &rear);
				a = a->link;
				break;

		}
	}

	for (; a; a = a->link) {
		attach(a->coef, a->expon, &rear);
	}
	for (; b; b = b->link) {
		attach(b->coef, b->expon, &rear);
	}
	rear->link = NULL;
	temp = c;
	c = c->link;
	free(temp);
	return c;
}

polyPointer findLast (polyPointer *b) {
	polyPointer x = *b;
	if (*b == NULL) {
		return x;
	}
	else {
		while (x->link != NULL) {
			x = x->link;
		}

		return x;
	}
}

void erase(polyPointer* ptr) {
	polyPointer temp;
	while (*ptr) {
		temp = *ptr;
		*ptr = (*ptr)->link;
		free(temp);
	}
}
void inputPoly(FILE* file, polyPointer *x) {
	int coef, expon;
	char ch;
	polyPointer p;

	fscanf(file, "%c\n", &ch);
	while (!feof(file)) {
		if (ch == 'a') {
			fscanf(file, "%d %d\n", &coef, &expon);
			p = *x;
			insert(x, p, coef, expon);
		}
		else if (ch == 'd') {
			fscanf(file, "%d %d\n", &coef, &expon);
			p = findLast(x);
			insert(x, p, coef, expon);
		}
	}
}

int main () {
	polyPointer c;

	FILE* ai = fopen("a.txt", "r");
	FILE* bi = fopen("b.txt", "r");

	inputPoly(ai, &a);
	inputPoly(bi, &b);
	
	fclose(ai);
	fclose(bi);

	printf("a : ");
	printList(a);

	printf("b : ");
	printList(b);

	c = padd(a, b);
	printf("a + b = c : ");
	printList(c);

	erase(&a);
	erase(&b);
	erase(&c);
}