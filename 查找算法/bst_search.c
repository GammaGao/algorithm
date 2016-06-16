/* bst_search.c
 * purpose:	   suit for search a data.
 * efficiency: In the worse conditon, is O(n).
 * better: create an average tree(AVL tree).
 */
#include <stdio.h>`

typedef enum{FALSE = -1, TRUE}Status;

/*二叉树的二叉链表结点*/
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
		*p = f;		    //结点为叶结点时，*p指向双亲结点
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
 * 二叉排序树插入操作
 * 当二叉排序树中存在关键字key的数据元素时
 * 插入key并返回TRUE, 否则返回FALSE
 */
Status InsertBST(BitTree *T, int key)
{
	BitTree p, s;
	if(SearchBST(*T, key, NULL, &p)) //查找不成功
	{
		s = (BitTree)malloc(sizeof(BiTNode));
		s->data = key;
		printf("%d\n", key);
		s->lchild = s->rchild = NULL;
		if(!p)
			*T = s; //插入s为新的根结点
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