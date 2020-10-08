#include <stdio.h>
#include <time.h>
#include "1-selectionSort.h"
#define MAX_SIZE 2001
#define _CRT_SECURE_NO_WARNINGS

//2017111866 황지욱
//본인은 이 소스파일을 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다.

int main() {
	int i, n, step = 10;
	int a[MAX_SIZE];
	double duration;
	clock_t start;
	FILE* out1 = fopen("c:\\out1.txt", "w");

	printf("     n	        time\n");
	fprintf(out1, "     n	            time\n");
	for (n = 0; n <= 2000; n += step) {
		for (i = 0; i < n; i++) {
			a[i] = n - i;
		}

		start = clock();
		sort(a, n);

		duration = (double)clock() - (double)start / CLOCKS_PER_SEC;
		printf("%6d		%f\n", n, duration);
		fprintf(out1, "%6d		%f\n", n, duration);
		if (n == 100) {
			step = 100;
		}
	}

	fclose(out1);
}

