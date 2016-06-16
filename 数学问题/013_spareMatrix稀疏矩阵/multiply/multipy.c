#include <stdio.h>
#include <stdlib.h>
#define MAX_ROW		6
#define MAX_COL 	6
#define MAX_TERMS 	10
#define COMPARE()

typedef struct {
	int col;
	int row;
	int value;
} term;

void fastTranspose(term a[], term b[])
{
	int i, j, n;
	int row_nozero_num[MAX_COL], startingPos[MAX_COL];
	
	b[0].row = a[0].col;
	b[0].col = a[0].row;
	b[0].value = a[0].value;
	
	if(!a[0].value) { //non zero matrix
		printf("the matrix is zero matrix\n");	
		return;
	}

	for(i = 0; i < a[0].col; i++) {
		row_nozero_num[i] = 0; //转置后每行非零的个数
	}
	for(i = 1; i <= a[0].value; i++) {
		row_nozero_num[a[i].col]++; //统计
	}

	startingPos[0] = 1;
	for(i = 1; i <= a[0].col; i++) {
		startingPos[i] = startingPos[i-1] + row_nozero_num[i-1]; 
	}
	for(i = 1; i <= a[0].value; i++) {
		j = startingPos[a[i].col]++;
		b[j].value = a[i].value;
		b[j].row = a[i].col;
		b[j].col = a[i].row;
	}	
}

void storeSum(term d[], int *totalD, int row, int col, int *sum)
{
	if(*sum)
		if(*totalD < MAX_TERMS) {
			d[++*totalD].row = row;
			d[*totalD].col = col;
			d[*totalD].value = *sum;
			*sum = 0;
		}else {
			fprintf(stderr, "Numbers of terms in produce execeeds\n", MAX_TERMS);
			exit(EXIT_FAILURE);
		}
	
}

/*
 * 稀疏矩阵相乘
 */
void mmult(term a[], term b[], term d[]) 
{
	int i, j, col, sum = 0;
	int rowsA = a[0].row, colsA = a[0].col;
	int colsB = b[0].col, rowsB = b[0].row;
	int totalA = a[0].value, totalB=b[0].value, totalD = 0;
	int rowBegin = 1, row = a[1].row;
	term newB[MAX_TERMS];

	if(colsA != rowsB) { //矩阵相乘的条件
		fprintf(stderr, "Incompatible matrices\n");
		exit(EXIT_FAILURE);
	}

	fastTranspose(b, newB);
	//a[totalA+1].row = rowsA;
	for(i = 1; i <= totalA;) {
		for(j = 1; j < totalB;) {
			if(a[i].row != row) {
				storeSum(d, &totalD, row, col, &sum);	
				i = rowBegin;
				for(; newB[j].row == col; j++);
				col = newB[j].row;
			}else if (newB[j].col != col) {
				storeSum(d, &totalD, row, col, &sum);
				i = rowBegin; 
				col = newB[j].row;
			}else {
				switch(COMPARE(a[i].col, newB[j].col)) {
					case -1:
						i++;
						break;
					case 0:
						sum += (a[i++].value * newB[j++].value);
						break;
					case 1:
						j++;
				}
				for(; a[i].row == row; i++);
				rowBegin = 1; row = a[i].row;
			}
			d[0].row = rowsA; 
			d[0].col = colsB;
			d[0].value = totalD;
		}
	}
}

int main()
{
	int i, j, n;
	int array[MAX_ROW][MAX_COL];
	term a[MAX_TERMS], b[MAX_TERMS];

	a[0].row = MAX_ROW; 	//稀疏矩阵中行个数
	a[0].col = MAX_COL;     //稀疏矩阵中列个数
	a[0].value = 0;		//稀疏矩阵中非0元素个数
	printf("输入稀疏矩阵:\n");
	for(i = 0; i < MAX_ROW; i++) {
		for(j = 0; j < MAX_COL; j++) {
			scanf("%d", &array[i][j]);
		}
	} 

	n = 1; 
	for(i = 0; i < MAX_ROW; i++) {   /* 按矩阵行扫 */
		for(j = 0; j < MAX_COL; j++)
			if(array[i][j]) {
				a[0].value++;
				a[n].row = i;
				a[n].col = j;
				a[n].value = array[i][j];
				n++;
		}
	} 
	transpose(a, b); 

#if 1
	for(i = 0; i < MAX_ROW; i++) {
		for(j = 0; j < MAX_COL; j++)
			printf("%-2d ", array[i][j]);
		putchar('\n');
	}	
#endif 

	printf("转置输出:\n");
#if 1	
	for(i = 0; i < n; i++) {
		printf("%d %d %d\n", b[i].row, b[i].col, b[i].value);
	}
#endif
	return 0;	
}
