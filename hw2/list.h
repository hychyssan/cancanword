#define _CRT_SECURE_NO_WARNINGS
#ifndef LIST_H_		//what meaning?
#define LIST_H_
#include<stdbool.h>


/*  */
#define TSIZE 50

typedef struct film {		//这是一个电影评分链表，由两个元素组成：电影名字和评分
	char title[TSIZE];		//电影名字
	int rating;			//电影评分
}Item;

typedef struct node {
	Item item;
	struct node* next;
}Node;
typedef Node* List;


void Initializelist(List* plist);			//初始化链表

bool ListIsEmpty(const List* plist);		//判断链表是否为空

bool ListIsFull(const List* plist);			//判断链表是否为满

unsigned int ListItemCount(const List* plist);		//统计链表元素个数

bool AddItem(Item item, List* plist);		//给链表添加一个元素

void Traverse(const List* plist, void(*pfun)(Item item));		//给链表每个元素执行一个函数

void EmptyTheList(List* plist);		//清空链表


#endif			