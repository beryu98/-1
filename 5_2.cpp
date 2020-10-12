#include <stdio.h>
#include <stdlib.h>

//2017111866 황지욱
//본인은 이 소스파일을 복사 없이 직접 작성하였습니다.

#define MALLOC1(p,s) \
	if(!((p) = (int***) malloc(s))) {\
		fprintf(stderr, "insufficient memory");\
		exit (EXIT_FAILURE);\
	}

#define MALLOC2(p,s) \
	if(!((p) = (int**) malloc(s))) {\
		fprintf(stderr, "insufficient memory");\
		exit (EXIT_FAILURE);\
	}

#define MALLOC3(p,s) \
	if(!((p) = (int*) malloc(s))) {\
		fprintf(stderr, "insufficient memory");\
		exit (EXIT_FAILURE);\
	}

int i, j, k, s;

int sumAry3D_f1(int ary[][3][4], int SEC, int ROW, int COL) {
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

int sumAry3D_f2(int(*ary)[3][4], int SEC, int ROW, int COL) {
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

int sumAry3D_f3(int ary[2][3][4], int SEC, int ROW, int COL) {
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

int sumAry3D_f4(int*** ary, int SEC, int ROW, int COL) {

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

int sumAry3D_f5(int**** ary, int SEC, int ROW, int COL) {

    s = 0;

    for (i = 0; i < SEC; i++) {
        for (j = 0; j < ROW; j++) {
            for (k = 0; k < COL; k++) {
                s += *(*(*(*ary + i) + j) + k);
            }
        }
    }

    return s;
}

void freeAry3D(int*** ary, int a, int b) {

    for (i = 0; i < a; i++) {
        for (j = 0; j < b; j++) {
            free(ary[i][j]);
        }
        free(ary[i]);
    }

    free(ary);

    printf("3d array - free!");
}

int main() {
    int ary3D[][3][4] = { {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}},
                         {{13, 14, 15, 16}, {17, 18, 19, 20}, {21, 22, 23, 24}} };

    int*** ary = (int***)malloc(sizeof(int**) * 2);
    MALLOC1(ary, sizeof(int**) * 2);

    for (i = 0; i < 2; i++) {
        ary[i] = (int**)malloc(sizeof(int*) * 3);
        MALLOC2(ary[i], sizeof(int*) * 3);
        for (j = 0; j < 3; j++) {
            ary[i][j] = (int*)malloc(sizeof(int) * 4);
            MALLOC3(ary[i][j], sizeof(int) * 4);
        }
    }

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 3; j++) {
            for (k = 0; k < 4; k++) {
                ary[i][j][k] = i + j + k;
            }
        }
    }

    printf("sumAry2D_f1() %d\n", sumAry3D_f1(ary3D, 2, 3, 4));
    printf("sumAry2D_f2() %d\n", sumAry3D_f2(ary3D, 2, 3, 4));
    printf("sumAry2D_f3() %d\n", sumAry3D_f3(ary3D, 2, 3, 4));

    printf("sumAry2D_f4() %d\n", sumAry3D_f4(ary, 2, 3, 4));
    printf("sumAry2D_f5() %d\n", sumAry3D_f5(&ary, 2, 3, 4));

    freeAry3D(ary, 2, 3);

    return 0;
}
