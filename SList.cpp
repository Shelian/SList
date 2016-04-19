#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
//��β��ͷ��ӡ������
//ɾ��һ����ͷ������ķ�β�ڵ�
//����ͷ�������һ����ͷ�ڵ�ǰ����һ���ڵ�
//����/��ת������
//���ҵ�������м�ڵ㣬Ҫ��ֻ�ܱ���һ��
//���ҵ�����ĵ�����k���ڵ㣬Ҫ��ֵ����һ��
typedef int DataType;

typedef struct SListNode
{
	DataType data;
	struct SListNode * next;
}SListNode;

SListNode* BuyNode(DataType x)
{
	SListNode *next = (SListNode*)malloc(sizeof(SListNode));
	next->data = x;
	next->next = NULL;
	return next;
}

void PushBack(SListNode*& pHead,DataType x)
{
	if (pHead == NULL)
	{
		pHead = BuyNode(x);
	}
	else
	{
		SListNode* tail = pHead;
		while (tail->next !=NULL)
		{
			tail = tail->next;
		}
		tail->next = BuyNode(x);
	}
	
}

void PushFront(SListNode*& pHead, DataType x)
{
		SListNode* front = BuyNode(x);
		front->next = pHead;
		pHead = front;
}

void PrintSListNode(SListNode* pHead)
{
	while (pHead)
	{
		printf("%d ", pHead->data);
		pHead = pHead->next;
	}
	printf("\n");
}
//��β��ͷ��ӡ������
void PrintTailToHead(SListNode* pHead)
{
	if (pHead)
	{
		PrintTailToHead(pHead->next);
		printf("%d ", pHead->data);
	}
}

//ɾ��һ����ͷ������ķ�β�ڵ�
void EraseNode(SListNode*& pHead,SListNode* pos)
{
	SListNode* cur = pHead;
	if (pHead == NULL)
	{
		return;
	}
	while (cur)
	{
		if (cur == pos)
		{
			pos->data = pos->next->data;
			pos->next = pos->next->next;
			free(pos->next);
			return;
		}
		cur = cur->next;
	}
}

//����ͷ�������һ����ͷ�ڵ�ǰ����һ���ڵ�
void InsertFront(SListNode*& pHead,SListNode* pos, DataType x)
{
	if (pHead==NULL)
	{
		return;
	}
	SListNode* cur = pHead;
	/*SListNode* newNode = BuyNode(x);*/
	/*while (cur !=NULL)
	{
		if (cur == pos)
		{
			newNode->next = pos->next;
			cur->next = newNode;
			DataType tmp = pos->data;
			pos->data = newNode->data;
			newNode->data = tmp;
		}
		cur = cur->next;
	}*/
	
	while (cur)
	{
		if (cur == pos)
		{
			SListNode* dpos = BuyNode(pos->data);
			dpos -> next = pos->next;
			pos ->next = dpos;
			pos->data = x;
			break;
		}
		cur = cur->next;
	}
}
//����/��ת������
void ReserveSList(SListNode* &pHead)
{
	SListNode* cur = pHead;
	SListNode* tail = NULL;
	while (cur)
	{
		//if (tail == NULL)
		//{
		//	tail = cur;
		//	cur = cur->next;
		//	tail->next = NULL;
		//	pHead = tail;
		//}
		
			SListNode* ptail = cur;
			cur = cur->next;
			ptail->next = tail;
			tail = ptail;
			pHead = ptail;
	}
}

//���ҵ�������м�ڵ㣬Ҫ��ֻ�ܱ���һ��
SListNode* FindMid(SListNode* pHead)
{
	SListNode* slow = pHead;
	SListNode* fast = pHead;
	while (fast)
	{
		if (fast->next != NULL)
		{
			slow = slow->next;
			fast = fast->next->next;
		}
		else
		return slow;
	}
	return slow;
}

//���ҵ�����ĵ�����k���ڵ㣬Ҫ��ֵ����һ��
SListNode* FindK(SListNode* pHead,int k)
{
	SListNode* slow = pHead;
	SListNode* fast = pHead;
	while (fast && k--)
	{
		fast = fast->next;
	}
	if (k > 0)
	{
		return NULL;
	}
	while (fast)
	{
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
}

void Test()
{
	SListNode* list = NULL;
	SListNode* List = NULL;
	PushBack(list, 1);
	PushBack(list, 2);
	PushBack(list, 3);
	PushBack(list, 4);
	PushBack(list, 5);
	PrintSListNode(list);
	/*PrintTailToHead(list);*/
	printf("\n");
	/*EraseNode(list, list->next->next);*/
	/*InsertFront(list, list->next, 20);*/
	ReserveSList(list);
	PrintSListNode(list);
	/*SListNode* ret=FindMid(list);*/
	//printf("%d ", ret->data);
	SListNode* ret = FindK(list, 3);
	if (ret == NULL)
	{
		printf("not exist!\n");
	}
	else
		printf("%d \n", ret->data);
	/*PrintSListNode(List);*/
}
//void Test()
//{
//	SListNode* list = NULL;
//	PushFront(list, 1);
//	PushFront(list, 2);
//	PushFront(list, 3);
//	PushFront(list, 4);
//	PrintSListNode(list);
//
//}

void main()
{
	Test();
	system("pause");
}