#include "qgsort.c"
#include <stdio.h>
#include <stdlib.h>
# include <time.h>

int main()
{
	//int a[] = {10,8,1,4,6,5,0,10,9};       //���������
	/*�������²��ԣ������������*/
	int i,n;					//ͨ�����벻ͬ��n������n�������
	printf("Enter a number n:");
	scanf("%i",&n);
	int a[n];
	srand((unsigned)time(NULL));
	for(i=0;i<n;i++)
		a[i]=rand()%1000+1;         //ͨ�����İٷֺź����ָ����������Χ����������������ΧΪ0-1000
	//for(i=0;i<n;i++)
	//	printf("%4i",a[i]);         //����������

	int len = sizeof(a) / sizeof(a[0]);          //���鳤�ȼ���
	/*�鲢����*/
	/*
	int *tmp = (int *)malloc(sizeof(int)*(sizeof(a) / sizeof(int)));
	memset(tmp, -1, sizeof(a) / sizeof(int));
	MergeSort(a, 0, sizeof(a) / sizeof(int)-1, tmp);
	*/

	//insertSort(a,len);         			//��������
	//QuickSort_Recursion(a,0,len-1);    		//���ٵݹ��
	//QuickSortNonR(a,0,len-1);   			//���ٷǵݹ��
	//CountSort(a,len);          			//��������
	//ColorSort(a,len);          			//��ɫ����

	/*��������*/
	/*
	int dec = 4;   			//����λ����3����3λ��
	int order = 1;  			//�����λ����1�����λ��2����ʮλ��3�����λ
	radix_sort(a,len,dec,order);
	*/

	Printf(a,len);			//���
	return 0;
}
