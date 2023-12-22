#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include"list.h"

static void CopyToNode(Item item, Node* pnode);			//将一个item类型元素拷贝到一个链表节点里

void InitializeList(List* plist) {			//初始化链表
	plist = NULL;
}

bool ListIsEmpty(const List* plist) {		//判断链表是否为空
	if (*plist == NULL) {
		return true;
	}
	else {
		return false;
	}
}

bool ListIsFull(const List* plist) {		//判断链表是否为满
	Node* pt;
	bool full;

	pt = (Node*)malloc(sizeof(Node));
	if (pt == NULL) {
		full = true;
	}
	else {
		full = false;
	}
	free(pt);

	return full;
}

unsigned int ListItemCount(const List* plist) {			////统计链表元素个数
	unsigned int count = 0;
	Node* pnode = *plist;

	while (pnode != NULL)
	{
		++count;
		pnode = pnode->next;
	}
	return count;
}

bool AddItem(Item item, List* plist) {			//给链表添加一个元素
	Node* pnew;
	Node* scan = *plist;
	pnew = (Node*)malloc(sizeof(Node));
	if (pnew == NULL) {
		return false;
	}
	CopyToNode(item, pnew);
	pnew->next = NULL;
	if (scan == NULL) {
		*plist = pnew;
	}
	else {
		while (scan->next != NULL) {
			scan = scan->next;
		}
		scan->next = pnew;
	}
	return true;
}

void Traverse(const List* plist, void(*pfun)(Item item))		//给链表每个元素执行一个函数
{
	if (*plist == NULL)		//+*
		return;
	Node* pnode = *plist;
	Node* prev=*plist;
	
	while ((pnode ->next)!= NULL)
	{
		prev = pnode;
		pnode = pnode->next;
		
	}
	if (pnode->next == NULL||pnode!=NULL)
	{
		(*pfun)(pnode->item);
		if (prev->next == pnode)
		{
			free(pnode);
			pnode = NULL;
			prev->next = NULL;
		}
		else
		{
			free(pnode);
			pnode = NULL;
			return;
		}

		Traverse(plist, pfun);
	}
	return;
}

void EmptyTheList(List* plist)		//清空链表
{
	Node* psave;

	while (*plist != NULL)
	{
		psave = (*plist)->next;
		free(*plist);
		*plist = psave;
	}
}

void CopyToNode(Item item, Node* pnode) {
	pnode->item = item;
}