#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//2017111866 Ȳ����
//������ �� �ҽ������� �ٸ� ����� �ҽ��� �������� �ʰ� ���� �ۼ��Ͽ����ϴ�.
#define MALLOC(p,s) \
	if(!((p) = malloc(s))) {\
		fprintf(stderr, "insufficient memory");\
		exit (EXIT_FAILURE);\
	}

int t ,i ,j;

#define SWAP(a,b) {\
    for (i = 0; i < n-1; i++) {\
        for (j = 1; j < n; j++) {\
           if (ary[i] > ary[j]) {\
                t = a;  \
                a = b;  \
                b = t;  \
            }\
        }\
    }\
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
    int n, s;

    printf("Enter the number of numbers to generate : ");
    while (1) {
        scanf_s("%d", &n);
        if (n > 100) {
            printf("100���� ���� ���� �Է��� �ּ���\nEnter the number of numbers to generate : ");
        }
        else {
            break;
        }
    }

    int* ary = (int*)malloc(sizeof(int*) * n);

    srand(time(NULL));

    for (i = 0; i < n; i++) {
        ary[i] = rand() % 1000;
        printf("%d ", ary[i]);
    }

    printf("\nsorted array:\n");

    for (i = 0; i < n; i++) {
        printf("%d ", ary[i]);
    }

    printf("Enter the number to search : ");
    scanf_s("%d", &s);

    compare(ary, n, s);
}