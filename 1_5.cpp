#include <stdio.h>

//2017111866 황지욱
//본인은 이 소스파일을 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다.

int i, j, k, s;

int sumAry3D_f1(int ary[][2][3], int SEC, int ROW, int COL) {
    s = 0;

    for (i = 0; i < SEC; i++) {
        for (j = 0; j < ROW; j++) {
            for (k = 0; k < COL; k++) {
                s += ary[i][j][k];
            }
        }
    }

    return s;
}

int sumAry3D_f2(int(*ary)[2][3], int SEC, int ROW, int COL) {
    s = 0;

    for (i = 0; i < SEC; i++) {
        for (j = 0; j < ROW; j++) {
            for (k = 0; k < COL; k++) {
                s += ary[i][j][k];
            }
        }
    }

    return s;
}

int sumAry3D_f3(int ary[2][2][3], int SEC, int ROW, int COL) {
    s = 0;

    for (i = 0; i < SEC; i++) {
        for (j = 0; j < ROW; j++) {
            for (k = 0; k < COL; k++) {
                s += ary[i][j][k];
            }
        }
    }

    return s;
}

int main() {
    int ary3D[][2][3] = {
        {{1, 2, 3}, {4, 5, 6}},
        {{7, 8, 9}, {10, 11, 12}}
    };

    printf("sumAry3D_f1() %d\n", sumAry3D_f1(ary3D, sizeof(ary3D) / sizeof(ary3D[0]), sizeof(ary3D[0]) / sizeof(ary3D[0][0]), sizeof(ary3D[0][0]) / sizeof(int)));
    printf("sumAry3D_f2() %d\n", sumAry3D_f2(ary3D, sizeof(ary3D) / sizeof(ary3D[0]), sizeof(ary3D[0]) / sizeof(ary3D[0][0]), sizeof(ary3D[0][0]) / sizeof(int)));
    printf("sumAry3D_f3() %d\n", sumAry3D_f3(ary3D, sizeof(ary3D) / sizeof(ary3D[0]), sizeof(ary3D[0]) / sizeof(ary3D[0][0]), sizeof(ary3D[0][0]) / sizeof(int)));
}