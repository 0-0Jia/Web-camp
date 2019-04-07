#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "LQueue.c"

int main()
{
	LQueue q;
	int select = 1,count = 0, data, e;
	printf("****************You can use it to implement the LQueue****************\n");

	  printf(" \n");
	  printf("                    ======================================\n");
	  printf("                                   ��  ��\n");
	  printf("                    ======================================\n");
	  printf(" \n");
	  printf("                                  1  ��ʼ��\n");
	  printf("                                  2  Ԫ����ӣ����ͣ�\n");
	  printf("                                  3  Ԫ�س��ӣ����ͣ�\n");
	  printf("                                  4  ȡ��ͷԪ��\n");
	  printf("                                  5  �ж��Ƿ�Ϊ�ն���\n");
	  printf("                                  6  �õ���ǰ���еĳ���\n");
	  printf("                                  7  ���������Ԫ�أ���ǰ����\n");
	  printf("                                  8  ��ն���\n");
	  printf(" \n");
	  printf("                                  0  ���ٶ���\n");
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
		printf("%d����ʼ�����У�\n",select);
		InitLQueue(&q);
		break;
	}
	case 2:
	{
		printf("%d�����������Ԫ�أ�\n",select);
		scanf("%d",&data);
		EnLQueue(&q,&data);
		break;
	}
        case 3:
	{
		printf("%d��Ԫ�س��ӳɹ���\n",select);
		DeLQueue(&q);
		break;
	}
	case 4:
	{
		printf("%d��ȡ��ͷԪ�أ�\n",select);
		GetHeadLQueue(&q,&e);
		break;
	}
	case 5:
	{
		printf("%d���ж��Ƿ�Ϊ�ն��У�\n",select);
		IsEmptyLQueue(&q);
		break;
	}
	case 6:
	{
		printf("%d���õ���ǰ���еĳ��ȣ�\n",select);
		count = LengthLQueue(&q);
		printf("%d",count);
		break;
	}
	case 7:
	{
		printf("%d�����������Ԫ�أ�\n",select);
		TraverseLQueue(&q,LPrint);
		break;
        }
        case 8:
	{
		printf("%d����ն��У�\n",select);
		ClearLQueue(&q);
		break;
        }
        case 0:
        	printf("%d�����ٶ��У�\n",select);
        	DestoryLQueue(&q);
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

