#include <stdio.h>

void hannoi(int n, char a, char b, char c)
{
	if(1 == n)
		printf("Move disk %d from %c to %c\n", n, a, c);
	else{
		hannoi(n-1, a, c, b);
		printf("Move disk %d from %c to %c\n", n, a, c);
		hannoi(n-1, b, a, c);
	}
		
}
int main()
{
	int n;
	scanf("%d", &n);
	hannoi(n, 'A', 'B', 'C');
	return 0;
}
