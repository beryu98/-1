#include <stdio.h>
#include <stdlib.h>
#define MAX_COL 10
#define _CRT_SECURE_NO_WARNINGS

typedef struct {
	int row;
	int col;
	int value;
}term;

term a[MAX_COL], b[MAX_COL];

//2017111866 황지욱
//본인은 이 소스파일을 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다.

void fastTranspose(term a[], term b[]) {
	int rowTerms[MAX_COL], startingPos[MAX_COL];
	int i, j, numCols = a[0].col, numTerms = a[0].value;
	b[0].row = numCols;
	b[0].col = a[0].row;
	
	if (numTerms > 0) {
		for (i = 0; i < numCols; i++) {
			rowTerms[i] = 0;
		}
		for (i = 1; i <= numTerms; i++) {
			rowTerms[a[i].col]++;
		}
		startingPos[0] = 1;
		for (i = 1; i < numCols; i++) {
			startingPos[i] = startingPos[i - 1] + rowTerms[i - 1];
		}
		for (i = 1; i <= numTerms; i++) {
			j = startingPos[a[i].col]++;
			b[j].row = a[i].col;
			b[j].col = a[i].row;
			b[j].value = a[i].value;
		}
	}
}

void print(term a[], int row, int col) {
	int i, j, n = 1, zero = 0;

	for (i = 1; i <= row; i++) {
		for (j = 1; j <= col; j++) {
			if (a[n].row == i - 1 && a[n].col == j - 1) {
				printf("%4d", a[n].value);
				n++;
			}
			else {
				printf("%4d", zero);
			}
		}
		printf("\n");
	}
}

int main() {
	FILE* input = fopen("c:\\a.txt", "r");
	FILE* output = fopen("c:\\b.txt", "w");
	int i;
	


	fscanf_s(input, "%d %d %d\n", &a[0].row, &a[0].col, &a[0].value);
	fprintf(output, "%d %d %d\n", a[0].row, a[0].col, a[0].value);

	for (i = 1; i <= a[0].value; i++) {
		fscanf_s(input, "%d %d %d\n", &a[i].row , &a[i].col, &a[i].value);
	}

	fastTranspose(a, b);

	for (i = 1; i <= a[0].value; i++) {
		fprintf(output, "%d %d %d\n", b[i].row, b[i].col, b[i].value);
	}

	printf("A\n");
	print(a, a[0].row, a[0].col);

	printf("B\n");
	print(b, a[0].col, a[0].row);

	fclose(input);
	fclose(output);
}