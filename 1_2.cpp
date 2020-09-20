#include <stdio.h>

//2017111866 황지욱
//본인은 이 소스파일을 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다.

int main() {
    int a = 2, b = 3, c = 4;
    int* ary[3] = { &a, &b, &c };

    printf("포인터 배열의 배열요소를 이용한 a, b, c 출력\n");
    printf("a : %d, b : %d, c : %d", *ary[0], *ary[1], *ary[2]);

}