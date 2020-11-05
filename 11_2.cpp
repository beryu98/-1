#include <stdio.h>
#include <stdlib.h>
#define COMPARE(a,b) (a > b ? 1 : a == b ? 0 : -1)
#define FALSE 0
#define TRUE 1

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
polyPointer c, lastA, lastB, avail = NULL;

polyPointer getNode() {
	polyPointer node;
	if (avail) {
		node = avail;
		avail = avail->link;
	}
	else {
		MALLOC(node, sizeof(*node));
	}
	return node;
}

void attach(int coefficient, int exponent, polyPointer* ptr) {
	polyPointer temp;
	temp = getNode();
	temp->coef = coefficient;
	temp->expon = exponent;
	(*ptr)->link = temp;
	*ptr = temp;
}

void erase(polyPointer* ptr) {
	polyPointer temp;
	while (*ptr) {
		temp = *ptr;
		*ptr = (*ptr)->link;
		free(temp);
	}
}

void cerase(polyPointer* ptr) {
	polyPointer temp;
	if (*ptr) {
		temp = (*ptr)->link;
		(*ptr)->link = avail;
		avail = temp;
		*ptr = NULL;
	}
}

void retNode(polyPointer node) {
	node->link = avail;
	avail = node;
}

polyPointer cpadd(polyPointer a, polyPointer b) {
	polyPointer startA, c, lastC;
	int sum, done = FALSE;
	startA = a;
	a = a->link;
	b = b->link;
	c = getNode();
	c->expon = -1;
	lastC = c;

	do {
		switch (COMPARE(a->expon, b->expon)) {
		case -1:
			attach(b->coef, b->expon, &lastC);
			b = b->link;
			break;
		case 0:
			if (startA == a) {
				done = TRUE;
			}
			else {
				sum = a->coef + b->coef;
				if (sum) {
					attach(sum, a->expon, &lastC);
				}
				a = a->link;
				b = b->link;
			}
			break;
		case 1:
			attach(a->coef, a->expon, &lastC);
			a = a->link;
			break;

		}
	} while (!done);
	lastC->link = c;
	return c;
}

void insertFront2(polyPointer* last, int coef, int expon) {
	polyPointer node, x;
	x = (*last)->link;
	node = getNode();
	node->coef = coef;
	node->expon = expon;

	if ((*last)->expon == -1) {
		node->link = x;
		x->link = node;
		*last = node;
	}
	else {
		node->link = x->link;
		x->link = node;
	}
}

void insertLast(polyPointer* last, int coef, int expon) {
	polyPointer node;
	node = getNode();
	node->coef = coef;
	node->expon = expon;
	node->link = (*last)->link;

	(*last)->link = node;
	*last = node;
}

void printCList(polyPointer last) {
	polyPointer temp;	

	if (last) {
		temp = last->link;
		do {
			temp = temp->link;
			if (temp->expon != -1) {
				if (temp->coef > 0) {
					printf(" + %dx^%d", temp->coef, temp->expon);
				}
				else if (temp->coef < 0) {
					printf(" - %dx^%d", -(temp->coef), temp->expon);
				}
			}
		} while(temp != last);
	}
	printf("\n");
}

void inputPolyCL(FILE* file, polyPointer* x,polyPointer *last) {
	int coef, expon;
	char ch;
	(*x) = getNode();
	(*x)->expon = -1;
	(*x)->link = *x;
	*last = *x;

	fscanf(file, "%c\n", &ch);
	while (!feof(file)) {
		if (ch == 'a') {
			fscanf(file, "%d %d\n", &coef, &expon);
			insertFront2(last, coef, expon);
		}
		else if (ch == 'd') {
			fscanf(file, "%d %d\n", &coef, &expon);
			insertLast(last, coef, expon); 
		}
	}
}

int main() {
	polyPointer lastC, CL;

	FILE* ai = fopen("a.txt", "r");
	FILE* bi = fopen("b.txt", "r");

	inputPolyCL(ai, &a, &lastA);
	inputPolyCL(bi, &b, &lastB);

	fclose(ai);
	fclose(bi);

	printf("a : ");
	printCList(lastA);

	printf("b : ");
	printCList(lastB);

	c = cpadd(a, b);
	CL = c;

	while (1) {
		if (CL->link == c) {
			lastC = CL;
			break;
		}
		CL = CL->link;
	}

	printf("a + b = c : ");
	printCList(lastC);

	cerase(&a);
	erase(&avail);

	cerase(&b);
	erase(&avail);

	cerase(&c);
	erase(&avail);
}