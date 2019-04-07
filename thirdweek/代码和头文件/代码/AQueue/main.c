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
	  printf("                                   ��  ��\n");
	  printf("                    ======================================\n");
	  printf(" \n");
	  printf("                                  1  ��ʼ��\n");
	  printf("                                  2  Ԫ����ӣ����ͣ�\n");
	  printf("                                  3  Ԫ�س��ӣ����ͣ�\n");
	  printf("                                  4  ȡ��ͷԪ��\n");
	  printf("                                  5  �ж��Ƿ�Ϊ�ն���\n");
	  printf("                                  6  �ж϶����Ƿ�����\n");
	  printf("                                  7  �õ���ǰ���еĳ���\n");
	  printf("                                  8  ���������Ԫ�أ���ǰ����\n");
	  printf("                                  9  ��ն���\n");
	  printf(" \n");
	  printf("                                  0  ���ٶ���\n");
	  printf(" \n");
	printf("*************************************************************************\n");

	printf(" \n");
	printf("                    ��ѡ�񣺣�1/2/3/4/5/6/7/8/9/0��");

        scanf("%d",&select);
        printf("\n");
        while(select<=0 || select>=9)
	{
		printf("����������������룺");
		scanf("%d",&select);
	}
        while(select>=0 && select<=9)
	{
	switch(select)
        {
	case 1:
	{
		printf("%d����ʼ�����У�\n",select);
		InitAQueue(&q);
		break;
	}
	case 2:
	{
		printf("%d�����������Ԫ�أ�\n",select);
		scanf("%d",&data);
		EnAQueue(&q,&data);
		break;
	}
        case 3:
	{
		printf("%d��Ԫ�س��ӳɹ���\n",select);
		DeAQueue(&q);
		break;
	}
	case 4:
	{
		printf("%d��ȡ��ͷԪ�أ�\n",select);
		GetHeadAQueue(&q,&e);
		break;
	}
	case 5:
	{
		printf("%d���ж��Ƿ�Ϊ�ն��У�\n",select);
		IsEmptyAQueue(&q);
		break;
	}
	case 6:
	{
		printf("%d���ж϶����Ƿ�������\n",select);
		IsFullAQueue(&q);
		break;
	}
	case 7:
	{
		printf("%d���õ���ǰ���еĳ��ȣ�\n",select);
		count = LengthAQueue(&q);
		printf("%d",count);
		break;
	}
	case 8:
	{
		printf("%d�����������Ԫ�أ�\n",select);
		TraverseAQueue(&q,APrint);
		break;
        }
        case 9:
	{
		printf("%d����ն��У�\n",select);
		ClearAQueue(&q);
		break;
        }
        case 0:
        	printf("%d�����ٶ��У�\n",select);
        	DestoryAQueue(&q);
        }
        printf("\n");
        printf("����ѡ�񣺣�1/2/3/4/5/6/7/8/9/0��");
        scanf("%d",&select);
        while(select<0 || select>9)
	{
		printf("����������������룺");
		scanf("%d",&select);
		printf("\n");
	}
	}
	return 0;
}

