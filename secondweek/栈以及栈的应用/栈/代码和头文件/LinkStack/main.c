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
	  printf("                                   菜  单\n");
	  printf("                    ======================================\n");
	  printf(" \n");
	  printf("                                  1  初始化\n");
	  printf("                                  2  元素入栈（整型）\n");
	  printf("                                  3  元素出栈（整型）\n");
	  printf("                                  4  取栈顶元素\n");
	  printf("                                  5  判断是否为空栈\n");
	  printf("                                  6  得到当前栈的长度\n");
	  printf("                                  7  输出栈中元素（从后往前）\n");
	  printf("                                  8  清空栈\n");
	  printf(" \n");
	  printf("                                  0  销毁栈\n");
	  printf(" \n");
	printf("*************************************************************************\n");

	printf(" \n");
	printf("                    请选择：（1/2/3/4/5/6/7/8/0）");

        scanf("%d",&select);
        printf("\n");
        while(select<=0 || select>=8)
	{
		printf("输入错误，请重新输入：");
		scanf("%d",&select);
	}
        while(select>=0 && select<=8)
	{
	switch(select)
        {
	case 1:
	{
		printf("%d、初始化链表：\n",select);
		initLStack(&s);
		break;
	}
	case 2:
	{
		printf("%d、请输入入栈元素：\n",select);
		scanf("%d",&data);
		pushLStack(&s,data);
		break;
	}
        case 3:
	{
		printf("%d、元素出栈成功！\n",select);
		popLStack(&s,&data);
		break;
	}
	case 4:
	{
		printf("%d、取栈顶元素：\n",select);
		getTopLStack(&s,&e);
		break;
	}
	case 5:
	{
		printf("%d、判断是否为空栈：\n",select);
		isEmptyLStack(&s);
		break;
	}
	case 6:
	{
		printf("%d、得到当前栈的长度：\n",select);
		LStackLength(&s,&length);
		printf("%d",length);
		break;
	}
	case 7:
	{
		printf("%d、输出栈中元素：\n",select);
		PrintfLinkStack(&s);
		break;
	}
	case 8:
	{
		printf("%d、清空栈：\n",select);
		clearLStack(&s);
		break;
        }
        case 0:
        	printf("%d、销毁栈：\n",select);
        	destroyLStack(&s);
        }
        printf("\n");
        printf("继续选择：（1/2/3/4/5/6/7/8/0）");
        scanf("%d",&select);
        while(select<0 || select>8)
	{
		printf("输入错误，请重新输入：");
		scanf("%d",&select);
		printf("\n");
	}
	}
	return 0;
}
