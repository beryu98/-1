#include <stdio.h>
#include <stdlib.h>
#define MAX_TERMS 100
#define _CRT_SECURE_NO_WARNINGS
#define COMPARE(x, y) (((x) < (y)) ? -1 : ((x) == (y)) ? 0: 1 )

//2017111866 황지욱
//본인은 이 소스파일을 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다.

typedef struct {
	float coef;
	int expon;
}term;

term terms[MAX_TERMS];

int avail = 0;

void termprint(int start, int finish) {
	int i = start;

	printf("%.1fx^%d ", terms[i].coef, terms[i].expon);
	i++;
	for (; i <= finish; i++) {
		if (terms[i].coef < 0 && terms[i].expon != 0) {
			printf(" %.1fx^%d ", terms[i].coef, terms[i].expon);
		}
		else if (terms[i].expon == 0) {
			if (terms[i].coef < 0) {
				printf(" %.1f ", terms[i].coef);
			}

			else {
				printf("+ %.1f ", terms[i].coef);
			}
		}

		else {
			printf("+ %.1fx^%d ", terms[i].coef, terms[i].expon);
		}
	}

	printf("\n");
}

void attach(float coefficient, int exponent) {
	if (avail >= MAX_TERMS) {
		fprintf(stderr, "Too many terms in the polynomial\n");
		exit(EXIT_FAILURE);
	}
	terms[avail].coef = coefficient;
	terms[avail++].expon = exponent;
}

void padd(int startA, int finishA, int startB, int finishB, int* startD, int* finishD) {
	float coefficient;
	*startD = avail;
	while (startA <= finishA && startB <= finishB) {
		switch (COMPARE(terms[startA].expon, terms[startB].expon)) {
		case -1:
			attach(terms[startB].coef, terms[startB].expon);
			startB++;
			break;
		case 0:
			coefficient = terms[startA].coef + terms[startB].coef;
			if (coefficient) {
				attach(coefficient, terms[startA].expon);
			}
			startA++;
			startB++;
			break;
		case 1:
			attach(terms[startA].coef, terms[startA].expon);
			startA++;
			break;
		}
	}
	

	for (; startA <= finishA; startA++) {
		attach(terms[startA].coef, terms[startA].expon);
	}

	for (; startB <= finishB; startB++) {
		attach(terms[startB].coef, terms[startB].expon);
	}
	
	*finishD = avail - 1;
}


int main() {
	FILE* input = fopen("c:\\input.txt", "r");
	int  n1, n2, startA, finishA, startB, finishB, startD, finishD;
	term term;

	printf("two input polynomials ...\n");
	startA = avail;

	fscanf_s(input, "%d %d\n", &n1, &n2);

	while (1) {
		fscanf_s(input, "%f %d\n", &term.coef, &term.expon);
		if (n1 - 1 == avail) {
			finishA = avail;
			attach(term.coef, term.expon);
			break;
		}
		attach(term.coef, term.expon);
	}

	startB = avail;

	while (1) {
		fscanf_s(input, "%f %d\n", &term.coef, &term.expon);
		if (n1 + n2 - 1 == avail) {
			finishB = avail;
			attach(term.coef, term.expon);
			break;
		}
		attach(term.coef, term.expon);
	}

	printf("A(x) = ");
	termprint(startA, finishA);
	printf("B(x) = ");
	termprint(startB, finishB);

	printf("\nthe result of polynomials addition ...\n");
	printf("D(x) = A(x) + B(x) = \n");

	padd(startA, finishA, startB, finishB, &startD, &finishD);

	termprint(startD, finishD);

	fclose(input);
}