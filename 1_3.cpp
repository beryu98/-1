#include <stdio.h>

//2017111866 Ȳ����
//������ �� �ҽ������� �ٸ� ����� �ҽ��� �������� �ʰ� ���� �ۼ��Ͽ����ϴ�.

int i, s;

int sumAry1D_f1(int ary[], int size) {
    s = 0;

    for (i = 0; i < size; i++) {
        s += ary[i];
    }

    return s;
}

int sumAry1D_f2(int* ary, int size) {
    s = 0;

    for (i = 0; i < size; i++) {
        s += ary[i];
    }

    return s;
}

int sumAry1D_f3(int ary[6], int size) {
    s = 0;

    for (i = 0; i < size; i++) {
        s += ary[i];
    }

    return s;
}

int main() {
    int ary1D[] = { 1, 2, 3, 4, 5, 6 };

    printf("sumAry1D_f1() %d\n", sumAry1D_f1(ary1D, sizeof(ary1D) / sizeof(int)));
    printf("sumAry1D_f2() %d\n", sumAry1D_f2(ary1D, sizeof(ary1D) / sizeof(int)));
    printf("sumAry1D_f3() %d\n", sumAry1D_f3(ary1D, sizeof(ary1D) / sizeof(int)));
}