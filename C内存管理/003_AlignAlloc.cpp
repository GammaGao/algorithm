/* 题目：编写支持对齐分配的malloc和free函数，分配内存时，malloc函数返回的地址必须是能被2的n次方整除
 * TIME：2015-5-7
 */
#include <stdio.h>
#include <malloc.h>
#define DEBUG 1
/* 思路1：假设需要100字节的内存块，我们希望起始地址是16的整数倍，那么需要额外分配15字节
 *		有了这15字节，加上100字节，便可以在随后的115字节找一个地址为可以被16整除的地址。
 * 缺陷：无法释放内存
 */
void* AlignMalloc_1(size_t required_size, size_t alignment)
{
	size_t offsize = alignment - 1;
	void *p = (void *)malloc(required_size + alignment);
	/* 假设alignment=16, ~(alignment-1)=11..110000
	 * 它再与地址相与，得出来的地址肯定就可以被2^4整除，这儿没有用到模运算，而是用的&运算进行整除
	 * 当然q所指向的地址空间会比require_size大0~alignmnet-1字节的空间
	 */
	void *q = (void *)(((size_t)p + offsize) & ~(alignment - 1));
#ifdef DEBUG
	printf("p:0x%x, end:0x%x, q:0x%x\n", p, size_t(p) + required_size + offsize, q);
#endif
	return q;
}

/* 思路2:
 */
void *AlignMalloc_2(size_t required_size, size_t alignment)
{
	void *p; //原先的内存块
	void **q;//对齐后的内存块
	int offsize = alignment - 1 + sizeof(void *);
	p = (void *)malloc(required_size + offsize);
	if (!p)
		return NULL;
	q = (void **)(((size_t)p + offsize) & ~(alignment - 1));
	q[-1] = p; //把起始地址信息存放于此
#ifdef DEBUG
	printf("p:0x%x, end:0x%x, q:0x%x\n", p, size_t(p) + required_size + offsize, q);
#endif
	return q;
}


void AlignFree(void *q)
{
	void *p = ((void **)q)[-1];
	free(p);
}

int main()
{
	//int *p = (int *)AlignMalloc_1(11, 32);
	int *p = (int *)AlignMalloc_2(11, 32);
	AlignFree(p);
	getchar();
}