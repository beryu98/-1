#include <stdio.h>
#include <stdlib.h>

//2017111866 Ȳ����
//������ �� �ҽ������� �ٸ� ����� �ҽ��� �������� �ʰ� ���� �ۼ��Ͽ����ϴ�.

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