/* ��Ŀ��ʹ��C���Է�ʽ��malloc��̬���ٶ�ά���飬���ͷŶ�ά���顣
 * TIME��2015-5-5
 */
#include <stdio.h>
#include <stdlib.h>

/* �ȿ���һ���ڴ�ָ������ָ��
 * �ٿ�������������ָ��ָ����ڴ��
 */
int** My2Dalloc(int rows, int cols)
{
	int **p;
	/* pָ��һ��Ԫ��Ϊָ�������
	 * �����ڴ�����Ϊint*
	 */
	p = (int **)malloc(sizeof(int*) * rows);

	/* ָ�������е�ÿ��Ԫ����ָ��һ������ */
	for (int i = 0; i < rows; i++)
		*(p+i) = (int *)malloc(sizeof(int)*cols);
	return p;
}

void My2Dfree(int **p, int rows)
{
	/* �����ͷ�ָ������Ԫ��ָ������� */
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