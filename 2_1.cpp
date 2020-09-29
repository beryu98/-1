#include <stdio.h>
#include <stdlib.h>

//2017111866 Ȳ����
//������ �� �ҽ������� �ٸ� ����� �ҽ��� �������� �ʰ� ���� �ۼ��Ͽ����ϴ�.

int t;

void swap1(int a, int b) {
	t = a;
	a = b;
	b = t;
}

void swap2(int* a, int* b) {
	t = *a;
	*a = *b;
	*b = t;

}

void swap3(int** a, int** b) {
	t = **a;
	**a = **b;
	**b = t;
}

int main() {
	int a, b;

	int* pa = &a;
	int** ppa = &pa;

	int* pb = &b;
	int** ppb = &pb;

	a = 1; b = 2; swap1(a, b);
	printf("After calling swap1(a, b), a : %d, b : %d\n\n", a, b);

	a = 1; b = 2; swap2(&a, &b);
	printf("After calling swap2(&a, &b), a : %d, b : %d\n\n", a, b);
	
	a = 1; b = 2; swap2(pa, pb);
	printf("After calling swap2(pa, pb), a : %d, b : %d\n\n", a, b);
	
	a = 1; b = 2; swap3(&pa, &pb);
	printf("After calling swap3(&pa, &pb), a : %d, b : %d\n\n", a, b);
	
	a = 1; b = 2; swap3(ppa, ppb);
	printf("After calling swap3(ppa, ppb), a : %d, b : %d\n\n", a, b);

	return 0;
}