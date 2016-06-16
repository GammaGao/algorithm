/* bst_search.c
 * purpose:	   suit for search a data.
 * efficiency: In the worse conditon, is O(n).
 * better: create an average tree(AVL tree).
 */
#include <stdio.h>`

typedef enum{FALSE = -1, TRUE}Status;

/*�������Ķ���������*/
typedef struct BiTNode
{
	int data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BitTree;

/* Search Binary Sort Tree to find 'key'
 * f points to T's parents, inlilated NULL
 * if succeeded, p points to data structure, and return FALSE
 * or, p points to last data structure of the path
 */
Status SearchBST(BitTree T, int key, BitTree f, BitTree *p)
{
	if(!T)		    //terminal leaf
	{
		*p = f;		    //���ΪҶ���ʱ��*pָ��˫�׽��
		return FALSE;
	}
	else if(key == T->data) //successfully searched
	{
		*p = T;
		//	printf("T->data:%d\n", T->data);
		return TRUE;
	}
	else if(key < T->data)
	{
		return SearchBST(T->lchild, key, T, p);
	}
	else
		return SearchBST(T->rchild, key, T, p);
}

/*
 * �����������������
 * �������������д��ڹؼ���key������Ԫ��ʱ
 * ����key������TRUE, ���򷵻�FALSE
 */
Status InsertBST(BitTree *T, int key)
{
	BitTree p, s;
	if(SearchBST(*T, key, NULL, &p)) //���Ҳ��ɹ�
	{
		s = (BitTree)malloc(sizeof(BiTNode));
		s->data = key;
		printf("%d\n", key);
		s->lchild = s->rchild = NULL;
		if(!p)
			*T = s; //����sΪ�µĸ����
		else if(key < p->data)
			p->lchild = s;
		else
			p->rchild = s;
		return TRUE;
	}
	else
		return FALSE;
}


int main()
{
	int a[] = {16, 53, 54, 75, 80, 99, 100, 110, 160, 161, 162};
	int i, res, need = 17;
	BitTree T = NULL, p;

	for(i = 0; i < sizeof(a)/sizeof(a[0]); i++)
	{
		InsertBST(&T, a[i]);
	}

	res = SearchBST(T, need, NULL, &p);

	if(FALSE == res)
		fprintf(stderr, "Not found %d\n", need);
	else
		fprintf(stdout, "Has found %d\n", need);
}