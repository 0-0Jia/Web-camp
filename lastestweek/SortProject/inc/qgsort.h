
#define MAXSIZE 100
#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED

typedef int STDatatype;
typedef struct Stack
{
	STDatatype* _a;
	int _top;//栈顶
	int _capacity;//容量
}Stack;

/**
 *  @name        : void insertSort(int *a,int n);
 *  @description : 插入排序
 *  @param       : 数组指针 a, 数组长度 n
 */
void insertSort(int *a,int n);


/**
 *  @name        : void MergeArray(int *a,int begin,int mid,int end,int *temp);
 *  @description : 归并排序（合并数组）
 *  @param       : 数组指针a，数组起点begin，数组中点mid，数组终点end，承载数组指针temp
 */
void MergeArray(int *a, int begin1, int end1, int begin2, int end2, int *tmp);


/**
 *  @name        : void MergeSort(int *a, int left, int right, int *tmp)
 *  @description : 归并排序
 *  @param       : 数组指针a，数组起点left，数组终点right，承载数组指针tmp
 */
void MergeSort(int *a, int left, int right, int *tmp);


/**
 *  @name        : QuickSort_Recursion(int *a, int left, int right)
 *  @description : 快速排序（递归版）
 *  @param       : 数组指针a，数组起点left，数组终点right
 */
void QuickSort_Recursion(int *a, int left, int right);


/**
 *  @name        : QuickSortNonR(int* a, int left, int right)
 *  @description : 快速排序（非递归版）
 *  @param       : 数组指针a，数组起点left，数组终点right
 */
void QuickSortNonR(int* a, int left, int right);


/**
 *  @name        : int Partition(int *a, int begin, int end
 *  @description : 快速排序（枢轴存放）
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */
int Partition(int *a, int begin, int end);


/**
 *  @name        : void CountSort(int *a, int size)
 *  @description : 计数排序
 *  @param       : 数组指针a，数组长度size
 */
void CountSort(int *a, int size);

/**
 *  @name        : radix_sort(int array[], int len, int dec, int order)
 *  @description : 基数计数排序
 *  @param       : 数组指针a，数组长度len，数据位数dec，排序位数order
 */
void radix_sort(int array[], int len, int dec, int order);


/**
 *  @name        : void ColorSort(int *a,int size)
 *  @description : 颜色排序
 *  @param       : 数组指针a（只含0，1，2元素），数组长度size
 */
void ColorSort(int *a,int size);

/*输出*/
void Printf(int *arr,int len);
/*交换*/
void swap(int x,int y);

#endif // QUEUE_H_INCLUDED
