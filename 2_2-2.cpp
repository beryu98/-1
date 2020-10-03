#include <stdio.h>
#include <stdlib.h>

//2017111866 황지욱
//본인은 이 소스파일을 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다.

#define MALLOCI(p,s) \
	if(!((p) = (int*) malloc(s))) {\
		fprintf(stderr, "insufficient memory");\
		exit (EXIT_FAILURE);\
	}

int *func(int num) {
	int* pNum = (int*)malloc(sizeof(int));
	MALLOCI(pNum, sizeof(int));
	*pNum = num;
	printf("%d\n", *pNum);
	return pNum;
}

int main() {
	int num = 1;
	int* pNum = func(num);
	printf("%d\n", num);
	free(pNum);

	return 0;
}