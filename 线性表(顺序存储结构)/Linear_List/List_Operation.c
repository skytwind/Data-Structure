#define CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include "Definition.h"

// ��ʼ�����Ա�����һ������Ϊ0�����Ա�List
SqList List_Init() 
{
	SqList List;
	if (!List.student)
	{
		printf("���ִ���");
		exit(OVERFLOW);
	}
	List.length = 0;
	return List;
}

// ��ӡ���Ա�Ԫ��
// �����Ա�����������ERROR
Status List_Display(SqList List) 
{
	int i = 0;
	for (i = 0; i < List.length; i++)
	{
		printf("%d\t\t%d\t\t%c\n", List.student[i].serial_number, List.student[i].age, List.student[i].name);
	}

	return TRUE;
}

// �ú������������Ա��i��Ԫ�ز���һ����Ԫ�� elem
Status List_Insert(SqList* List, int i, Student elem) 
{
	int k;
	if (i<1 || i > List->length + 1)
	{
		return ERROR;       // ������λ�� i ������,����ERROR
	}

	else if (List->length == LIST_INIT_SIZE)
	{
		return ERROR;     //����ǰ���Ա�����������ERROR
	}
	//������ڵ�i��λ�ò���һ����Ԫ�أ�����Ҫ�����Ա�ӵ�i��Ԫ�ؿ�ʼ��������Ԫ�غ���һλ
	//�ٽ�Ԫ��elem��ֵ����i��Ԫ������λ��
	else
	{
		for (k = List->length - 1; k > i - 2; k--)
		{
			List->student[k + 1] = List->student[k]; 
			// ��i��Ԫ�ض�Ӧ���±�Ϊ i-1 ���������һ��ѭ������ ElemType[i - 1] ��ֵ�� ElemType[i] ����
		}
	}
	List->student[i - 1] = elem;
	List->length++; // ���������Ա��ȼ�1
	return TRUE;

}

// ɾ�����Ա�ĵ�i��Ԫ��
Status List_Delete(SqList* List, int i) 
{
	int k;
	if (i < 1 || i > List->length)
	{
		return ERROR;  //iֵ������ʱ ����ERROR
	}
	else if (List->length == 0)
	{
		return ERROR;  //���Ա���Ϊ0(��û���κ�����ʱ),����ERROR
	}
	// ɾ����i��Ԫ�أ� ֻ��Ҫ�ѵ�i+1��Ԫ�ؿ�ʼ������Ԫ����ǰ�ƶ�һλ
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

//����Ԫ��elem�����Ա��е�λ�ã�����������λ��
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
	return ERROR; // ���Ա���û����Ҫ����Ԫ��ʱ����ERROR
}

// ��NewElem�滻���Ա��е�ElemԪ��
Status Replace_Elem(SqList* List, Student elem, Student NewElem)
{
	int i = Locate_Elem(List, elem);
	if (!i)
	{
		printf("���Ա��в����ڴ��滻���ݣ�");
		return ERROR;
	}
	else
	{
		List->student[i - 1] = NewElem;
	}
	return TRUE;
}