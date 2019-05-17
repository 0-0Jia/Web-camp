#include "qgsort.c"
#include <stdio.h>
#include <stdlib.h>
# include <time.h>

int main()
{
	//int a[] = {10,8,1,4,6,5,0,10,9};       //简单数组测试
	/*大数据下测试，随机生成数组*/
	int i,n;					//通过输入不同的n，生成n个随机数
	printf("Enter a number n:");
	scanf("%i",&n);
	int a[n];
	srand((unsigned)time(NULL));
	for(i=0;i<n;i++)
		a[i]=rand()%1000+1;         //通过更改百分号后数字更改随机数范围，例如测试随机数范围为0-1000
	//for(i=0;i<n;i++)
	//	printf("%4i",a[i]);         //输出随机函数

	int len = sizeof(a) / sizeof(a[0]);          //数组长度计算
	/*归并排序*/
	/*
	int *tmp = (int *)malloc(sizeof(int)*(sizeof(a) / sizeof(int)));
	memset(tmp, -1, sizeof(a) / sizeof(int));
	MergeSort(a, 0, sizeof(a) / sizeof(int)-1, tmp);
	*/

	//insertSort(a,len);         			//插入排序
	//QuickSort_Recursion(a,0,len-1);    		//快速递归版
	//QuickSortNonR(a,0,len-1);   			//快速非递归版
	//CountSort(a,len);          			//计数排序
	//ColorSort(a,len);          			//颜色排序

	/*基数排序*/
	/*
	int dec = 4;   			//数据位数，3代表3位数
	int order = 1;  			//排序的位数，1代表个位、2代表十位、3代表百位
	radix_sort(a,len,dec,order);
	*/

	Printf(a,len);			//输出
	return 0;
}
