#include <stddef.h>
#include "../head/duLinkedList.h"
//˫��ѭ���б�


/**
 *  @name        : Status InitList_DuL(DuLinkedList *L)
 *	@description : initialize an empty linked list with only the head node ����ͷ�ڵ��ʼ���������б�
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList_DuL(DuLinkedList *L) {
    DuLNode *p, *s;
    (*L) = (DuLinkedList *)malloc(sizeof(DuLinkedList));
    if ((*L) == NULL)
        exit(0);
    (*L)->next = NULL;        //head��prev��next��ָ��NULL
    (*L)->prior = NULL;
    p = (*L);                 //pָ��head
//����Ϊ��ͷ�ڵ��ʼ��������������β�巨����
    int i;
       for (i = 0; s!=NULL; ++i)
    {
        s = (DuLNode *)malloc(sizeof(DuLNode));
        if (s == NULL)
            exit(0);
        printf("Input the value of the %dth node:", i + 1);
        scanf("%d", &s->data);
        s->next = NULL;
        p->next = s;
        s->prior = p;
        p = s;//pָ��β�ڵ�
    }
    return p;
}

/**
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : destroy a linked list  ���������б�
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
void DestroyList_DuL(DuLinkedList *L) {
       DuLNode *p;
       while((*L)->next != NULL)
{
        p = *L;
	p->next->prior = NULL;
        *L= p->next;
        free(p);
}
        if((*L)->next = NULL)
        return SUCCESS;
        else
	return ERROR;
}

/**
 *  @name        : Status InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : insert node q before node p  �ڽڵ�p֮ǰ����ڵ�q
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q) {
q->prior = p->prior;
q->next = p;
p->prior->next = q;
p->prior = q;
return SUCCESS;
}

/**
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p  �ڽڵ�p�����ڵ�q
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q) {
q->next = p->next;
q->prior = p;
p->next->prior = q;
p->next = q;
return SUCCESS;
}

/**
 *  @name        : Status DeleteList_DuL(DuLNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e  ɾ���ڵ�p֮��ĵ�һ���ڵ㣬������ֵ����e
 *	@param		 : p, e
 *	@return		 : status
 *  @notice      : None
 */
Status DeleteList_DuL(DuLNode *p, ElemType *e) {
    int i;
    DuLNode *p1;
    p1 = p->next;
    //��Ϊβ�ڵ�
    if(p1->next == NULL)
    {
        p1->prior->next = NULL;
        e=NULL;
        free(p1);
    }

    else
    {
        p1->next->prior = p1->prior;
        p1->prior->next = p1->next;
        *e=p1->data;
        free(p1);
    }
    return SUCCESS;

}

/**
 *  @name        : void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit   ���������б����ú�������
 *	@param		 : L(the head node), visit
 *	@return		 : Status
 *  @notice      : None
 */
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e)) {
       DuLNode *p;
       p = L->next;
       if (L->next == NULL)
       return ERROR;
       while(p != NULL)
{
       printf("%d ", p->data);
       p = p->next;
       (*visit)(p);
}
       printf("\n");
       return SUCCESS;
}
