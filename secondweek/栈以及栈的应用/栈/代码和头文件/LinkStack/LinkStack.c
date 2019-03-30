#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "../head/LinkStack.h"


//��ջ(���������)
Status initLStack(LinkStack *s)   //��ʼ��
{
	if(!s)
	{
		return ERROR;
		printf("��ʼ��ʧ�ܣ�");
	}
	else
	{
		s->top = NULL;
		s->count = 0 ;
		printf("��ʼ���ɹ���");
		return SUCCESS;
	}
}

Status isEmptyLStack(LinkStack *s)  //�ж���ջ�Ƿ�Ϊ��
{
	if(NULL == s->top || s->count == 0)
	{
		printf("��ջΪ��ջ��\n");
		return SUCCESS;
	}
	else
	{
		printf("��ջ�ǿ�ջ��\n");
		return ERROR;
	}
}

Status getTopLStack(LinkStack *s,ElemType *e)  //�õ�ջ��Ԫ��
{
	if((NULL != s->top) && s->count)
	{
		*e = s->top->data;
		printf("%d\n",*e);
		return SUCCESS;
	}
	else
	{
		return ERROR;
	}
}

Status clearLStack(LinkStack *s)   //���ջ
{
	if(NULL == s->top || s->count == 0)
	{
		printf("��ջ��Ϊ��ջ��\n");
		return ERROR;
	}
	else
	{
		s->top == NULL;
		s->count = 0;
		return SUCCESS;
	}

}

Status destroyLStack(LinkStack *s)   //����ջ
{

	s->top = NULL;
	s->count = 0;
	free(s);
	return SUCCESS;
}

Status LStackLength(LinkStack *s,int *length)    //���ջ����
{
	if(!s)
	{
		return ERROR;
	}
	else
	{
		*length = (int)(s->count);
		printf("��ջ�ĵ�ǰ����Ϊ:");
		return SUCCESS;
	}

}

Status pushLStack(LinkStack *s,ElemType data)   //��ջ
{
	if(!s)
	{
		return ERROR;
	}
	StackNode *node = (StackNode*)malloc(sizeof(StackNode));
	node->next = s->top;
	node->data = data;
	s->top = node;
	s->count++;
	return SUCCESS;
}

Status popLStack(LinkStack *s,ElemType *data)   //��ջ
{
	if(NULL == s->top || s->count == 0)   //�ж��Ƿ�Ϊ��ջ
	{
		return ERROR;
	}
	StackNode* node = s->top;
	*data = node->data;
	s->top = node->next;
	free(node);
	s->count--;
	return SUCCESS;

}

//�º�������ӡ������Ԫ��
Status PrintfLinkStack(LinkStack *s)
{
	if ( NULL == s || s->count == 0)
	{
		return ERROR;
	}
	StackNode* node = s->top;
	while (node)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	printf("\n");
	return SUCCESS;
}

