/* ��Ŀ����д֧�ֶ�������malloc��free�����������ڴ�ʱ��malloc�������صĵ�ַ�������ܱ�2��n�η�����
 * TIME��2015-5-7
 */
#include <stdio.h>
#include <malloc.h>
#define DEBUG 1
/* ˼·1��������Ҫ100�ֽڵ��ڴ�飬����ϣ����ʼ��ַ��16������������ô��Ҫ�������15�ֽ�
 *		������15�ֽڣ�����100�ֽڣ������������115�ֽ���һ����ַΪ���Ա�16�����ĵ�ַ��
 * ȱ�ݣ��޷��ͷ��ڴ�
 */
void* AlignMalloc_1(size_t required_size, size_t alignment)
{
	size_t offsize = alignment - 1;
	void *p = (void *)malloc(required_size + alignment);
	/* ����alignment=16, ~(alignment-1)=11..110000
	 * �������ַ���룬�ó����ĵ�ַ�϶��Ϳ��Ա�2^4���������û���õ�ģ���㣬�����õ�&�����������
	 * ��Ȼq��ָ��ĵ�ַ�ռ���require_size��0~alignmnet-1�ֽڵĿռ�
	 */
	void *q = (void *)(((size_t)p + offsize) & ~(alignment - 1));
#ifdef DEBUG
	printf("p:0x%x, end:0x%x, q:0x%x\n", p, size_t(p) + required_size + offsize, q);
#endif
	return q;
}

/* ˼·2:
 */
void *AlignMalloc_2(size_t required_size, size_t alignment)
{
	void *p; //ԭ�ȵ��ڴ��
	void **q;//�������ڴ��
	int offsize = alignment - 1 + sizeof(void *);
	p = (void *)malloc(required_size + offsize);
	if (!p)
		return NULL;
	q = (void **)(((size_t)p + offsize) & ~(alignment - 1));
	q[-1] = p; //����ʼ��ַ��Ϣ����ڴ�
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