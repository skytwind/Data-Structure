#pragma once
#ifndef __LINKLISTOPERATION_H
#define __LINKLISTOPERATION_H

LinkList* LinkList_Init();
Status LinkList_Is_Empty(LinkList* L);
Status LinkList_Destroy(LinkList* L);
Status LinkList_Clear(LinkList* L);
int LinkList_GetLength(LinkList* L);
Status LinkList_Display(LinkList* L);
Status LinkList_GetElem_1(LinkList* L, int i, Student* Elem);
Status LinkList_GetElem_2(LinkList* L, char name, Student* elem);

#endif
