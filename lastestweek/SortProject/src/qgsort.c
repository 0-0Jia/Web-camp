# include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<assert.h>
#include<malloc.h>
#include<unistd.h>

#include "../inc/qgsort.h"

/**
 *  @name        : void insertSort(int *a,int n);
 *  @description : 插入排序
 *  @param       : 数组指针 a, 数组长度 n
 */
void insertSort(int *a,int n){
	for (int i = 1; i < n; ++i)
	{
		//挪动数据
		int tmp = a[i];//待插入数据
		int end = i - 1;
		while (end >= 0 && a[end]>tmp)
		{
			a[end + 1] = a[end];
			--end;
		}
		a[end + 1] = tmp;
	}
}


/**
 *  @name        : void MergeArray(int *a,int begin,int mid,int end,int *temp);
 *  @description : 归并排序（合并数组）
 *  @param       : 数组指针a，数组起点begin，数组中点mid，数组终点end，承载数组指针temp
 */
void MergeArray(int *a, int begin1, int end1, int begin2, int end2, int *tmp){
	int index = begin1;
	int i = begin1, j = begin2;
	//注意:当划分的区间足够小时,begin1==end1,begin2==end2
	while (i <= end1&&j <= end2){
		if (a[i]<=a[j])
			tmp[index++] = a[i++];
		else
			tmp[index++] = a[j++];
	}
	//将左边元素填充到tmp中
	while (i <= end1)
		tmp[index++] = a[i++];
	//将右边元素填充的tmp中
	while (j <= end2)
		tmp[index++] = a[j++];
	//将tmp中的数据拷贝到原数组对应的序列区间
	//注意:end2-begin1+1
	memcpy(a + begin1, tmp + begin1, sizeof(int)*(end2 - begin1 + 1));
}


/**
 *  @name        : void MergeSort(int *a, int left, int right, int *tmp)
 *  @description : 归并排序
 *  @param       : 数组指针a，数组起点left，数组终点right，承载数组指针tmp
 */
void MergeSort(int *a, int left, int right, int *tmp)
{
	if (left >= right)
		return;
	assert(a);
	//mid将数组二分
	int mid = left + ((right - left) >> 1);
	//左边归并排序,使得左子序列有序
	MergeSort(a, left, mid, tmp);
	//右边归并排序,使得右子序列有序
	MergeSort(a, mid + 1, right, tmp);
	//将两个有序子数组合并
	MergeArray(a, left, mid, mid + 1, right, tmp);
}
/**
 *  @name        : QuickSort_Recursion(int *a, int left, int right)
 *  @description : 快速排序（递归版）
 *  @param       : 数组指针a，数组起点left，数组终点right
 */
void QuickSort_Recursion(int *a, int left, int right){
		//定义左右指针指向数组的下标
	int i = left;
	int j = right;

	//递归出口
	if(i>j)
		return;

	//记录标杆值
	int pivot = a[i];

	//一次循环可以得到：标杆的左侧都比标杆小，标杆的右侧都比标杆大
	while(i<j)
	{
		//从right开始找比标杆小的为止
		while(i<j && a[j]>=pivot)
			j--;

		//将较小的数赋值到left上
		a[i] = a[j];

		//从left开始找比标杆大的为止
		while(i<j && a[i]<=pivot)
			i++;

		//将较大的数赋值到right上
		a[j] = a[i];
	}
	//将标杆值补到数组中
	a[i] = pivot;
	//一次循环完成

	//进行左侧和右侧的递归
	QuickSort_Recursion(a,left,i-1);
	QuickSort_Recursion(a,i+1,right);

}
//交换函数
void swap(int x,int y)
{
int temp;
temp=x;
x=y;
y=temp;
}

/**
 *  @name        : QuickSortNonR(int* a, int left, int right)
 *  @description : 快速排序（非递归版）
 *  @param       : 数组指针a，数组起点left，数组终点right
 */

void StackInit(Stack* ps)
{
	assert(ps);
	ps->_a = NULL;
	ps->_capacity = 0;
	ps->_top = 0;
}
void StackDestory(Stack* ps)
{
	assert(ps);
	free(ps->_a);
	ps->_a = NULL;
	ps->_capacity = 0;
	ps->_top = 0;

}

void StackPush(Stack* ps, STDatatype x)
{
	assert(ps);
	if (ps->_top == ps->_capacity)
	{
		size_t newcapacity = ps->_capacity == 0 ? 4 : ps->_capacity * 2;
		ps->_a = (STDatatype*)realloc(ps->_a, sizeof(STDatatype)*newcapacity);
		assert(ps->_a);
		ps->_capacity = newcapacity;
	}
	ps->_a[ps->_top] = x;
	ps->_top++;
}
void StackPop(Stack* ps)
{
	assert(ps && ps->_top > 0);
	ps->_top--;
}
STDatatype StackTop(Stack* ps)
{
	assert(ps);
	return ps->_a[ps->_top - 1];
}
int StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->_top == 0 ? 0 : 1;
}
void QuickSortNonR(int* a, int left, int right)
{
	Stack st;
	StackInit(&st);
	StackPush(&st, right);
	StackPush(&st, left);
	while (StackEmpty(&st) != 0)
	{
		int begin = StackTop(&st);
		StackPop(&st);
		int end = StackTop(&st);
		StackPop(&st);
		int div = Partition(a, begin, end);
		//[div+1,end]
		if (div + 1 <end)//在此区间有元素就进栈
		{
			StackPush(&st, end);
			StackPush(&st, div+1);
		}
		//[begin,div-1]

		if (begin < div - 1)//在此区间有元素就进栈
		{
			StackPush(&st,div-1);
			StackPush(&st, begin);
		}
	}
}


