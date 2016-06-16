/* hash_search.c
 * purpose: finding-algorithm realized by hash.
 * method: hash table.
 * efficiency:search,insert,delete ==> O(1).
 */
#include <stdio.h>
#include <malloc.h>

#define SUCCESS   1
#define UNSUCCESS 0
#define HASHSIZE  12
#define NULLKEY   -32768

typedef enum{FALSE = 0, TRUE}Status;

typedef struct
{
	int *elem;
	int count;
}HashTable;

int m = 0; //length of hash table

Status InitHashTable(HashTable *H)
{
	int i;
	m = HASHSIZE;
	H->count = m;
	H->elem = (int *)malloc(m*sizeof(HashTable));
	for(i = 0; i < m; i++)
	{
		H->elem[i] = NULLKEY;
	}
	return TRUE;
}

/* hash function for generate hash address
 */
int Hash(int key)
{
	return key % m;
}

void InsertHash(HashTable *H, int key)
{
	int addr = Hash(key);
	while(H->elem[addr] != NULLKEY) //if not NULLKEY, conflict with other key.
		addr = (addr+1)%m; //linear probe to cancel confliction.
	H->elem[addr] = key;
}

Status SearchHash(HashTable H, int key, int *addr)
{
	*addr = Hash(key);
	while(H.elem[*addr] != key)
	{
		*addr =  (*addr + 1) % m;
		if(H.elem[*addr] == NULLKEY || *addr == Hash(key))
		{
			return UNSUCCESS;
		}
	}
	return SUCCESS;
}

main()
{
	HashTable H;
	int key[] = {12,67,56,16,25,37,22,29,15,47,48,34}; //HASHSIZE=12
	int i, addr;

	InitHashTable(&H);
	for(i = 0; i < sizeof(key)/sizeof(key[0]); i++)
	{
		InsertHash(&H, key[i]);
	}
	SearchHash(H, 34, &addr);
	printf("%d\n", addr);
}