#include <stdio.h>
#include <stdlib.h>

//2017111866 Ȳ����
//������ �� �ҽ������� �ٸ� ����� �ҽ��� �������� �ʰ� ���� �ۼ��Ͽ����ϴ�.

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

	printf("\n�� : %.4f count : %d", s, count);

	return 0;
}