/**
 *  @name        : int Partition(int *a, int begin, int end
 *  @description : 快速排序（枢轴存放）
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */
int Partition(int *a, int begin, int end){
    int pivot = a[begin];
    while (begin < end)
    {
        while (begin < end && a[end] >= pivot)
            end--;
        a[begin] = a[end];
        while (begin < end && a[begin] <= pivot)
            begin++;
        a[end] = a[begin];
    }
    a[begin] = pivot;
    return begin;
}


/**
 *  @name        : void CountSort(int *a, int size)
 *  @description : 计数排序
 *  @param       : 数组指针a，数组长度size
 */
void CountSort(int *a, int size){
	assert(a);
	//通过max和min计算出临时数组所需要开辟的空间大小
	int max = a[0], min = a[0];
	for (int i = 0; i < size; i++){
		if (a[i] > max)
			max = a[i];
		if (a[i] < min)
			min = a[i];
	}
	//使用calloc将数组都初始化为0
	int range = max - min + 1;
	int *b = (int *)calloc(range, sizeof(int));
	//使用临时数组记录原始数组中每个数的个数
	for (int i = 0; i < size; i++){
		//注意：这里在存储上要在原始数组数值上减去min才不会出现越界问题
		b[a[i] - min] += 1;
	}
	int j = 0;
	//根据统计结果，重新对元素进行回收
	for (int i = 0; i < range; i++){
		while (b[i]--){
			//注意：要将i的值加上min才能还原到原始数据
			a[j++] = i + min;
		}
	}
	//释放临时数组
	free(b);
	b = NULL;

}


/**
 *  @name        : radix_sort(int array[], int len, int dec, int order)
 *  @description : 基数计数排序
 *  @param       : 数组指针a，数组长度len，数据位数dec，排序位数order
 */
int get_index(int num, int dec, int order)
{
    int i, j, n;
    int index;
    int div;

    /* 根据位数，循环减去不需要的高位数字 */
    for (i=dec; i>order; i--) {
        n = 1;
        for (j=0; j<dec-1; j++)
            n *= 10;
        div = num/n;
        num -= div * n;
        dec--;
    }

    /* 获得对应位数的整数 */
    n = 1;
    for (i=0; i<order-1; i++)
        n *= 10;

    /* 获取index */
    index = num / n;

    return index;
}

/* 进行基数排序 */
void radix_sort(int array[], int len, int dec, int order)
{
    int i, j;
    int index;     /* 排序索引 */
    int tmp[len];  /* 临时数组，用来保存待排序的中间结果 */
    int num[10];   /* 保存索引值的数组 */
    memset(num, 0, 10*sizeof(int));  /* 数组初始清零 */
    memset(tmp, 0, len*sizeof(int)); /* 数组初始清零 */

    if (dec < order) /* 最高位排序完成后返回 */
        return;

    for (i=0; i<len; i++) {
        index = get_index(array[i], dec, order);  /* 获取索引值 */
        num[index]++;  /* 对应位加一 */
    }

    for (i=1; i<10; i++)
        num[i] += num[i-1]; /* 调整索引数组 */

    for (i=len-1; i>=0; i--) {
        index = get_index(array[i], dec, order);  /* 从数组尾开始依次获得各个数字的索引 */
        j = --num[index];  /* 根据索引计算该数字在按位排序之后在数组中的位置 */
        tmp[j] = array[i]; /* 数字放入临时数组 */
    }

    for (i=0; i<len; i++)
        array[i] = tmp[i];  /* 从临时数组复制到原数组 */


    /* 继续按高一位的数字大小进行排序 */
    radix_sort(array, len, dec, order+1);

    return;
}

/**
 *  @name        : void ColorSort(int *a,int size)
 *  @description : 颜色排序
 *  @param       : 数组指针a（只含0，1，2元素），数组长度size
 */
void ColorSort(int *a,int size){
	int i = 0, count1 = 0, count2 = 0, index = 0;
	for(i = 0; i < size; i++) {
		if(a[i] == 1)
		    count1++;
		else if(a[i] == 2)
		    count2++;
	}
	for(i = 0; i < size - count1 - count2; i++)
	a[index++] = 0;
	for(i = 0; i < count1; i++)
	a[index++] = 1;
	for(i = 0; i < count2; i++)
	a[index++] = 2;
}

/*输出*/
void Printf(int *arr,int len)
{
	for (int i = 0; i < len; ++i)
	{
		printf(" %d ", arr[i]);
	}
	printf("\n");
}

