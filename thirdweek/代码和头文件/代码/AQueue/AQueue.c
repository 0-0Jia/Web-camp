#include "../../头文件/AQueue.h"

/**
 *  @name        : void InitAQueue(AQueue *Q)
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void InitAQueue(AQueue *Q){
	if(!Q->data)
	{
		return FALSE;
	}
	Q->front = NULL;
	Q->rear = NULL;
	Q->length = MAXQUEUE;
	return TRUE;
}


/**
 *  @name        : void DestoryAQueue(AQueue *Q)
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void DestoryAQueue(AQueue *Q){
	Q->front = NULL;
	Q->rear = NULL;
	Q->length = 0;
	free(Q);
}



/**
 *  @name        : Status IsFullAQueue(const AQueue *Q)
 *    @description : 检查队列是否已满
 *    @param         Q 队列指针Q
 *    @return         : 满-TRUE; 未满-FALSE
 *  @notice      : None
 */
Status IsFullAQueue(const AQueue *Q){
	if((Q->rear+1)%MAXQUEUE == Q->front)
	{
		printf("队列已满！");
		return TRUE;
	}
	else
	{
		printf("队列还未满！");
		return FALSE;
	}
}

/**
 *  @name        : Status IsEmptyAQueue(const AQueue *Q)
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyAQueue(const AQueue *Q){
	if(Q->front == Q->rear)
	{
		printf("队列为空！");
		return TRUE;
	}
	else{
		printf("队列非空！");
		return FALSE;
	}
}



/**
 *  @name        : Status GetHeadAQueue(AQueue *Q, void *e)
 *    @description : 查看队头元素
 *    @param         Q 队列指针Q，存放元素e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadAQueue(AQueue *Q, int *e){
	if(Q->front == Q->rear)
	{
		printf("队列为空！");
		return FALSE;
	}
	else
	{
		*e = Q->data[Q->front];
		printf("%d",*e);
		printf("\n");
		return TRUE;
	}
}



/**
 *  @name        : int LengthAQueue(AQueue *Q)
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 队列长度count
 *  @notice      : None
 */
int LengthAQueue(AQueue *Q){
	int count;
	count = (Q->rear-Q->front+MAXQUEUE)%MAXQUEUE;
	return count;
}



/**
 *  @name        : Status EnAQueue(AQueue *Q, void *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否满了或为空
 */
Status EnAQueue(AQueue *Q, int *data){
	if((Q->rear+1)%MAXQUEUE == Q->front)
	{
		printf("队列已满！");
		return FALSE;
	}
	else
	{
		Q->data[Q->rear] = *data;
		Q->rear = (Q->rear+1)%MAXQUEUE;
		return TRUE;
	}
}



/**
 *  @name        : Status DeAQueue(AQueue *Q)
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeAQueue(AQueue *Q){
	if(Q->front == Q->rear)
	{
		printf("队列为空");
		return FALSE;
	}
	else
	{
		Q->front = (Q->front+1)%MAXQUEUE;
		return TRUE;
	}
}



/**
 *  @name        : void ClearAQueue(Queue *Q)
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void ClearAQueue(AQueue *Q){
	if(Q->front == Q->rear)
	{
		printf("该队列已空！");
		return FALSE;
	}
	else
	{
		Q->rear = Q->front;
		return TRUE;
	}
}



/**
 *  @name        : Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseAQueue(const AQueue *Q, int (*foo)(int *q)){
	int i = Q->front;
	while(i != Q->rear)
	{
		APrint(&(Q->data[i]));
		i = (i+1)%MAXQUEUE;
	}
	printf("\n");
	return TRUE;
}



/**
 *  @name        : void APrint(int *q)
 *    @description : 操作函数
 *    @param         q 指针q
 *  @notice      : None
 */
void APrint(int *q){
	printf("%d\t",*q);
	return TRUE;
}
