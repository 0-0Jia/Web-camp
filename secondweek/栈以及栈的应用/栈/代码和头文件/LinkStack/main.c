#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "LinkStack.c"

int main()
{
	ElemType data, e;
	LinkStack s;
	int select = 1,length = 0;
	printf("****************You can use it to implement the Linkstack****************\n");

	  printf(" \n");
	  printf("                    ======================================\n");
	  printf("                                   ��  ��\n");
	  printf("                    ======================================\n");
	  printf(" \n");
	  printf("                                  1  ��ʼ��\n");
	  printf("                                  2  Ԫ����ջ�����ͣ�\n");
	  printf("                                  3  Ԫ�س�ջ�����ͣ�\n");
	  printf("                                  4  ȡջ��Ԫ��\n");
	  printf("                                  5  �ж��Ƿ�Ϊ��ջ\n");
	  printf("                                  6  �õ���ǰջ�ĳ���\n");
	  printf("                                  7  ���ջ��Ԫ�أ��Ӻ���ǰ��\n");
	  printf("                                  8  ���ջ\n");
	  printf(" \n");
	  printf("                                  0  ����ջ\n");
	  printf(" \n");
	printf("*************************************************************************\n");

	printf(" \n");
	printf("                    ��ѡ�񣺣�1/2/3/4/5/6/7/8/0��");

        scanf("%d",&select);
        printf("\n");
        while(select<=0 || select>=8)
	{
		printf("����������������룺");
		scanf("%d",&select);
	}
        while(select>=0 && select<=8)
	{
	switch(select)
        {
	case 1:
	{
		printf("%d����ʼ������\n",select);
		initLStack(&s);
		break;
	}
	case 2:
	{
		printf("%d����������ջԪ�أ�\n",select);
		scanf("%d",&data);
		pushLStack(&s,data);
		break;
	}
        case 3:
	{
		printf("%d��Ԫ�س�ջ�ɹ���\n",select);
		popLStack(&s,&data);
		break;
	}
	case 4:
	{
		printf("%d��ȡջ��Ԫ�أ�\n",select);
		getTopLStack(&s,&e);
		break;
	}
	case 5:
	{
		printf("%d���ж��Ƿ�Ϊ��ջ��\n",select);
		isEmptyLStack(&s);
		break;
	}
	case 6:
	{
		printf("%d���õ���ǰջ�ĳ��ȣ�\n",select);
		LStackLength(&s,&length);
		printf("%d",length);
		break;
	}
	case 7:
	{
		printf("%d�����ջ��Ԫ�أ�\n",select);
		PrintfLinkStack(&s);
		break;
	}
	case 8:
	{
		printf("%d�����ջ��\n",select);
		clearLStack(&s);
		break;
        }
        case 0:
        	printf("%d������ջ��\n",select);
        	destroyLStack(&s);
        }
        printf("\n");
        printf("����ѡ�񣺣�1/2/3/4/5/6/7/8/0��");
        scanf("%d",&select);
        while(select<0 || select>8)
	{
		printf("����������������룺");
		scanf("%d",&select);
		printf("\n");
	}
	}
	return 0;
}
