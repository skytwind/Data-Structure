#pragma once
#include "Definition.h"
#ifndef __LIST_OPERATION_H
#define __LIST_OPERATION_H

SqList List_Init();
void List_Display(SqList List);
Status List_Insert(SqList* List, int i, Student elem);
Status List_Delete(SqList* List, int i);
int Locate_Elem(SqList* List, Student elem);
Status Replace_Elem(SqList* List, Student elem, Student NewElem);

#endif
