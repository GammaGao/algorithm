/* 题目：使用C语言方式用malloc动态开辟二维数组，和释放二维数组。
 * TIME：2015-5-5
 */
#include <stdio.h>
#include <stdlib.h>

/* 先开劈一段内存指向数组指针
 * 再开辟若干由上述指针指向的内存块
 */
int** My2Dalloc(int rows, int cols)
{
	int **p;
	/* p指向一个元素为指针的数组
	 * 开劈内存类型为int*
	 */
	p = (int **)malloc(sizeof(int*) * rows);

	/* 指针数组中的每个元素又指向一个数组 */
	for (int i = 0; i < rows; i++)
		*(p+i) = (int *)malloc(sizeof(int)*cols);
	return p;
}

void My2Dfree(int **p, int rows)
{
	/* 依次释放指针数组元素指向的数组 */
	for (int i = 0; i < rows; i++){
		free(*(p+i));
	}
	free(p);
}
int main()
{
	int rows = 5, cols = 3;
	int value = 0;
	int **array;
	array = My2Dalloc(rows, cols);
	for (int i = 0; i < rows; i++){
		for (int j = 0; j < cols; j++){
			array[i][j] = value++;
		}
	}
	for (int i = 0; i < rows; i++){
		for (int j = 0; j < cols; j++)
			printf("%d ", array[i][j]);
		printf("\n");
	}
	My2Dfree(array, rows);
	system("pause");
}