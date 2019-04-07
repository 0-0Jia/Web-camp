#include "../../ͷ�ļ�/AQueue.h"

/**
 *  @name        : void InitAQueue(AQueue *Q)
 *    @description : ��ʼ������
 *    @param         Q ����ָ��Q
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
 *    @description : ���ٶ���
 *    @param         Q ����ָ��Q
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
 *    @description : �������Ƿ�����
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
 *  @notice      : None
 */
Status IsFullAQueue(const AQueue *Q){
	if((Q->rear+1)%MAXQUEUE == Q->front)
	{
		printf("����������");
		return TRUE;
	}
	else
	{
		printf("���л�δ����");
		return FALSE;
	}
}

/**
 *  @name        : Status IsEmptyAQueue(const AQueue *Q)
 *    @description : �������Ƿ�Ϊ��
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
 *  @notice      : None
 */
Status IsEmptyAQueue(const AQueue *Q){
	if(Q->front == Q->rear)
	{
		printf("����Ϊ�գ�");
		return TRUE;
	}
	else{
		printf("���зǿգ�");
		return FALSE;
	}
}



/**
 *  @name        : Status GetHeadAQueue(AQueue *Q, void *e)
 *    @description : �鿴��ͷԪ��
 *    @param         Q ����ָ��Q�����Ԫ��e
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ��
 */
Status GetHeadAQueue(AQueue *Q, int *e){
	if(Q->front == Q->rear)
	{
		printf("����Ϊ�գ�");
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
 *    @description : ȷ�����г���
 *    @param         Q ����ָ��Q
 *    @return         : ���г���count
 *  @notice      : None
 */
int LengthAQueue(AQueue *Q){
	int count;
	count = (Q->rear-Q->front+MAXQUEUE)%MAXQUEUE;
	return count;
}



/**
 *  @name        : Status EnAQueue(AQueue *Q, void *data)
 *    @description : ��Ӳ���
 *    @param         Q ����ָ��Q,�������ָ��data
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ����˻�Ϊ��
 */
Status EnAQueue(AQueue *Q, int *data){
	if((Q->rear+1)%MAXQUEUE == Q->front)
	{
		printf("����������");
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
 *    @description : ���Ӳ���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
Status DeAQueue(AQueue *Q){
	if(Q->front == Q->rear)
	{
		printf("����Ϊ��");
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
 *    @description : ��ն���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void ClearAQueue(AQueue *Q){
	if(Q->front == Q->rear)
	{
		printf("�ö����ѿգ�");
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
 *    @description : ������������
 *    @param         Q ����ָ��Q����������ָ��foo
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
 *    @description : ��������
 *    @param         q ָ��q
 *  @notice      : None
 */
void APrint(int *q){
	printf("%d\t",*q);
	return TRUE;
}
