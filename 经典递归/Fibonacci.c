#include <stdio.h>
#include <stdlib.h>

#define MALLOC(p, n) \
	if(!(p = malloc(n))){ \
		perror("Insufficient memorry");	\
	} 

/* recursively */
#if 0
unsigned int fibonacci(unsigned int n)
{	
	if(0 == n){
		return 0;	
	}
	else if(1 == n){
		return 1;
	}
	else
		return fibonacci(n-1) + fibonacci(n-2);
}
#endif

/* inrecrsively array */
#if 0
unsigned int fibonacci(unsigned int n)
{
	unsigned int i, *p = NULL;

	MALLOC(p, n*sizeof(unsigned int));
	
	if(0 == n){
		return 0;	
	}
	else if(1 == n){
		return 1;
	}
	else{
		i = 0;
		*p = 0;
		*(p+1) = 1;
		while(i < n-1){
			*(p+2+i) = *(p+1+i) + *(p+i);
			i++;
		}
	}
	return *(p+n);
}
#endif

unsigned int fibonacci(unsigned int n)
{
	int forward, backward, res;
	
	forward  = 0; 
	backward = 1;
	res 	 = 0;

	
	if(0 == n)
		return 0;
	else if(1 == n){
		return 1;
	}
	while(--n){
		res = forward + backward;
		forward = backward;
		backward = res;	
	}
	return res;
}
int main()
{
	int n;
	printf("Enter ther order of Fibonacci:");	
	scanf("%d", &n);
	printf("%lu\n", fibonacci(n));
	return 0;
}
