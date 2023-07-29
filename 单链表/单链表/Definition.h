#pragma once

#define TRUE 1  // 函数运行正确返回TRUE
#define ERROR 0 // 出错时函数返回ERROR
#define FALSE 0 //  
#define OVERFLOW -2

typedef int Status; // 表示状态的返回值

typedef struct {
	unsigned short int serial_number; //学生序号
	char name; // 学生姓名 这里为方便赋值将姓名定义为字符型
	unsigned short int age; // 学生年龄
}Student;

typedef struct LNode
{
	Student student; 
	struct LNode *next; 
}LinkList;

