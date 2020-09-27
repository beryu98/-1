#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//2017111866 황지욱
//본인은 이 소스파일을 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다.

void swap(int *a, int n) {
    int i, j;
    int t;

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (*(a + i) > * (a + j)) {
                t = *(a + i);
                *(a + i) = *(a + j);
                *(a + j) = t;
            }
        }
    }
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

}

void compare(int ary[], int a, int b) {
    int f = 0;
    int l = a - 1;
    int m;

    while (f <= l) {
        m = (f + l) / 2;
        if (f > l) {
            break;
        }
        else {
            if (ary[m] == b) {
                printf("\n The search number is present in list[%d]", m);
                break;
            }
            else {
                if (ary[m] > b) {
                    l = m - 1;
                }
                else {
                    f = m + 1;
                }
            }
        }
    }

    printf("\nThe search nuber is not present ");
}

int main() {
    int n, i, s;

    printf("Enter the number of numbers to generate : ");
    while (1) {
        scanf_s("%d", &n);
        if (n > 100) {
            printf("100보다 작은 수를 입력해 주세요\nEnter the number of numbers to generate : ");
        }
        else {
            break;
        }
    }

    int *ary = (int*) malloc(sizeof(int*) * n);

    srand(time(NULL));

    for (i = 0; i < n; i++) {
        ary[i] = rand() % 1000;
        printf("%d ", ary[i]);
    }

    printf("\nsorted array:\n");

    swap(ary, n);

    printf("\nEnter the number to search : ");
    scanf_s("%d", &s);

    compare(ary, n, s);
}