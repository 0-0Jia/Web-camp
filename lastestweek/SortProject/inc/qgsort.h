
#define MAXSIZE 100
#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED

typedef int STDatatype;
typedef struct Stack
{
	STDatatype* _a;
	int _top;//ջ��
	int _capacity;//����
}Stack;

/**
 *  @name        : void insertSort(int *a,int n);
 *  @description : ��������
 *  @param       : ����ָ�� a, ���鳤�� n
 */
void insertSort(int *a,int n);


/**
 *  @name        : void MergeArray(int *a,int begin,int mid,int end,int *temp);
 *  @description : �鲢���򣨺ϲ����飩
 *  @param       : ����ָ��a���������begin�������е�mid�������յ�end����������ָ��temp
 */
void MergeArray(int *a, int begin1, int end1, int begin2, int end2, int *tmp);


/**
 *  @name        : void MergeSort(int *a, int left, int right, int *tmp)
 *  @description : �鲢����
 *  @param       : ����ָ��a���������left�������յ�right����������ָ��tmp
 */
void MergeSort(int *a, int left, int right, int *tmp);


/**
 *  @name        : QuickSort_Recursion(int *a, int left, int right)
 *  @description : �������򣨵ݹ�棩
 *  @param       : ����ָ��a���������left�������յ�right
 */
void QuickSort_Recursion(int *a, int left, int right);


/**
 *  @name        : QuickSortNonR(int* a, int left, int right)
 *  @description : �������򣨷ǵݹ�棩
 *  @param       : ����ָ��a���������left�������յ�right
 */
void QuickSortNonR(int* a, int left, int right);


/**
 *  @name        : int Partition(int *a, int begin, int end
 *  @description : �������������ţ�
 *  @param       : ����ָ��a���������begin�������յ�end
 */
int Partition(int *a, int begin, int end);


/**
 *  @name        : void CountSort(int *a, int size)
 *  @description : ��������
 *  @param       : ����ָ��a�����鳤��size
 */
void CountSort(int *a, int size);

/**
 *  @name        : radix_sort(int array[], int len, int dec, int order)
 *  @description : ������������
 *  @param       : ����ָ��a�����鳤��len������λ��dec������λ��order
 */
void radix_sort(int array[], int len, int dec, int order);


/**
 *  @name        : void ColorSort(int *a,int size)
 *  @description : ��ɫ����
 *  @param       : ����ָ��a��ֻ��0��1��2Ԫ�أ������鳤��size
 */
void ColorSort(int *a,int size);

/*���*/
void Printf(int *arr,int len);
/*����*/
void swap(int x,int y);

#endif // QUEUE_H_INCLUDED
