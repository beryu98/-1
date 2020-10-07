#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_SIZE 3

//2017111866 황지욱
//본인은 이 소스파일을 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다.

int i = 0, j = 0, count = 0;

void add(int a[][MAX_SIZE], int b[][MAX_SIZE], int c[][MAX_SIZE], int rows, int cols) {
	int i, j;

	for (i = 0; i < rows; i++) {
		count++;
		for (j = 0; j < cols; j++) {
			count++;
			c[i][j] = a[i][j] + b[i][j]; count++;
		}
		count++;
	}
	count++;
}

void input(int num[][MAX_SIZE], int rows, int cols, FILE* file) {


	for (i = 0; i < rows; i++) {
		for (j = 0; j < cols; j++) {
			fscanf_s(file, "%d", &num[i][j]); 
		}
		fscanf_s(file, "\n"); 
	}
}




int main() {
	int a[3][MAX_SIZE], b[3][MAX_SIZE], c[3][MAX_SIZE];

	FILE* num1 = fopen("c:\\a.txt", "r");
	FILE* num2 = fopen("c:\\b.txt", "r");

	input(a, 3, MAX_SIZE, num1);
	input(b, 3, MAX_SIZE, num2);

	add(a, b, c, 3, MAX_SIZE);

	fclose(num1);
	fclose(num2);

	for (i = 0; i < 3; i++) {
		for (j = 0; j < MAX_SIZE; j++) {
			printf("%d ", c[i][j]);
		}
		printf("\n");
	}

	printf("count : %d", count);

	return 0;
}
