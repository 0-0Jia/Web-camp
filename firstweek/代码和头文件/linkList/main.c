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
    printf("\n------初始化链表----------\n");
    InitList(&L);
    printf("请输入数字创建链表：\n");
    create(L);
    printf("节点P后插入节点Q: \n");
    InsertList(p,q);
    printf("遍历链表并调用函数访问：\n");
    TraverseList(L,e);
    printf("根据e找到链表中的第一个节点：\n");
    SearchList(L,e);
    printf("删除节点P之后的第一个节点并将其值分配给E\n");
    DeleteList(p,e);
    printf("反向链表：\n");
    ReverseList(&L);
    printf("判断链表是否为环：\n");
    IsLoopList(L);
    printf("\n销毁链表:\n");
    DestroyList
    printf("***********************\n");

}
