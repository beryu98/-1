#include <stdio.h>
#include <stdlib.h>

//2017111866 Ȳ����
//������ �� �ҽ������� �ٸ� ����� �ҽ��� �������� �ʰ� ���� �ۼ��Ͽ����ϴ�.

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

    printf("ary�� �̿��� ���\n");

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            for (k = 0; k < 3; k++) {
                printf("%d ", ary[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }

    printf("\np�� �̿��� ���\n");

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