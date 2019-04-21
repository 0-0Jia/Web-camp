#include "../ͷ�ļ�/BinaryTree.h"
//(�밴ǰ�������ʽ����)
/**
 *  @name        : Status InitBiTree(BiTree T);
 *  @description : ����ն�����T
 *  @param       : �����������T
 */
Status InitBiTree(BiTree *T)
{
	*T = NULL;
}

/**
 *  @name        : Status DestroyBiTree(BiTree T);
 *  @description : �ݻٶ�����T
 *  @param       : �����������T
 */
Status DestroyBiTree(BiTree *T)
{
	if(*T)
	{
		DestroyBiTree(&(*T)->lchild);
		DestroyBiTree(&(*T)->lchild);
		free(*T);
	}
	else
	{
		return ERROR;
	}
}


/**
 *  @name        : Status CreateBiTree(BiTree T, char* definition);
 *  @description : ���������T
 *  @param       : �����������T, ��������������ַ���definition
 */
Status CreateBiTree(BiTree *T, char* definition)
{
	char c = *definition;
	for(;*definition != "#";*definition++)
	{
	if(c == ' ')
	{
		*T = NULL;
	}
	else
	{
		*T = (BiTNode *)malloc(sizeof(BiTNode));
		(*T)->data = c;
		CreateBiTree(&(*T)->lchild,definition);
		CreateBiTree(&(*T)->rchild,definition);
	}
	visit(*definition);
	}
}

void visit(TElemType e)
{
	printf("%c",e);
}
/**
 *  @name        : Status PreOrderTraverse(BiTree T, Status (*visit)(TElemType e));
 *  @description : �������������T
 *  @param       : �����������T, �Խ��Ĳ�������visit
 */
Status PreOrderTraverse(BiTree T, Status (*visit)(TElemType e))
{
	if(T)
	{
		visit(T->data);
		PreOrderTraverse(T->lchild,T->data);
		PreOrderTraverse(T->rchild,T->data);
	}
	else
	{
		return ERROR;
	}
}


/**
 *  @name        : Status InOrderTraverse(BiTree T, Status (*visit)(TElemType e));
 *  @description : �������������T
 *  @param       : �����������T, �Խ��Ĳ�������visit
 */
Status InOrderTraverse(BiTree T, Status (*visit)(TElemType e))
{
	if(T)
	{
		PreOrderTraverse(T->lchild,T->data);
		visit(T->data);
		PreOrderTraverse(T->rchild,T->data);
	}
	else
	{
		return ERROR;
	}
}


/**
 *  @name        : Status PostOrderTraverse(BiTree T, Status (*visit)(TElemType e)));
 *  @description : �������������T
 *  @param       : �����������T, �Խ��Ĳ�������visit
 */
Status PostOrderTraverse(BiTree T, Status (*visit)(TElemType e))
{
	if(T)
	{
		PreOrderTraverse(T->lchild,T->data);
		PreOrderTraverse(T->rchild,T->data);
		visit(T->data);
	}
	else
	{
		return ERROR;
	}
}


pQueue init(pQueue pq){
	pq->front=(pQueueNode)malloc(sizeof(QueueNode));
	pq->front->next=NULL;
	pq->rear=pq->front;
	return pq;
}

void enqueue(pQueue pq,BiTree T){
	pQueueNode pNew=(pQueueNode)malloc(sizeof(QueueNode));
	pNew->data=*T;
	pNew->next=NULL;
	pq->rear->next=pNew;
	pq->rear=pNew;
}

BiTree dequeue(pQueue pq){
	pQueueNode pTemp=(pQueueNode)malloc(sizeof(QueueNode));
	pTemp=pq->front->next;
	if(pTemp->next==NULL){
		pq->rear=pq->front;
	}else{
		pq->front->next=pTemp->next;
	}
	BiTree x=pTemp;
	free(pTemp);
	return x;
}


/**
 *  @name        : Status LevelOrderTraverse(BiTree T, Status (*visit)(TElemType e));
 *  @description : �������������T
 *  @param       : �����������T, �Խ��Ĳ�������visit
 */
Status LevelOrderTraverse(BiTree T, Status (*visit)(TElemType e))
{
	pQueue pq=(pQueue)malloc(sizeof(Queue));
	pq=init(pq);
	enqueue(pq,T);
	while(pq->rear!=pq->front){
		BiTree x=dequeue(pq);
		printf("%d ",x->data);
		if(x->lchild){
			enqueue(pq,x->lchild);
			visit(x->lchild);
		}
		if(x->rchild){
			enqueue(pq,x->rchild);
			visit(x->rchild);
		}
	}
}


/**
 *  @name        : int Value(BiTree T);
 *  @description : �Թ������ǰ׺���ʽ��������ֵ
 *  @param       : �����������T
 *  @note        : ���ڽ��ṹ�������ø�Tagֵ��־������������������������
 *                 �ɸ�����Ҫ�������Ӳ���.
 */
int Value(BiTree T,int ans)
{

	char ch = T->data;
	if (isdigit(ch))  return ch - '0';
	switch (ch)
	{
	case '+':  ans = T->lchild->data + T->rchild->data; break;
	case '-':  ans = T->lchild->data - T->rchild->data; break;
	case '*':  ans = T->lchild->data * T->rchild->data; break;
	case '/':  ans = T->lchild->data / T->rchild->data; break;
	}
	return ans;
}

