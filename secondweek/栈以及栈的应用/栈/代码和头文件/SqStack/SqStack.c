#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
#include "../head/SqStack.h"

//˳��ջ(���������)
Status initStack(SqStack *s,int sizes)  //��ʼ��ջ
{
	s->elem = (ElemType *)malloc(STACK_INIT_SIZE *sizeof(ElemType));  //���䶯̬�洢�ռ�
	if( !s->elem )                                      //������ʧ��
	{
		return ERROR;
	}
	s->top = -1;                                   //��ʼ��
	s->size = sizes;       //��ʼ������
	return SUCCESS;
}

Status isEmptyStack(SqStack *s)   //�ж�ջ�Ƿ�Ϊ��
{
	if( -1 == s->top )
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

Status getTopStack(SqStack *s,ElemType *e)   //�õ�ջ��Ԫ��
{
	if( s->top != -1)
	{
		*e = s->elem[s->top];
		printf("%d",*e);
		printf("\n");
	}
	else
	{
		printf("��ջΪ��ջ��\n");
		return ERROR;
	}
}

Status clearStack(SqStack *s)   //���ջ
{
	if(s->top == -1)
	{
		return SUCCESS;
	}
	else
	{
		s->top = -1;
		s->elem = NULL;
		return ERROR;
	}
}

Status destroyStack(SqStack *s)  //����ջ
{
	s->top = -1;
	s->elem = NULL;
	s->size = 0;
	return SUCCESS;
}

Status stackLength(SqStack *s,int *length)   //���ջ����
{
	*length = (s->top)+1;
	return SUCCESS;
}

Status pushStack(SqStack *s,ElemType data)  //��ջ
{
	if( NULL == s || s->top - s->size >= -1 )   //ջ��
	{
		return ERROR;
	}
	s->top++;                                  //ջ��ָ���һ
	s->elem[s->top] = data;                   //���²����Ԫ�ظ�ֵ��ջ���ռ�
	return SUCCESS;
}

Status popStack(SqStack *s,ElemType *data)   //��ջ
{
	if( NULL == s || s->top == -1)
	{
		return ERROR;
	}
	*data = s->elem[s->top];
	s->top--;
	return SUCCESS;
}

