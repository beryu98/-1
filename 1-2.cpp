#include <stdio.h>
#include <stdlib.h>

//2017111866 Ȳ����
//������ �� �ҽ������� �ٸ� ����� �ҽ��� �������� �ʰ� ���� �ۼ��Ͽ����ϴ�.

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

    printf("ary�� �̿��� ���\n");

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", ary[i][j]);
        }
        printf("\n");
    }

    printf("\np�� �̿��� ���\n");

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