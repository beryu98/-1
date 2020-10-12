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

int s, i, j;

int sumAry2D_f1(int ary[][3], int row, int col) {
	s = 0;

	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			s += ary[i][j];
		}
	}

	return s;
}

int sumAry2D_f2(int(*ary)[3], int row, int col) {
	s = 0;

	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			s += ary[i][j];
		}
	}

	return s;
}

int sumAry2D_f3(int ary[2][3], int row, int col) {
	s = 0;

	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			s += ary[i][j];
		}
	}

	return s;
}

int sumAry2D_f4(int** ary, int row, int col) {
	
	s = 0;

	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			s += ary[i][j];
		}
	}

	return s;
}

int sumAry2D_f5(int*** ary, int row, int col) {

	s = 0;

	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			s += *(*(*ary+i)+j);
		}
	}

	return s;
}

void freeAry2D(int** ary, int a) {

	for (i = 0; i < a; i++) {
		free (ary[i]);
	}
	
	free(ary);

	printf("2d array - free!");
}

int main() {
	int ary2D[][3] = { {1, 2, 3},
						{4, 5, 6} };

	int** ary = (int**)malloc(sizeof(int*) * 2);
	MALLOC1(ary, sizeof(int*) * 2);

	for (i = 0; i < 2; i++) {
		ary[i] = (int*) malloc(sizeof(int) * 3);
		MALLOC2(ary[i], sizeof(int) * 3);
	}
	

	for (i = 0; i < 2; i++) {
		for (j = 0; j < 3; j++) {
			ary[i][j] = i + j;
		}
	}

	printf("sumAry2D_f1() %d\n", sumAry2D_f1(ary2D, 2, 3));
	printf("sumAry2D_f2() %d\n", sumAry2D_f2(ary2D, 2, 3));
	printf("sumAry2D_f3() %d\n", sumAry2D_f3(ary2D, 2, 3));

	printf("sumAry2D_f4() %d\n", sumAry2D_f4(ary, 2, 3));
	printf("sumAry2D_f5() %d\n", sumAry2D_f5(&ary, 2, 3));

	freeAry2D(ary, 2);

	return 0;
}