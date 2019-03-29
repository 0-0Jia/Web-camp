#include "duLinkedList.c"

int main()
{
    int num;
    ElemType e;
    DuLNode *head,*p,*q;
    scanf("%d,%d",p,q);
    InitList_DuL(&head);//初始化链表并赋值,返回尾节点last
    TraverseList_DuL(head,e);
    /***************************************************************/
    printf("在节点p之前插入节点q，请输入节点p,q：");
    InsertBeforeList_DuL(p,q);
    TraverseList_DuL(head,e);
    printf("insert node q after node p，请输入节点p,q：");
    InsertAfterList_DuL(p,q);
    TraverseList_DuL(head,e);
    printf("要删除节点p之后的第一个节点，并将其值赋给e，请输入节点p：");
    DeleteList_DuL(p,e);
    TraverseList_DuL(head,e);
    /***************************************************************/
    DestroyList_DuL(&head);
    TraverseList_DuL(head,e);
    return 0;
}
