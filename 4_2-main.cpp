#include <stdio.h>
#include <time.h>
#include "2-selectionSort.h"
#define MAX_SIZE 2001
#define _CRT_SECURE_NO_WARNINGS

//2017111866 황지욱
//본인은 이 소스파일을 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다.

int main() {
	int i, n, step = 10;
	int a[MAX_SIZE];
	double duration;
	FILE* out2 = fopen("c:\\out2.txt", "w");

	printf("     n	        repetitions	          time\n");
	fprintf(out2,"     n	            repetitions	       time\n");
	for (n = 0; n <= 2000; n += step) {
		long repetitions = 0;
		clock_t start = clock();
		do {
			repetitions++;
			for (i = 0; i < n; i++) {
				a[i] = n - i;
			}
			sort(a, n);
		} while (clock() - start < 1000);

		duration =  (double)clock() - (double)start / CLOCKS_PER_SEC;
		duration /= repetitions;
		printf("%6d		%9ld		%f\n", n, repetitions, duration);
		fprintf(out2, "%6d		%9ld               %f\n", n, repetitions, duration);
		if (n == 100) {
			step = 100;
		}
	}

	fclose(out2);
}
