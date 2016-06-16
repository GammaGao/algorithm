#include <stdio.h>
#include <stdlib.h>

#define ROW 6 
#define COL 6
#define EXIT_ROW (ROW-2)
#define EXIT_COL (COL-2)
#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))
//迷宫布局
short int maze[ROW][COL] = {1, 1, 1, 1, 1, 1,//0为通道，1为墙
		            1, 0, 0, 1, 0, 1,
		            1, 1, 0, 0, 0, 1,
		            1, 0, 1, 0, 1, 1,
			    1, 0, 0, 0, 0, 1,
		            1, 1, 1, 1, 1, 1};
short int mark[ROW][COL]; //用1标记访问过的位置, 保证不会被重复访问

int top; //栈顶
typedef struct {
	short int row;
	short int col;	
	short int dir;
}element;
element stack[ROW*COL];//顺序栈

typedef struct {
	short int vert;
	short int horiz;
}offsets;
/* 方向矢量 */
offsets move[] = {{-1, 0}, //北
	//	   {-1, 1}, //东北
		   { 0, 1}, //东
	//	   { 1, 1}, //东南
		   { 1, 0}, //南
	//	   {1, -1}, //西南
		   {0, -1}, //西
	//	   {-1, -1} //西北
		  };

void push(element position)
{
    if(top == ROW*COL-1) {
	fprintf(stderr, "stack full\n"); 
	exit(EXIT_FAILURE);
    }
    stack[++top] = position; 
}

element pop() {
    if(top == -1) {
	fprintf(stderr, "stack empty\n"); 
	exit(EXIT_FAILURE);
    }
    return stack[top--];
}

void path()
{
	int row, col, nextRow, nextCol, dir, found = 0;
	element position;

	mark[1][1] = 1;//迷宫入口
	top = 0; //第一个元素入口
	stack[top].row = 1;
	stack[top].col = 1;
	stack[top].dir = 1;

	while(top > -1 && !found) { 
	    //获取stack[top]
		position = pop();
		row = position.row;
		col = position.col;
		dir = position.dir;
		
		while(dir < ARRAY_SIZE(move) && !found) {//顺时针扫描方位
		    nextRow = row + move[dir].vert;
		    nextCol = col + move[dir].horiz;
		    if(nextRow == EXIT_ROW && nextCol == EXIT_COL){ //找到出口 
			position.row = row; //找到出口前的最后一次入栈
			position.col = col;
			position.dir = ++dir;
			push(position);
			position.row = nextRow; //出口也入栈
		        position.col = nextCol;
			push(position);
			found = 1;
			position.dir = ++dir;break;
		    }
		    else if(!maze[nextRow][nextCol] && !mark[nextRow][nextCol]) { //非墙, 可深入进去
			mark[nextRow][nextCol] = 1;
			position.row = row;
			position.col = col;
			position.dir = ++dir;
			push(position);
			row = nextRow;
			col = nextCol;
			dir = 0;
		    }
		    else {//非出口，而且是墙
			++dir;
		    }
//		    printf("row:%d, col:%d, dir:%d\n", row, col,dir);
		}
	}
	printf("found:%d, top:%d\n", found, top);
	if(found) {
	    printf("the path is:\n");
	    printf("row col:\n");
	    for(int i = 0; i <= top; i++) {
		printf("%2d%5d\n", stack[i].row, stack[i].col); 
	    }
	}
}

int main()
{
	path();
	return 0;
}
