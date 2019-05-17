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
 *  @description : ��������
 *  @param       : ����ָ�� a, ���鳤�� n
 */
void insertSort(int *a,int n){
	for (int i = 1; i < n; ++i)
	{
		//Ų������
		int tmp = a[i];//����������
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
 *  @description : �鲢���򣨺ϲ����飩
 *  @param       : ����ָ��a���������begin�������е�mid�������յ�end����������ָ��temp
 */
void MergeArray(int *a, int begin1, int end1, int begin2, int end2, int *tmp){
	int index = begin1;
	int i = begin1, j = begin2;
	//ע��:�����ֵ������㹻Сʱ,begin1==end1,begin2==end2
	while (i <= end1&&j <= end2){
		if (a[i]<=a[j])
			tmp[index++] = a[i++];
		else
			tmp[index++] = a[j++];
	}
	//�����Ԫ����䵽tmp��
	while (i <= end1)
		tmp[index++] = a[i++];
	//���ұ�Ԫ������tmp��
	while (j <= end2)
		tmp[index++] = a[j++];
	//��tmp�е����ݿ�����ԭ�����Ӧ����������
	//ע��:end2-begin1+1
	memcpy(a + begin1, tmp + begin1, sizeof(int)*(end2 - begin1 + 1));
}


/**
 *  @name        : void MergeSort(int *a, int left, int right, int *tmp)
 *  @description : �鲢����
 *  @param       : ����ָ��a���������left�������յ�right����������ָ��tmp
 */
void MergeSort(int *a, int left, int right, int *tmp)
{
	if (left >= right)
		return;
	assert(a);
	//mid���������
	int mid = left + ((right - left) >> 1);
	//��߹鲢����,ʹ��������������
	MergeSort(a, left, mid, tmp);
	//�ұ߹鲢����,ʹ��������������
	MergeSort(a, mid + 1, right, tmp);
	//����������������ϲ�
	MergeArray(a, left, mid, mid + 1, right, tmp);
}
/**
 *  @name        : QuickSort_Recursion(int *a, int left, int right)
 *  @description : �������򣨵ݹ�棩
 *  @param       : ����ָ��a���������left�������յ�right
 */
void QuickSort_Recursion(int *a, int left, int right){
		//��������ָ��ָ��������±�
	int i = left;
	int j = right;

	//�ݹ����
	if(i>j)
		return;

	//��¼���ֵ
	int pivot = a[i];

	//һ��ѭ�����Եõ�����˵���඼�ȱ��С����˵��Ҳ඼�ȱ�˴�
	while(i<j)
	{
		//��right��ʼ�ұȱ��С��Ϊֹ
		while(i<j && a[j]>=pivot)
			j--;

		//����С������ֵ��left��
		a[i] = a[j];

		//��left��ʼ�ұȱ�˴��Ϊֹ
		while(i<j && a[i]<=pivot)
			i++;

		//���ϴ������ֵ��right��
		a[j] = a[i];
	}
	//�����ֵ����������
	a[i] = pivot;
	//һ��ѭ�����

	//���������Ҳ�ĵݹ�
	QuickSort_Recursion(a,left,i-1);
	QuickSort_Recursion(a,i+1,right);

}
//��������
void swap(int x,int y)
{
int temp;
temp=x;
x=y;
y=temp;
}

/**
 *  @name        : QuickSortNonR(int* a, int left, int right)
 *  @description : �������򣨷ǵݹ�棩
 *  @param       : ����ָ��a���������left�������յ�right
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
		if (div + 1 <end)//�ڴ�������Ԫ�ؾͽ�ջ
		{
			StackPush(&st, end);
			StackPush(&st, div+1);
		}
		//[begin,div-1]

		if (begin < div - 1)//�ڴ�������Ԫ�ؾͽ�ջ
		{
			StackPush(&st,div-1);
			StackPush(&st, begin);
		}
	}
}


/**
 *  @name        : int Partition(int *a, int begin, int end
 *  @description : �������������ţ�
 *  @param       : ����ָ��a���������begin�������յ�end
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
 *  @description : ��������
 *  @param       : ����ָ��a�����鳤��size
 */
void CountSort(int *a, int size){
	assert(a);
	//ͨ��max��min�������ʱ��������Ҫ���ٵĿռ��С
	int max = a[0], min = a[0];
	for (int i = 0; i < size; i++){
		if (a[i] > max)
			max = a[i];
		if (a[i] < min)
			min = a[i];
	}
	//ʹ��calloc�����鶼��ʼ��Ϊ0
	int range = max - min + 1;
	int *b = (int *)calloc(range, sizeof(int));
	//ʹ����ʱ�����¼ԭʼ������ÿ�����ĸ���
	for (int i = 0; i < size; i++){
		//ע�⣺�����ڴ洢��Ҫ��ԭʼ������ֵ�ϼ�ȥmin�Ų������Խ������
		b[a[i] - min] += 1;
	}
	int j = 0;
	//����ͳ�ƽ�������¶�Ԫ�ؽ��л���
	for (int i = 0; i < range; i++){
		while (b[i]--){
			//ע�⣺Ҫ��i��ֵ����min���ܻ�ԭ��ԭʼ����
			a[j++] = i + min;
		}
	}
	//�ͷ���ʱ����
	free(b);
	b = NULL;

}


/**
 *  @name        : radix_sort(int array[], int len, int dec, int order)
 *  @description : ������������
 *  @param       : ����ָ��a�����鳤��len������λ��dec������λ��order
 */
int get_index(int num, int dec, int order)
{
    int i, j, n;
    int index;
    int div;

    /* ����λ����ѭ����ȥ����Ҫ�ĸ�λ���� */
    for (i=dec; i>order; i--) {
        n = 1;
        for (j=0; j<dec-1; j++)
            n *= 10;
        div = num/n;
        num -= div * n;
        dec--;
    }

    /* ��ö�Ӧλ�������� */
    n = 1;
    for (i=0; i<order-1; i++)
        n *= 10;

    /* ��ȡindex */
    index = num / n;

    return index;
}

/* ���л������� */
void radix_sort(int array[], int len, int dec, int order)
{
    int i, j;
    int index;     /* �������� */
    int tmp[len];  /* ��ʱ���飬���������������м��� */
    int num[10];   /* ��������ֵ������ */
    memset(num, 0, 10*sizeof(int));  /* �����ʼ���� */
    memset(tmp, 0, len*sizeof(int)); /* �����ʼ���� */

    if (dec < order) /* ���λ������ɺ󷵻� */
        return;

    for (i=0; i<len; i++) {
        index = get_index(array[i], dec, order);  /* ��ȡ����ֵ */
        num[index]++;  /* ��Ӧλ��һ */
    }

    for (i=1; i<10; i++)
        num[i] += num[i-1]; /* ������������ */

    for (i=len-1; i>=0; i--) {
        index = get_index(array[i], dec, order);  /* ������β��ʼ���λ�ø������ֵ����� */
        j = --num[index];  /* ������������������ڰ�λ����֮���������е�λ�� */
        tmp[j] = array[i]; /* ���ַ�����ʱ���� */
    }

    for (i=0; i<len; i++)
        array[i] = tmp[i];  /* ����ʱ���鸴�Ƶ�ԭ���� */


    /* ��������һλ�����ִ�С�������� */
    radix_sort(array, len, dec, order+1);

    return;
}

/**
 *  @name        : void ColorSort(int *a,int size)
 *  @description : ��ɫ����
 *  @param       : ����ָ��a��ֻ��0��1��2Ԫ�أ������鳤��size
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

/*���*/
void Printf(int *arr,int len)
{
	for (int i = 0; i < len; ++i)
	{
		printf(" %d ", arr[i]);
	}
	printf("\n");
}

