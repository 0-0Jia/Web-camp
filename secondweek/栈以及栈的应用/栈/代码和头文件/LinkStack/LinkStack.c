#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "../head/LinkStack.h"


//链栈(基于链表的)
Status initLStack(LinkStack *s)   //初始化
{
	if(!s)
	{
		return ERROR;
		printf("初始化失败！");
	}
	else
	{
		s->top = NULL;
		s->count = 0 ;
		printf("初始化成功！");
		return SUCCESS;
	}
}

Status isEmptyLStack(LinkStack *s)  //判断链栈是否为空
{
	if(NULL == s->top || s->count == 0)
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

Status getTopLStack(LinkStack *s,ElemType *e)  //得到栈顶元素
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

Status clearLStack(LinkStack *s)   //清空栈
{
	if(NULL == s->top || s->count == 0)
	{
		printf("该栈已为空栈！\n");
		return ERROR;
	}
	else
	{
		s->top == NULL;
		s->count = 0;
		return SUCCESS;
	}

}

Status destroyLStack(LinkStack *s)   //销毁栈
{

	s->top = NULL;
	s->count = 0;
	free(s);
	return SUCCESS;
}

Status LStackLength(LinkStack *s,int *length)    //检测栈长度
{
	if(!s)
	{
		return ERROR;
	}
	else
	{
		*length = (int)(s->count);
		printf("该栈的当前长度为:");
		return SUCCESS;
	}

}

Status pushLStack(LinkStack *s,ElemType data)   //入栈
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

Status popLStack(LinkStack *s,ElemType *data)   //出栈
{
	if(NULL == s->top || s->count == 0)   //判断是否为空栈
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

//新函数：打印出链表元素
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

