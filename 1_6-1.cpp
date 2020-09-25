#include <stdio.h>
#include <stdlib.h>

//2017111866 황지욱
//본인은 이 소스파일을 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다.

int main() {
	int i, * pi;
	float f, * pf;
	int p;

	if (!((pi = (int*) malloc(sizeof(int)))) ||
		!((pf = (float*) malloc(sizeof(float))))){
		fprintf(stderr, "Insufficient memory");
		exit(EXIT_FAILURE);
	}

	*pi = 1024;
	*pf = 3.14;

	printf("an integer = %d, a float =  %f\n", *pi, *pf);

	free(pi);
	free(pf);
}