// 主要存储单链表的相关代码
// 单链表的每个结点只有一个指针域，故名为单链表
#include<stdio.h>
#include<stdlib.h>

#include "Definition.h"
#include "LinkList_Operation.h"

#define _CRT_SECURE_NO_WARNINGS

int main()
{
	LinkList* L = LinkList_Init(); // 初始化链表
	LinkList_Is_Empty(L); // 判断链表是否为空
	LinkList* t = L; 
	for (int i = 0; i < 3; i++) // 给链表赋值
	{
		LinkList* p = (LinkList*)malloc(sizeof(LinkList));
		p->student.serial_number = i + 1;
		p->student.age = i + 14;
		p->student.name = (char)(i + 65);
		t->next = p;
		t = p;
	}
	t->next = NULL;
	LinkList_Display(L); // 打印链表元素
	Student elem;
	LinkList_GetElem_1(L, 2, &elem);
	printf("该链表的第2个元素的姓名为:%c\n", elem.name);
	printf("当前链表的长度为%d\n", LinkList_GetLength(L));
	LinkList_Is_Empty(L); // 判断链表是否为空
	//LinkList_Clear(L);
	//LinkList_Destroy(L); 
	//调用此函数后，调用函数LinkList_Is_Empty()
	//运行程序会出现错误，说明该链表已被摧毁，无法调用
	LinkList_Is_Empty(L);
	Student elem1;
	LinkList_GetElem_2(L, 'A', &elem1);
	printf("姓名为A的学生的相关信息为: 序号：%d, 年龄:%d", elem1.serial_number, elem1.age);
	return 0;
}