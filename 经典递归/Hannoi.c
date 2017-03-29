#include <stdio.h>

/**
 * Hanoi Tower
 * @date 2017.03.29
 */
void hannoi(int n, char a, char b, char c)
{
	if(1 == n)
		printf("Move disk-%d from %c to %c\n", n, a, c);
	else{
		//move the n-1 disks above from A to B. So the max disk-n is on the A.
		hannoi(n-1, a, c, b);
		
		//move the current max disk from A to C.
		printf("Move disk-%d from %c to %c\n", n, a, c);
		
		//move the rest n-1 disks from B to A.
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
