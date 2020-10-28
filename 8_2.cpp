#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#define MAX_STACK_SZIE 100
#define TRUE 1
#define FALSE 0
#define MAX_MAZE_SIZE 10

//2017111866 황지욱
//본인은 이 소스파일을 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다.

int EXIT_ROW, EXIT_COL;
int mark[MAX_MAZE_SIZE][MAX_MAZE_SIZE];
int maze[MAX_MAZE_SIZE][MAX_MAZE_SIZE];

typedef struct {
	short int vert;
	short int horiz;
}offsets;
offsets move[8];

void move_make() {
	move[0].vert = -1;
	move[0].horiz = 0;
	move[1].vert = -1;
	move[1].horiz = 1;
	move[2].vert = 0;
	move[2].horiz = 1;
	move[3].vert = 1;
	move[3].horiz = 1;
	move[4].vert = 1;
	move[4].horiz = 0;
	move[5].vert = 1;
	move[5].horiz = -1;
	move[6].vert = 0;
	move[6].horiz = -0;
	move[7].vert = -1;
	move[7].horiz = -1;
}

typedef struct {
	short int row;
	short int col;
	short int dir;
}element;

element stack[MAX_STACK_SZIE];
int top = -1;

element stackEmpty() {
	element s;
	fprintf(stderr, "stack is empty, cannot delete elemnt\n");
	exit(EXIT_FAILURE);

	return s;
}

element pop() {
	if (top == -1) {
		return stackEmpty();
	}
	return stack[top--];
}

void stackFull() {
	element s;

	fprintf(stderr, "stack is full, cannot add elemnt\n");
	fprintf(stderr, "current stack elemnets :\n");
	exit(EXIT_FAILURE);
}

void push(element item) {
	if (top >= MAX_STACK_SZIE - 1) {
		stackFull();
	}
	stack[++top] = item;
}

void path() {
	int i, row, col, nextRow, nextCol, dir, found = FALSE;
	element position;
	mark[1][1] = 1;
	top = 0;
	stack[0].row = 1;
	stack[0].col = 1;
	stack[0].dir = 1;
	while (top > -1 && !found) {
		position = pop();
		row = position.row;
		col = position.col;
		dir = position.dir;
		while (dir < 8 && !found) {
			nextRow = row + move[dir].vert;
			nextCol = col + move[dir].horiz; 
			if (nextRow == EXIT_ROW && nextCol == EXIT_COL) {
				found = TRUE;
			}
			else if (!maze[nextRow][nextCol] && !mark[nextRow][nextCol]) {
				mark[nextRow][nextCol] = 1;
				position.row = row;
				position.col = col;
				position.dir = ++dir;
				push(position);
				row = nextRow;
				col = nextCol;
				dir = 0;
			}
			else {
				++dir;
			}
		}
	}
	if (found) {
		printf("The path is :\n");
		printf("row col\n");
		for (i = 0; i <= top; i++) {
			printf("%2d%5d\n", stack[i].row, stack[i].col);
		}
		printf("%2d%5d\n", row, col);
		printf("%2d%5d\n", EXIT_ROW, EXIT_COL);
	}
	else {
		printf("The maze does not have a path\n");
	}
}

void makemaze(FILE* input, int x, int y) {
	int i, j;
	for (i = 0; i < x + 2; i++) {
		maze[i][0] = 1;
		maze[i][y + 1] = 1;
		mark[i][0] = 1;
		mark[i][y + 1] = 1;
	}
	for (i = 0; i < y + 2; i++) {
		maze[0][i] = 1;
		maze[x + 1][i] = 1;
		mark[0][i] = 1;
		mark[x + 1][i] = 1;
	}
	for (i = 1; i <= x; i++) {
		for (j = 1; j <= y; j++) {
			fscanf_s(input, "%d", &maze[i][j]);
		}

	}
}

int main() {
	FILE* input = fopen("c:\\input.txt", "r");
	
	fscanf_s(input, "%d %d", &EXIT_ROW, &EXIT_COL);
	move_make();
	makemaze(input, EXIT_ROW, EXIT_COL);
	
	fclose(input);

	path();

	
}

