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
	printf("************************���������ʵ��˳��ջ��************************\n");
	initStack(&s,sizes);
	printf("��������ջԪ�أ�ע������Ϊ����������ÿ��Ԫ��Ҫ���У�������1111111111��ʾ������\n");
	scanf("%d",&data);
        do
	{
		pushStack(&s,data);
		scanf("%d",&data);
	}while(data!= 1111111111);
	printf("�õ���ǰջ�ĳ��ȡ���");
	stackLength(&s,&length);
	printf("ջ��ǰ�ĳ���Ϊ��%d\n",length);
	printf("Ԫ����ջ��\n");
	scanf("%d",&data);
	pushStack(&s,data);
	stackLength(&s,&length);
	printf("ջ��ǰ�ĳ���Ϊ��%d\n",length);
	printf("Ԫ�س�ջ��\n");
	popStack(&s,&data);
	stackLength(&s,&length);
	printf("ջ��ǰ�ĳ���Ϊ��%d\n",length);
	printf("ȡջ��Ԫ�أ�\n");
	getTopStack(&s,&e);
	printf("�ж��Ƿ�Ϊ��ջ��\n");
	isEmptyStack(&s);
	printf("���ջ��\n");
	clearStack(&s);
	stackLength(&s,&length);
	printf("ջ��ǰ�ĳ���Ϊ��%d\n",length);
	printf("����ջ��\n");
	destroyStack(&s);
	printf("*********************************End**********************************");
}
