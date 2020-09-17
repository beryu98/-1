#include <stdio.h>
#include <stdlib.h>

//2017111866 황지욱
//본인은 이 소스파일을 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다.

int main() {
    int i, j, k;

    int ary[2][2][3] = {
        {
            {1,2,3},
            {4,5,6}
        },
        {
            {7,8,9},
            {10,11,12}
        }
    };

    int*** ptr = (int***) malloc(sizeof(int**) * 2);

    for (i = 0; i < 2; i++) {
        ptr[i] = (int**) malloc(sizeof(int*) * 2);

        for (j = 0; j < 2; j++) {
            ptr[i][j] = (int*) malloc(sizeof(int*) * 3);

            for (k = 0; k < 3; k++) {
                ptr[i][j][k] = ary[i][j][k];
            }
        }
    }

    printf("ary를 이용한 출력\n");

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            for (k = 0; k < 3; k++) {
                printf("%d ", ary[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }

    printf("\np를 이용한 출력\n");

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            for (k = 0; k < 3; k++) {
                printf("%d ", ptr[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            free(ptr[i][j]);
        }
        free(ptr[i]);
    }

    free(ptr);
}