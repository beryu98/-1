#include <stdio.h>
#include <stdlib.h>

//2017111866 황지욱
//본인은 이 소스파일을 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다.

#define MALLOCI(p,s) \
	if(!((p) = (int*) malloc(s))) {\
		fprintf(stderr, "insufficient memory");\
		exit (EXIT_FAILURE);\
	}

#define MALLOCF(p,s) \
	if(!((p) = (float*) malloc(s))) {\
		fprintf(stderr, "insufficient memory");\
		exit (EXIT_FAILURE);\
	}

int main() {
	int i, * pi;
	float f, * pf;

	MALLOCI(pi, sizeof(int));
	MALLOCF(pf, sizeof(float));

	*pi = 1024;
	*pf = 3.14;

	printf("%d, %f\n", *pi, *pf);

	free(pi);
	free(pf);
}