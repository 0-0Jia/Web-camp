#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
#include "SqStack.c"

int main()
{
	ElemType e;
	ElemType data;
	SqStack s;
	int length,sizes=STACK_INIT_SIZE;
	printf("************************这个终于能实现顺序栈啦************************\n");
	initStack(&s,sizes);
	printf("请输入入栈元素，注意这里为整型且输入每个元素要换行，当输入1111111111表示结束！\n");
	scanf("%d",&data);
        do
	{
		pushStack(&s,data);
		scanf("%d",&data);
	}while(data!= 1111111111);
	printf("得到当前栈的长度——");
	stackLength(&s,&length);
	printf("栈当前的长度为：%d\n",length);
	printf("元素入栈：\n");
	scanf("%d",&data);
	pushStack(&s,data);
	stackLength(&s,&length);
	printf("栈当前的长度为：%d\n",length);
	printf("元素出栈：\n");
	popStack(&s,&data);
	stackLength(&s,&length);
	printf("栈当前的长度为：%d\n",length);
	printf("取栈顶元素：\n");
	getTopStack(&s,&e);
	printf("判断是否为空栈：\n");
	isEmptyStack(&s);
	printf("清空栈：\n");
	clearStack(&s);
	stackLength(&s,&length);
	printf("栈当前的长度为：%d\n",length);
	printf("销毁栈：\n");
	destroyStack(&s);
	printf("*********************************End**********************************");
}
