#include <stdio.h>

//2017111866 Ȳ����
//������ �� �ҽ������� �ٸ� ����� �ҽ��� �������� �ʰ� ���� �ۼ��Ͽ����ϴ�.

int i, j, s;

int sumAry2D_f1(int ary[][3], int row, int col) {
    s = 0;

    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            s += ary[i][j];
        }
    }

    return s;
}

int sumAry2D_f2(int(*ary)[3], int row, int col) {
    s = 0;

    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            s += ary[i][j];
        }
    }

    return s;
}

int sumAry2D_f3(int ary[2][3], int row, int col) {
    s = 0;

    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            s += ary[i][j];
        }
    }

    return s;
}

int main() {
    int ary2D[][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    printf("sumAry2D_f1() %d\n", sumAry2D_f1(ary2D, sizeof(ary2D) / sizeof(ary2D[0]), sizeof(ary2D[0]) / sizeof(int)));
    printf("sumAry2D_f2() %d\n", sumAry2D_f2(ary2D, sizeof(ary2D) / sizeof(ary2D[0]), sizeof(ary2D[0]) / sizeof(int)));
    printf("sumAry2D_f3() %d\n", sumAry2D_f3(ary2D, sizeof(ary2D) / sizeof(ary2D[0]), sizeof(ary2D[0]) / sizeof(int)));
}