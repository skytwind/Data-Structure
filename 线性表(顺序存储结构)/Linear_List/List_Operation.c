#define CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include "Definition.h"

// 初始化线性表，返回一个长度为0的线性表List
SqList List_Init() 
{
	SqList List;
	if (!List.student)
	{
		printf("出现错误！");
		exit(OVERFLOW);
	}
	List.length = 0;
	return List;
}

// 打印线性表元素
// 若线性表已满，返回ERROR
Status List_Display(SqList List) 
{
	int i = 0;
	for (i = 0; i < List.length; i++)
	{
		printf("%d\t\t%d\t\t%c\n", List.student[i].serial_number, List.student[i].age, List.student[i].name);
	}

	return TRUE;
}

// 该函数用于在线性表第i个元素插入一个新元素 elem
Status List_Insert(SqList* List, int i, Student elem) 
{
	int k;
	if (i<1 || i > List->length + 1)
	{
		return ERROR;       // 若插入位置 i 不合理,返回ERROR
	}

	else if (List->length == LIST_INIT_SIZE)
	{
		return ERROR;     //若当前线性表已满，返回ERROR
	}
	//如果想在第i个位置插入一个新元素，首先要将线性表从第i个元素开始，将所有元素后移一位
	//再将元素elem赋值给第i个元素所在位置
	else
	{
		for (k = List->length - 1; k > i - 2; k--)
		{
			List->student[k + 1] = List->student[k]; 
			// 第i个元素对应的下标为 i-1 ，所以最后一次循环满足 ElemType[i - 1] 赋值给 ElemType[i] 即可
		}
	}
	List->student[i - 1] = elem;
	List->length++; // 别忘了线性表长度加1
	return TRUE;

}

// 删除线性表的第i个元素
Status List_Delete(SqList* List, int i) 
{
	int k;
	if (i < 1 || i > List->length)
	{
		return ERROR;  //i值不合理时 返回ERROR
	}
	else if (List->length == 0)
	{
		return ERROR;  //线性表长度为0(即没有任何数据时),返回ERROR
	}
	// 删除第i个元素， 只需要把第i+1个元素开始的所有元素向前移动一位
	else
	{
		for (k = i - 1; k < List->length; k++)
		{
			List->student[k] = List->student[k + 1];
		}
	}
	List->length--;
	return TRUE;
}

//查找元素elem在线性表中的位置，返回其所在位次
int Locate_Elem(SqList* List, Student elem) 
{
	int i = 0;
	for (i = 0; i < List->length; i++)
	{
		if (List->student[i].age == elem.age &&
			List->student[i].serial_number == elem.serial_number &&
			List->student[i].name == elem.name)
		{
			return i + 1;
		}
	}
	return ERROR; // 线性表中没有所要查找元素时返回ERROR
}

// 用NewElem替换线性表中的Elem元素
Status Replace_Elem(SqList* List, Student elem, Student NewElem)
{
	int i = Locate_Elem(List, elem);
	if (!i)
	{
		printf("线性表中不存在待替换数据！");
		return ERROR;
	}
	else
	{
		List->student[i - 1] = NewElem;
	}
	return TRUE;
}