#include <stdio.h>
#include <stdlib.h>

//2017111866 Ȳ����
//������ �� �ҽ������� �ٸ� ����� �ҽ��� �������� �ʰ� ���� �ۼ��Ͽ����ϴ�.

#define MALLOCI(p,s) \
	if(!((p) = (int*) malloc(s))) {\
		fprintf(stderr, "insufficient memory");\
		exit (EXIT_FAILURE);\
	}

void func(int num) {
	int* pNum = (int*)malloc(sizeof(int));
	MALLOCI(pNum, sizeof(int));
	*pNum = num;
	printf("%d\n", *pNum);
	free(pNum);
}

int main() {
	int num = 1;
	func(num);
	printf("%d\n", num);

	return 0;
}