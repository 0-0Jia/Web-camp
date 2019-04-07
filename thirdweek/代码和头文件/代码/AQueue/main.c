#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "AQueue.c"

int main()
{
	AQueue q;
	int select = 1,count = 0, data, e;
	int *p;
	printf("****************You can use it to implement the AQueue****************\n");

	  printf(" \n");
	  printf("                    ======================================\n");
	  printf("                                   菜  单\n");
	  printf("                    ======================================\n");
	  printf(" \n");
	  printf("                                  1  初始化\n");
	  printf("                                  2  元素入队（整型）\n");
	  printf("                                  3  元素出队（整型）\n");
	  printf("                                  4  取对头元素\n");
	  printf("                                  5  判断是否为空队列\n");
	  printf("                                  6  判断队列是否已满\n");
	  printf("                                  7  得到当前队列的长度\n");
	  printf("                                  8  输出队列中元素（从前往后）\n");
	  printf("                                  9  清空队列\n");
	  printf(" \n");
	  printf("                                  0  销毁队列\n");
	  printf(" \n");
	printf("*************************************************************************\n");

	printf(" \n");
	printf("                    请选择：（1/2/3/4/5/6/7/8/9/0）");

        scanf("%d",&select);
        printf("\n");
        while(select<=0 || select>=9)
	{
		printf("输入错误，请重新输入：");
		scanf("%d",&select);
	}
        while(select>=0 && select<=9)
	{
	switch(select)
        {
	case 1:
	{
		printf("%d、初始化队列：\n",select);
		InitAQueue(&q);
		break;
	}
	case 2:
	{
		printf("%d、请输入入队元素：\n",select);
		scanf("%d",&data);
		EnAQueue(&q,&data);
		break;
	}
        case 3:
	{
		printf("%d、元素出队成功！\n",select);
		DeAQueue(&q);
		break;
	}
	case 4:
	{
		printf("%d、取队头元素：\n",select);
		GetHeadAQueue(&q,&e);
		break;
	}
	case 5:
	{
		printf("%d、判断是否为空队列：\n",select);
		IsEmptyAQueue(&q);
		break;
	}
	case 6:
	{
		printf("%d、判断队列是否已满：\n",select);
		IsFullAQueue(&q);
		break;
	}
	case 7:
	{
		printf("%d、得到当前队列的长度：\n",select);
		count = LengthAQueue(&q);
		printf("%d",count);
		break;
	}
	case 8:
	{
		printf("%d、输出队列中元素：\n",select);
		TraverseAQueue(&q,APrint);
		break;
        }
        case 9:
	{
		printf("%d、清空队列：\n",select);
		ClearAQueue(&q);
		break;
        }
        case 0:
        	printf("%d、销毁队列：\n",select);
        	DestoryAQueue(&q);
        }
        printf("\n");
        printf("继续选择：（1/2/3/4/5/6/7/8/9/0）");
        scanf("%d",&select);
        while(select<0 || select>9)
	{
		printf("输入错误，请重新输入：");
		scanf("%d",&select);
		printf("\n");
	}
	}
	return 0;
}

