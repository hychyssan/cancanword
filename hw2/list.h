#define _CRT_SECURE_NO_WARNINGS
#ifndef LIST_H_		//what meaning?
#define LIST_H_
#include<stdbool.h>


/*  */
#define TSIZE 50

typedef struct film {
	char title[TSIZE];
	int rating;
}Item;

typedef struct node {
	Item item;
	struct node* next;
}Node;
typedef Node* List;


void Initializelist(List* plist);

bool ListIsEmpty(const List* plist);

bool ListIsFull(const List* plist);

unsigned int ListItemCount(const List* plist);

bool AddItem(Item item, List* plist);

void Traverse(const List* plist, void(*pfun)(Item item));

void EmptyTheList(List* plist);


#endif			//what mean?