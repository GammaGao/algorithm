/* 题目：使用C语言方式用malloc动态开辟二维数组，和释放二维数组。
 * TIME：2015-5-5
 */
#include <stdio.h>
#include <stdlib.h>

/* 这段代码比较怪异，它开辟的一段连续的内存存放二维数组，例如int a[5][3]
 * [][][][][]|[][][]|[][][]|[][][]|[][][]|[][][]
 * 前面的5个为int*类型, 分别指向后面的5段，每段长度sizeof(int)*3
 * 优势之处在于不需要专门编写free函数
 */
int **My2Dalloc(int rows, int cols)
{
	int head_size = rows * sizeof(int *);
	int data_size = rows * cols * sizeof(int);
	int **p;
	p = (int **)malloc(head_size + data_size);
	if (p == NULL)
		return NULL;

	int *buf = (int *)(p + rows);
	for (int i = 0; i < rows; i++)
		*(p + i) = buf + cols * i;
	return p;
}

void My2Dfree(int **p)
{
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
	My2Dfree(array);
	system("pause");
}