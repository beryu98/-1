#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//2017111866 Ȳ����
//������ �� �ҽ������� �ٸ� ����� �ҽ��� �������� �ʰ� ���� �ۼ��Ͽ����ϴ�.

int i = 0;

void input(int* pNum, int num, FILE* fpIn) {

	for (i = 0; i < num; i++) {
		fscanf_s(fpIn, "%d", &*(pNum+i));
	}
}

void increase(int* pNum, int num) {
	
	for (i = 0; i < num; i++) {
		*(pNum + i) = *(pNum + i) + 1;
	}
}

void output(int* pNum, int num, FILE* fpOut) {
	
	fprintf(fpOut, "%d\n", num);

	for (i = 0; i < num; i++) {
		fprintf(fpOut, "%d ", *pNum + i);
	}
}


int main() {
	int num, * pNum;

	FILE* fpIn = fopen("c:\\input.txt", "r");
	FILE* fpOut = fopen("c:\\output.txt", "w");

	fscanf_s(fpIn, "%d\n", &num);
	pNum = (int*) malloc(sizeof(int)*num);
	input(pNum, num, fpIn);
	increase(pNum, num);
	output(pNum, num, fpOut);

	free(pNum);
	fclose(fpIn);
	fclose(fpOut);

	return 0;
}