#include "../头文件/BinaryTree.h"
//(请按前序遍历方式输入)
/**
 *  @name        : Status InitBiTree(BiTree T);
 *  @description : 构造空二叉树T
 *  @param       : 二叉树根结点T
 */
Status InitBiTree(BiTree *T)
{
	*T = NULL;
}

/**
 *  @name        : Status DestroyBiTree(BiTree T);
 *  @description : 摧毁二叉树T
 *  @param       : 二叉树根结点T
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
 *  @description : 构造二叉树T
 *  @param       : 二叉树根结点T, 二叉树先序遍历字符串definition
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
 *  @description : 先序遍历二叉树T
 *  @param       : 二叉树根结点T, 对结点的操作函数visit
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
 *  @description : 中序遍历二叉树T
 *  @param       : 二叉树根结点T, 对结点的操作函数visit
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
 *  @description : 后序遍历二叉树T
 *  @param       : 二叉树根结点T, 对结点的操作函数visit
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
 *  @description : 层序遍历二叉树T
 *  @param       : 二叉树根结点T, 对结点的操作函数visit
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
 *  @description : 对构造出的前缀表达式二叉树求值
 *  @param       : 二叉树根结点T
 *  @note        : 可在结点结构体中设置个Tag值标志数字与操作符来构造二叉树，
 *                 可根据需要自行增加操作.
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

