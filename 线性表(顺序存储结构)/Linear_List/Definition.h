#pragma once
#ifndef __DEFINITION_H
#define __DEFINITION_H

#define LIST_INIT_SIZE 100 // ���Ա�洢�ռ�ĳ�ʼ������
#define TRUE 1  // ����������ȷ����TRUE
#define ERROR 0 // ����ʱ��������ERROR
#define OVERFLOW -2

typedef int Status; // ��ʾ״̬�ķ���ֵ

typedef struct {
	unsigned short int serial_number; //ѧ�����
	char name; // ѧ������ ����Ϊ���㸳ֵ����������Ϊ�ַ���
	unsigned short int age; // ѧ������
}Student;

typedef struct
{
	Student student[LIST_INIT_SIZE]; // ��������洢����
	int length; //���Ա�ĳ��ȣ������ݸ������������ʾһ����ѧ���ĸ�����С�ڵ���List_Init_Size
}SqList;

#endif 