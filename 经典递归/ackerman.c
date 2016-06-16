#include <stdio.h>
#define N 10

#if 0
int ackerman(int m, int n)
{
	int i, j, a[N][N] = {0};
	for (j = 0; j < N; j++){
		
		a[0][j] = j + 1;
	}
	for (i = 1; i < N; i++){
		a[i][0] = a[i-1][1];
		for (j = 1; j < N; j++){
			a[i][j] = a[i-1][a[i][j-1]];
		}
	}
	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++){
			printf("%d ", a[i][j]);
		}
		putchar('\n');
	}
	return a[m][n];
}
#endif

int main()
{
	int m, n;
	printf("Enter m and n:");
	scanf("%d%d", &m, &n);
	printf("%d\n", ackerman(m, n));
}
