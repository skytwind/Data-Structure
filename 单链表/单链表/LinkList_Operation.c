#define _CRT_SECURE_NO_WARNINGS
#include "Definition.h"
#include<stdlib.h>
/*
����L������˵������ʾͷ���
*/
// ��ʼ��һ����ͷ���Ŀ�����
// ͷ������Ϊ����Ĳ��������ܶ����
LinkList* LinkList_Init()
{
	LinkList* L = (LinkList*)malloc(sizeof(LinkList)); // Ϊͷ������ռ�
	L->next = NULL; // ������ͷ����ָ����Ϊ��
	return L;  // ����ͷ��㣬ͨ��ͷ�������ҵ���������
}


// �ж������Ƿ�Ϊ�գ����򷵻�TRUE�����򷵻�FALSE
// L���������ͷ���ĵ�ַ
Status LinkList_Is_Empty(LinkList* L)
{
	if (L->next == NULL) // ���Լ�дΪ!L->next
	{
		printf("��ǰ����Ϊ��!\n");
		return FALSE;
	}
	else
	{
		printf("��ǰ����Ϊ��!\n");
		return TRUE;
	}
}

// ���������
// ����������ζ��������ȫ��ʧ��ͷ����ͷָ�벻������
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

// ��������
// �������� ��ͬ�� ��������� ��ͷ����ͷָ�����ɴ���
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

// ������ı�
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

// ��ӡ����Ԫ��
Status LinkList_Display(LinkList* L)
{
	printf("ѧ��  ����  ����\n");
	while (L = L->next)
	{
		printf("%-5d %-5d %-5c\n", L->student.serial_number, L->student.age, L->student.name);
	}
	return TRUE;
}


// Ѱ�������еĵ�i��Ԫ�� ������elem�������Ԫ�� ��λ����
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

// ��Ԫ��ֵѰ������Ԫ�� ������ʾ��ѧ����������ѧ���й���Ϣ
// ����elem�������Ԫ��
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

// �ڵ�i��Ԫ��ǰ����һ����Ԫ�أ��½�㣩
Status LinkList_Insert(LinkList* L, int i, Student* elem)
{
	LinkList* p = L, *s = NULL;
	int j = 1;
	while (p && j < i)  //��������i-1���ڵ�
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

// ɾ����i��Ԫ��(��i�����)������elem����������
Status LinkList_Delete(LinkList* L, int i, Student* elem)
{
	LinkList* p = L;
	int j = 1;
	while (p && j < i)
	{
		p = p->next;
		++j; //++j��ִ��Ч��Ҫ��j++����
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