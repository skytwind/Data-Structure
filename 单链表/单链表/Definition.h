#pragma once

#define TRUE 1  // ����������ȷ����TRUE
#define ERROR 0 // ����ʱ��������ERROR
#define FALSE 0 //  
#define OVERFLOW -2

typedef int Status; // ��ʾ״̬�ķ���ֵ

typedef struct {
	unsigned short int serial_number; //ѧ�����
	char name; // ѧ������ ����Ϊ���㸳ֵ����������Ϊ�ַ���
	unsigned short int age; // ѧ������
}Student;

typedef struct LNode
{
	Student student; 
	struct LNode *next; 
}LinkList;

