// ��Ҫ�洢 ���Ա�(˳��洢�ṹ) ��ش���
// ��һ����ѧ�������Ա�Ϊ��
// ע������ ElemType ��ָ���Ա�Ԫ����������
#define CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "List_Operation.h"


int main()
{
	printf("���		����		����\n");
	SqList List = List_Init();
	for (int i = 0; i < 5; i++) //�����Ա�ֵ
	{
		List.student[i].age = i + 14;
		List.student[i].name = (char)(i + 65);
		List.student[i].serial_number = i + 1;
		List.length++;

	}
	//List_Display(List); // ��ӡ���Ա�Ԫ��

	Student Elem;             //����һ��������Ԫ��
	Elem.serial_number = 6;
	Elem.name = 'W';
	Elem.age = 18;

	List_Insert(&List, 3, Elem);
	//List_Display(List);
	List_Delete(&List, 2);
	List_Display(List);
	printf("����Ԫ��Elem�����Ա�ĵ�%d��λ��\n", Locate_Elem(&List, Elem));
	Student NewElem;         // ����һ����Ԫ��
	NewElem.serial_number = 10;
	NewElem.name = 'Z';
	NewElem.age = 19;
	Replace_Elem(&List, Elem, NewElem); // �滻ElemԪ��
	List_Display(List);
	return 0;
}

