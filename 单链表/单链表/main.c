// ��Ҫ�洢���������ش���
// �������ÿ�����ֻ��һ��ָ���򣬹���Ϊ������
#include<stdio.h>
#include<stdlib.h>

#include "Definition.h"
#include "LinkList_Operation.h"

#define _CRT_SECURE_NO_WARNINGS

int main()
{
	LinkList* L = LinkList_Init(); // ��ʼ������
	LinkList_Is_Empty(L); // �ж������Ƿ�Ϊ��
	LinkList* t = L; 
	for (int i = 0; i < 3; i++) // ������ֵ
	{
		LinkList* p = (LinkList*)malloc(sizeof(LinkList));
		p->student.serial_number = i + 1;
		p->student.age = i + 14;
		p->student.name = (char)(i + 65);
		t->next = p;
		t = p;
	}
	t->next = NULL;
	LinkList_Display(L); // ��ӡ����Ԫ��
	Student elem;
	LinkList_GetElem_1(L, 2, &elem);
	printf("������ĵ�2��Ԫ�ص�����Ϊ:%c\n", elem.name);
	printf("��ǰ����ĳ���Ϊ%d\n", LinkList_GetLength(L));
	LinkList_Is_Empty(L); // �ж������Ƿ�Ϊ��
	//LinkList_Clear(L);
	//LinkList_Destroy(L); 
	//���ô˺����󣬵��ú���LinkList_Is_Empty()
	//���г������ִ���˵���������ѱ��ݻ٣��޷�����
	LinkList_Is_Empty(L);
	Student elem1;
	LinkList_GetElem_2(L, 'A', &elem1);
	printf("����ΪA��ѧ���������ϢΪ: ��ţ�%d, ����:%d", elem1.serial_number, elem1.age);
	return 0;
}