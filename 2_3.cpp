#include <stdio.h>
#include <stdlib.h>

//2017111866 Ȳ����
//������ �� �ҽ������� �ٸ� ����� �ҽ��� �������� �ʰ� ���� �ۼ��Ͽ����ϴ�.

#define MALLOCI(p,s) \
	if(!((p) = (int*) malloc(s))) {\
		fprintf(stderr, "insufficient memory");\
		exit (EXIT_FAILURE);\
	}


int *func1() {
	int* pNum = (int*)malloc(sizeof(int));
	MALLOCI(pNum, sizeof(int));

	*pNum = 0;

	return pNum;
}

int *func2(int* pNum) {
	*pNum = 100;
	return pNum;
}

int **func3(int** pNum) {
	**pNum = 200;
	return pNum;
}

int main() {
	int* pNum = func1();
	printf("%d\n", *pNum);
	printf("%d\n", *func2(pNum));
	printf("%d\n", **func3(&pNum));
	free(pNum);

	return 0;
}