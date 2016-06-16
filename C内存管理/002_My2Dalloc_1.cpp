/* ��Ŀ��ʹ��C���Է�ʽ��malloc��̬���ٶ�ά���飬���ͷŶ�ά���顣
 * TIME��2015-5-5
 */
#include <stdio.h>
#include <stdlib.h>

/* ��δ���ȽϹ��죬�����ٵ�һ���������ڴ��Ŷ�ά���飬����int a[5][3]
 * [][][][][]|[][][]|[][][]|[][][]|[][][]|[][][]
 * ǰ���5��Ϊint*����, �ֱ�ָ������5�Σ�ÿ�γ���sizeof(int)*3
 * ����֮�����ڲ���Ҫר�ű�дfree����
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