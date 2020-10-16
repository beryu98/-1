#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define FALSE 0
#define TRUE 1
#define MAX_SIZE 20

//2017111866 황지욱
//본인은 이 소스파일을 복사 없이 직접 작성하였습니다.

typedef struct {
	char name[MAX_SIZE];
	int age;
	float salary;
} humanBeing;

int humansEqual(humanBeing person1, humanBeing person2) {
	if (strcmp(person1.name, person2.name)) return FALSE;
	if (person1.age != person2.age) return FALSE;
	if (person1.salary != person2.salary) return FALSE;

	return TRUE;
}

int main() {
	humanBeing p1, p2;
	char n[10];

	printf("Input person1's name, age, salary : \n");
	scanf_s("%[^\n]s", &p1.name, MAX_SIZE);
	scanf_s("%d", &p1.age);
	scanf_s("%f", &p1.salary);

	rewind(stdin);

	printf("Input person2's name, age, salary : \n");
	scanf_s("%[^\n]s", &p2.name, MAX_SIZE);
	scanf_s("%d", &p2.age);
	scanf_s("%f", &p2.salary);

	rewind(stdin);

	if (humansEqual(p1, p2)) {
		printf("The two human beings are the same\n");
	}
	else {
		printf("The two human beings are not the same\n");
	}
}