#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
#include "../head/SqStack.h"

//顺序栈(基于数组的)
Status initStack(SqStack *s,int sizes)  //初始化栈
{
	s->elem = (ElemType *)malloc(STACK_INIT_SIZE *sizeof(ElemType));  //分配动态存储空间
	if( !s->elem )                                      //若分配失败
	{
		return ERROR;
	}
	s->top = -1;                                   //初始化
	s->size = sizes;       //初始化容量
	return SUCCESS;
}

Status isEmptyStack(SqStack *s)   //判断栈是否为空
{
	if( -1 == s->top )
	{
		printf("该栈为空栈！\n");
		return SUCCESS;
	}
	else
	{
		printf("该栈非空栈！\n");
		return ERROR;
	}
}

Status getTopStack(SqStack *s,ElemType *e)   //得到栈顶元素
{
	if( s->top != -1)
	{
		*e = s->elem[s->top];
		printf("%d",*e);
		printf("\n");
	}
	else
	{
		printf("该栈为空栈！\n");
		return ERROR;
	}
}

Status clearStack(SqStack *s)   //清空栈
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

Status destroyStack(SqStack *s)  //销毁栈
{
	s->top = -1;
	s->elem = NULL;
	s->size = 0;
	return SUCCESS;
}

Status stackLength(SqStack *s,int *length)   //检测栈长度
{
	*length = (s->top)+1;
	return SUCCESS;
}

Status pushStack(SqStack *s,ElemType data)  //入栈
{
	if( NULL == s || s->top - s->size >= -1 )   //栈满
	{
		return ERROR;
	}
	s->top++;                                  //栈顶指针加一
	s->elem[s->top] = data;                   //将新插入的元素赋值给栈顶空间
	return SUCCESS;
}

Status popStack(SqStack *s,ElemType *data)   //出栈
{
	if( NULL == s || s->top == -1)
	{
		return ERROR;
	}
	*data = s->elem[s->top];
	s->top--;
	return SUCCESS;
}

