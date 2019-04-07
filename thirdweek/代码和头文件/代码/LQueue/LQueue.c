#include "../../ͷ�ļ�/LQueue.h"

//��ʽ����

/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : ��ʼ������
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void InitLQueue(LQueue *Q)
{
	if(!Q)
	{
		printf("��ʼ��ʧ�ܣ�");
		return FALSE;
	}
	else
	{
		Q->front = NULL;
		Q->rear = NULL ;
		Q->length = 0;
		printf("��ʼ���ɹ���");
		return TRUE;
	}
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : ���ٶ���
 *    @param         Q ����ָ��Q
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
 *    @description : �������Ƿ�Ϊ��
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue *Q)
{
	if(Q->front == Q->rear)
	{
		printf("�ö���Ϊ�գ�\n");
		return TRUE;
	}
	else
	{
		printf("�ö��зǿգ�\n");
		return FALSE;
	}
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, int *e)
 *    @description : �鿴��ͷԪ��
 *    @param         Q e ����ָ��Q,��������ָ��e
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ��
 */
Status GetHeadLQueue(LQueue *Q, int *e)
{
	if(Q->front == Q->rear)
	{
		printf("�ö���Ϊ�գ�\n");
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
 *    @description : ȷ�����г���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
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
		printf("�ö��еĵ�ǰ����Ϊ:",Q->length);
		return (Q->length);
	}
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, int *data)
 *    @description : ��Ӳ���
 *    @param         Q ����ָ��Q,�������ָ��data
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ�Ϊ��     (important!)
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
 *    @description : ���Ӳ���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue *Q)
{
	if(NULL == Q->front)
	{
		printf("�ö���Ϊ�գ�");
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
 *    @description : ��ն���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void ClearLQueue(LQueue *Q)
{
	if(NULL == Q->front)
	{
		printf("�ö�����Ϊ�գ�\n");
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
 *    @description : ������������
 *    @param         Q ����ָ��Q����������ָ��foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue *Q, int (*foo)(int *q))
{
	Node *node = Q->front;
	if(NULL == Q->front)
	{
		printf("�ö���Ϊ�գ�");
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
 *    @description : ��������
 *    @param         q ָ��q

 *  @notice      : None
 */
void LPrint(int *q)
{
	printf("%d\t",*q);
	return TRUE;
}

