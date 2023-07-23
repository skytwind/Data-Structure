#pragma once
#ifndef __DEFINITION_H
#define __DEFINITION_H

#define LIST_INIT_SIZE 100 // 线性表存储空间的初始分配量
#define TRUE 1  // 函数运行正确返回TRUE
#define ERROR 0 // 出错时函数返回ERROR
#define OVERFLOW -2

typedef int Status; // 表示状态的返回值

typedef struct {
	unsigned short int serial_number; //学生序号
	char name; // 学生姓名 这里为方便赋值将姓名定义为字符型
	unsigned short int age; // 学生年龄
}Student;

typedef struct
{
	Student student[LIST_INIT_SIZE]; // 定义数组存储数据
	int length; //线性表的长度，即数据个数，在这里表示一个班学生的个数，小于等于List_Init_Size
}SqList;

#endif 