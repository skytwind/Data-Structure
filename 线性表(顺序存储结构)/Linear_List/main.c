// 主要存储 线性表(顺序存储结构) 相关代码
// 以一个班学生的线性表为例
// 注释中用 ElemType 代指线性表元素数据类型
#define CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "List_Operation.h"


int main()
{
	printf("序号		年龄		姓名\n");
	SqList List = List_Init();
	for (int i = 0; i < 5; i++) //给线性表赋值
	{
		List.student[i].age = i + 14;
		List.student[i].name = (char)(i + 65);
		List.student[i].serial_number = i + 1;
		List.length++;

	}
	//List_Display(List); // 打印线性表元素

	Student Elem;             //定义一个待插入元素
	Elem.serial_number = 6;
	Elem.name = 'W';
	Elem.age = 18;

	List_Insert(&List, 3, Elem);
	//List_Display(List);
	List_Delete(&List, 2);
	List_Display(List);
	printf("数据元素Elem在线性表的第%d个位置\n", Locate_Elem(&List, Elem));
	Student NewElem;         // 定义一个新元素
	NewElem.serial_number = 10;
	NewElem.name = 'Z';
	NewElem.age = 19;
	Replace_Elem(&List, Elem, NewElem); // 替换Elem元素
	List_Display(List);
	return 0;
}

