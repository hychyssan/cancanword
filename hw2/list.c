#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include"list.h"

static void CopyToNode(Item item, Node* pnode);

void InitializeList(List* plist) {
	plist = NULL;
}

bool ListIsEmpty(const List* plist) {
	if (*plist == NULL) {
		return true;
	}
	else {
		return false;
	}
}

bool ListIsFull(const List* plist) {		//what mean of it?
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

unsigned int ListItemCount(const List* plist) {
	unsigned int count = 0;
	Node* pnode = *plist;

	while (pnode != NULL)
	{
		++count;
		pnode = pnode->next;
	}
	return count;
}

bool AddItem(Item item, List* plist) {
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

void Traverse(const List* plist, void(*pfun)(Item item))
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

void EmptyTheList(List* plist)
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