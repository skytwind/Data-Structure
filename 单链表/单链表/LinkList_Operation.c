#define _CRT_SECURE_NO_WARNINGS
#include "Definition.h"
#include<stdlib.h>
/*
以下L无特殊说明均表示头结点
*/
// 初始化一个带头结点的空链表
// 头结点可以为链表的操作带来很多便利
LinkList* LinkList_Init()
{
	LinkList* L = (LinkList*)malloc(sizeof(LinkList)); // 为头结点分配空间
	L->next = NULL; // 空链表头结点的指针域为空
	return L;  // 返回头结点，通过头结点可以找到整个链表
}


// 判断链表是否为空，是则返回TRUE，否则返回FALSE
// L接受链表的头结点的地址
Status LinkList_Is_Empty(LinkList* L)
{
	if (L->next == NULL) // 可以简写为!L->next
	{
		printf("当前链表为空!\n");
		return FALSE;
	}
	else
	{
		printf("当前链表不为空!\n");
		return TRUE;
	}
}

// 链表的销毁
// 销毁链表意味着链接完全消失，头结点和头指针不复存在
Status LinkList_Destroy(LinkList* L)
{
	LinkList* p;
	while(L)
	{
		p = L;
		L = L->next;
		free(p);
	}
	return TRUE;
	
}

// 链表的清空
// 链表的清空 不同于 链表的销毁 其头结点和头指针依旧存在
Status LinkList_Clear(LinkList* L)
{
	LinkList* p, * q;
	p = L->next;
	while (p)
	{
		q = p->next;
		free(p);
		p = q;
	}
	L->next = NULL;
	return TRUE;
}

// 求链表的表长
int LinkList_GetLength(LinkList* L)
{
	int length = 0;
	while (L->next)
	{
		length++;
		L = L->next;
	}
	return length;
}

// 打印链表元素
Status LinkList_Display(LinkList* L)
{
	printf("学号  年龄  姓名\n");
	while (L = L->next)
	{
		printf("%-5d %-5d %-5c\n", L->student.serial_number, L->student.age, L->student.name);
	}
	return TRUE;
}


// 寻找链表中的第i个元素 ，并用elem接收这个元素 按位查找
Status LinkList_GetElem_1(LinkList* L, int i, Student* Elem)
{
	LinkList* p = L->next;
	int j = 1;
	while (p && j < i)
	{
		p = p->next;
		++j;
	}
	if (!p || j > i)
	{
		return ERROR;
	}

	*Elem = p->student;
	return TRUE;

}

// 按元素值寻找链表元素 这里演示用学生姓名查找学生有关信息
// 并用elem接收这个元素
Status LinkList_GetElem_2(LinkList* L, char name, Student* elem)
{
	LinkList* p = L->next;
	while (p->student.name != name && p)
	{
		p = p->next;
	}
	if (!p)
	{
		return ERROR;
	}
	*elem = p->student;
	return TRUE;
}

// 在第i个元素前插入一个新元素（新结点）
Status LinkList_Insert(LinkList* L, int i, Student* elem)
{
	LinkList* p = L, *s = NULL;
	int j = 1;
	while (p && j < i)  //遍历到第i-1个节点
	{
		p = p->next;
		++j;
	}
	if (!p || j > i)
	{
		return ERROR;
	}
	s->student = *elem;
	s->next = p->next;
	p->next = s;
	return TRUE;
}

// 删除第i个元素(第i个结点)，并用elem接收这个结点
Status LinkList_Delete(LinkList* L, int i, Student* elem)
{
	LinkList* p = L;
	int j = 1;
	while (p && j < i)
	{
		p = p->next;
		++j; //++j的执行效率要比j++更高
	}
	if (!p || j > i)
	{
		return ERROR;
	}
	LinkList* q = p->next;
	p->next = q->next;
	*elem = q->student;
	free(q);
	return TRUE;

}