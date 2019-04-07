#include "../../头文件/LQueue.h"

//链式队列

/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void InitLQueue(LQueue *Q)
{
	if(!Q)
	{
		printf("初始化失败！");
		return FALSE;
	}
	else
	{
		Q->front = NULL;
		Q->rear = NULL ;
		Q->length = 0;
		printf("初始化成功！");
		return TRUE;
	}
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue *Q)
{
	Q->front = NULL;
	Q->rear = NULL;
	Q->length = 0;
	free(Q);
	return TRUE;
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue *Q)
{
	if(Q->front == Q->rear)
	{
		printf("该队列为空！\n");
		return TRUE;
	}
	else
	{
		printf("该队列非空！\n");
		return FALSE;
	}
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, int *e)
 *    @description : 查看队头元素
 *    @param         Q e 队列指针Q,返回数据指针e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadLQueue(LQueue *Q, int *e)
{
	if(Q->front == Q->rear)
	{
		printf("该队列为空！\n");
		return FALSE;
	}
	else
	{
		*e = Q->front->data;
		printf("%d\n",*e);
		return TRUE;
	}
}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue *Q)
{
	if(!Q)
	{
		return FALSE;
	}
	else
	{
		printf("该队列的当前长度为:",Q->length);
		return (Q->length);
	}
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, int *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否为空     (important!)
 */
Status EnLQueue(LQueue *Q, int *data)
{
	Node *node = (Node*)malloc(sizeof(Node));
		if(node == NULL)
		{
			return FALSE;
		}
		node->next = NULL;
	if(Q->front == NULL)
	{
		Q->front = Q->rear = node;
		Q->front->data = *data;
		Q->length++;
	}
	else
	{
		Q->rear->next = node;
		Q->rear = Q->rear->next;
		Q->rear->data = *data;
		Q->length++;
	}
	return TRUE;
}

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue *Q)
{
	if(NULL == Q->front)
	{
		printf("该队列为空！");
		return FALSE;
	}
	else
	{
		Node *Del;
		Del = Q->front;
		Q->front = Q->front->next;
		free(Del);
		Del = NULL;
		Q->length--;
	}
	return TRUE;

}

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void ClearLQueue(LQueue *Q)
{
	if(NULL == Q->front)
	{
		printf("该队列已为空！\n");
		return TRUE;
	}
	else
	{
		Q->front = NULL;
		Q->rear = NULL;
		return FALSE;
	}
}

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, int (*foo)(int *q))
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue *Q, int (*foo)(int *q))
{
	Node *node = Q->front;
	if(NULL == Q->front)
	{
		printf("该队列为空！");
		return FALSE;
	}
	else
	{
		while(node)
		{
			LPrint(&(node->data));
			node = node->next;
		}
		return TRUE;
	}
}

/**
 *  @name        : void LPrint(int *q)
 *    @description : 操作函数
 *    @param         q 指针q

 *  @notice      : None
 */
void LPrint(int *q)
{
	printf("%d\t",*q);
	return TRUE;
}

