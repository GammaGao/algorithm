#include <stdio.h>

#define MAX_ROW		6
#define MAX_COL 	6
#define MAX_TERMS 	10 

typedef struct {
	int col;
	int row;
	int value;
} term;

/*
 * 稀疏矩阵转置算法，渐近时间复杂度O(列数＊非0元素个数)
 */
void transpose(term a[], term b[])
{
	int i, j, n;
	
	b[0].row = a[0].col;
	b[0].col = a[0].row;
	b[0].value = a[0].value;
	
	if(!a[0].value) { //non zero matrix
		printf("the matrix is zero matrix\n");	
		return;
	}

#if 0	
	//O(列数＊非0元素个数)
	for(i = 0; i < a[0].col; i++) { //按列扫
		for(j = 1; j <= a[0].value; j++) {
			if(a[j].col == i) { //
				b[j].value = a[j].value;
				b[j].row = a[j].col;
				b[j].col = a[j].row;
			}
		}
	}		
#endif
	//O(非0元素个数)
	for(j = 1; j <= a[0].value; j++) {
		b[j].value = a[j].value;
		b[j].row = a[j].col;
		b[j].col = a[j].row;
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
