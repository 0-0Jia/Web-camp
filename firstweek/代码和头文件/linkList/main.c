#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<stddef.h>
#include "linkedList.c"

void main() {
    LinkedList L;
    ElemType e;
    LNode *p,*q;
    scanf("%d,%d",p,q);
    printf("\n------��ʼ������----------\n");
    InitList(&L);
    printf("���������ִ�������\n");
    create(L);
    printf("�ڵ�P�����ڵ�Q: \n");
    InsertList(p,q);
    printf("�����������ú������ʣ�\n");
    TraverseList(L,e);
    printf("����e�ҵ������еĵ�һ���ڵ㣺\n");
    SearchList(L,e);
    printf("ɾ���ڵ�P֮��ĵ�һ���ڵ㲢����ֵ�����E\n");
    DeleteList(p,e);
    printf("��������\n");
    ReverseList(&L);
    printf("�ж������Ƿ�Ϊ����\n");
    IsLoopList(L);
    printf("\n��������:\n");
    DestroyList
    printf("***********************\n");

}
