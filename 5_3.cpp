#include <stdio.h>
#include <stdlib.h>

//2017111866 황지욱
//본인은 이 소스파일을 복사 없이 직접 작성하였습니다.

#define MALLOC1(p,s) \
	if(!((p) = (int**) malloc(s))) {\
		fprintf(stderr, "insufficient memory");\
		exit (EXIT_FAILURE);\
	}

#define MALLOC2(p,s) \
	if(!((p) = (int*) malloc(s))) {\
		fprintf(stderr, "insufficient memory");\
		exit (EXIT_FAILURE);\
	}

int i, j;

void add(int **a, int **b, int **c, int rows, int cols) {
	int i, j;
	for (i = 0; i < rows; i++) {
		for (j = 0; j < cols; j++) {
			c[i][j] = a[i][j] + b[i][j];
		}
	}
}

int** make2dArray(int rows, int cols) {
	int** x;
	
	MALLOC1(x, rows * sizeof(*x));

	for (i = 0; i < rows; i++) {
		MALLOC2(x[i], cols * sizeof(**x));
	}

	return x;
}

void free2dArray(int** a, int** b, int** c, int row) {

	for (i = 0; i < row; i++) {
		free(a[i]);
	}
	free(a);

	for (i = 0; i < row; i++) {
		free(b[i]);
	}
	free(b);

	for (i = 0; i < row; i++) {
		free(c[i]);
	}
	free(c);

	printf("2d array - free!");
}

void print2dArray(int** ary, int row, int col) {
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			printf(" %d", ary[i][j]);
		}
		printf("\n");
	}
}

void init2dArray (int** ary, int row, int col, int n) {
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			ary[i][j] = n + j;
		}
		n ++;
	}
}


int main() {

	int row, col;
	printf("Enter row size and column size (ex) 3 4 : ");
	scanf_s("%d", &row);
	scanf_s("%d", &col);
	
	int** a = make2dArray(row, col);
	int** b = make2dArray(row, col);
	int** c = make2dArray(row, col);
	
	init2dArray(a, row, col, 1);
	init2dArray(b, row, col, 2);

	printf("matrix A\n");
	print2dArray(a, row, col);

	printf("matrix B\n");
	print2dArray(b, row, col);

	add(a, b, c, row, col);

	printf("matrix C\n");

	print2dArray(c, row, col);

	free2dArray(a, b, c, row);
}