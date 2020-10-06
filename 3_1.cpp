#include <stdio.h>
#include <stdlib.h>

//2017111866 황지욱
//본인은 이 소스파일을 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다.

int count = 0;

float rsum(float list[], int n) {
	count++;
	if (n) {
		count++;
		return rsum(list, n - 1) + list[n - 1];
	}
	count++;
	return 0;
}

int main() {
	int n, i;
	float s, ary[10];

	scanf_s("%d", &n);

	for (i = 0; i < n; i++) {
		scanf_s("%f", &ary[i]);
	}

	s = rsum(ary, n);

	printf("\n합 : %.4f count : %d", s, count);

	return 0;
}