#include<stdio.h>
#include<stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

#define MAX_TERMS 101
#define MAX_COL 11

typedef struct {
	int r;
	int c;
	int v;
}term;

term a[MAX_TERMS];
term b[MAX_TERMS];

void fastTranspose(term a[], term b[])
{
	int rt[MAX_COL], sp[MAX_COL];
	int i, j, numC = a[0].c, numT = a[0].v;
	b[0].r = a[0].c; b[0].c = a[0].r; b[0].v = a[0].v;
	if (numT > 0)
	{
		for (i = 0; i < numC; i++)
		{
			rt[i] = 0;
		}
		for (i = 1; i <= numT; i++)
		{
			rt[a[i].c]++;
		}
		sp[0] = 1;
		for (i = 1; i < numC; i++)
		{
			sp[i] = sp[i - 1] + rt[i - 1];
		}
		for (i = 1; i <= numT; i++)
		{
			j = sp[a[i].c]++;
			b[j].r = a[i].c;
			b[j].c = a[i].r;
			b[j].v = a[i].v;
		}
	}
}

void printm(term a[])
{
	int i, j, n = 1;
	for (i = 0; i < a[0].r; i++)
	{
		for (j = 0; j < a[0].c; j++)
		{
			if (i == a[n].r && j == a[n].c)
			{
				printf("%d\t", a[n].v);
				n++;
			}
			else
			{
				printf("0\t");
			}
		}
		printf("\n");
	}
}

int main()
{
	FILE* input = fopen("c:\\a.txt", "r");
	FILE* output = fopen("c:\\b.txt", "w");
	int i;
	fscanf_s(input, "%d %d %d\n", &a[0].r, &a[0].c, &a[0].v);
	if (a[0].v > 10)
	{
		printf("Too many!!\n");
		return 0;
	}
	else
	{
		for (i = 1; i <= a[0].v; i++)
		{
			fscanf_s(input, "%d %d %d\n", &a[i].r, &a[i].c, &a[i].v);
		}
	}

	printf("A\n");
	printm(a);

	fastTranspose(a, b);

	for (i = 0; i < b[0].v + 1; i++)
	{
		fprintf(output, "%d %d %d\n", b[i].r, b[i].c, b[i].v);
	}

	printf("\nB\n");
	printm(b);

	fclose(input);
	fclose(output);

	return 0;
}