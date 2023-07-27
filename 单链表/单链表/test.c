#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void test()
{
	int a = 5;
	int* p = &a;
	int* q;
	q = p;
	free(q);
	printf("%d", *p);

}