#include "duLinkedList.c"

int main()
{
    int num;
    ElemType e;
    DuLNode *head,*p,*q;
    scanf("%d,%d",p,q);
    InitList_DuL(&head);//��ʼ��������ֵ,����β�ڵ�last
    TraverseList_DuL(head,e);
    /***************************************************************/
    printf("�ڽڵ�p֮ǰ����ڵ�q��������ڵ�p,q��");
    InsertBeforeList_DuL(p,q);
    TraverseList_DuL(head,e);
    printf("insert node q after node p��������ڵ�p,q��");
    InsertAfterList_DuL(p,q);
    TraverseList_DuL(head,e);
    printf("Ҫɾ���ڵ�p֮��ĵ�һ���ڵ㣬������ֵ����e��������ڵ�p��");
    DeleteList_DuL(p,e);
    TraverseList_DuL(head,e);
    /***************************************************************/
    DestroyList_DuL(&head);
    TraverseList_DuL(head,e);
    return 0;
}
