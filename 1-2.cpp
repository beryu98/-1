#include <stdio.h>
#include <stdlib.h>

//2017111866 황지욱
//본인은 이 소스파일을 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다.

int main() {
    int i, j;

    int ary[2][3] = {
        {4,2,3},
        {5,2,3}
    };

    int** ptr = (int**)malloc(sizeof(int*) * 2);

    for (i = 0; i < 2; i++) {
        ptr[i] = (int*) malloc(sizeof(int) * 3);

        for (j = 0; j < 3; j++) {
            ptr[i][j] = ary[i][j];
        }
    }

    printf("ary를 이용한 출력\n");

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", ary[i][j]);
        }
        printf("\n");
    }

    printf("\np를 이용한 출력\n");

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", ptr[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < 2; i++) {
        free(ptr[i]);
    }

    free(ptr);
}