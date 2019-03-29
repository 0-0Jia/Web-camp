#include<stddef.h>
#include "../head/linkedList.h"
//单项循环列表

//创建链表
void create(struct LNode*head){
struct LNode *pend,*pnew;
int n=0;
pend=head;
scanf("%d",&n);
while(n!=-1)
{
    pnew=(struct LNode *)malloc(sizeof(struct LNode));    //为pnew开辟内存
    pnew->data=n;
    pnew->next=NULL;     //新节点指向空，因为后面还没有元素加入
    pend->next=pnew;     //旧节点的指针指向新节点
    pend=pnew;          //新节点变为旧节点
    scanf("%d",&n);
}
}
/**
 *  @name        : Status InitList(LinkList *L);
 *	@description : initialize an empty linked list with only the head node without value仅在没有值的头节点初始化空链表
 *	@param		 : L(the head node)  参数：头节点
 *	@return		 : Status  //Status是函数的类型,其值是函数结果状态代码，如OK等
 *  @notice      : None
 */

Status InitList(LinkedList *L) {         	//此处的L为二级指针，等价于LNode **L
*L=(LinkedList)malloc(sizeof(struct LNode));   /* 产生头结点,并使L指向此头结点 */
if(!(*L))
return ERROR;
(*L)->next=NULL; /* 指针域为空 */
return SUCCESS;
}

/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description : destroy a linked list, free all the nodes销毁链接列表，释放所有节点
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList(LinkedList *L) {
	LinkedList p,q;
	p=(*L)->next;          /*  p指向第一个结点 */
	while(p!=NULL)           /*  没到表尾 */
	{
		q=p->next;
		free(p);
		p=q;
	}
	(*L)=NULL;
	return SUCCESS;
}

/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p 节点P后插入节点Q
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertList(LNode *p, LNode *q) {
	LNode *p1,*p2;
	p1=p;
	p2=q;
	q->next=p->next;
	p->next=q;
}

/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e 删除节点P之后的第一个节点并将其值分配给E
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
Status DeleteList(LNode *p, ElemType *e) {
	LNode *p1=p->next;
	p->next=p1->next;
	*e=p1->data;
	free(p1);
	p1=NULL;
        return SUCCESS;
}


/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit 遍历链表并调用函数访问
 *	@param		 : L(the head node), visit
 *	@return		 : None
 *  @notice      : None
 */
void TraverseList(LinkedList L, void (*visit)(ElemType e)) {
	LinkedList p=L->next;
	printf("遍历链表的值为：");
	if(p==NULL)
	{return ERROR;}
	while(p!=NULL)
	{
		visit(p);
		p=p->next;
	}
	printf("\n");

}


/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e 根据e找到链表中的第一个节点
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
Status SearchList(LinkedList L, ElemType e) {
	LinkedList p1=L;
	while(p1!=NULL&&p1->data!=e)
	{
		p1=p1->next;
	}
	if(p1->data==e)
	return SUCCESS;
	else
		return ERROR;
}

/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list 反向链表
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status ReverseList(LinkedList *L) {
LNode *newhead=NULL,*p1=NULL;
newhead=(LNode*)malloc(sizeof(struct LNode));
newhead->next=NULL;
if(*L==NULL)
	return ERROR;
while((*L)->next!=NULL)
{
	p1=(*L)->next;
	(*L)->next=p1;
	p1=*L;
	*L=p1;
}
free(L);
return SUCCESS;
}
/**
 *  @name        : Status IsLoopList(LinkedList L)
 *	@description : judge whether the linked list is looped 判断链表是否为环
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status IsLoopList(LinkedList L) {
	LinkedList fast=L,slow=L;
while(fast!=NULL&&slow!=NULL)
{
	slow=slow->next;
	fast=fast->next->next;
}
if (fast==slow)
	return SUCCESS;
else
	return ERROR;
}




