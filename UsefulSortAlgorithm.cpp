// UsefulSortAlgorithm.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。

#include "pch.h"
#include <iostream>
#include<stdio.h>
using namespace std;

// 冒泡排序
void BubbleSort(int* p, int n)
{
	for (int i = 0; i < n-1; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (p[j] > p[j + 1])
			{
				p[j] ^= p[j + 1];
				p[j + 1] ^= p[j];
				p[j] ^= p[j + 1];
			}
		}
	}
}
// 显示函数
void dis(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << " "<< arr[i] << dec;
	}
	putchar(10);
}
// 冒泡排序优化设计
void BubbleSort_OptimizationVersion(int* p, int n)
{
	int flag;
	for (int i = 0; i < n - 1; i++)
	{
		flag = 1;//加标志的原因就是，如果本身是有序的，就不需要交换，免得浪费运行时间
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (p[j] > p[j + 1])
			{
				p[j] ^= p[j + 1];
				p[j + 1] ^= p[j];
				p[j] ^= p[j + 1];
				flag = 0;
			}
		}
		if (flag)
			break;
	}
}
/*插入排序
===========================================================//
插入排序的特点 
(1)稳定、快速、稳定指的是对于一样大的两个数不会交换位置
(2)比较的次数不一定，比较的次数越少，插入点后的数据移动越多
(3)平均时间复杂度O(n2)
(4)适合于少量数据的排序(1000以内的数据)
(5)
===========================================================//
*/
void InsertSortionComplete(int* Array, int NumberOf_ArrayElement)
{
	int i, j, temp;
	for (i = 0; i < NumberOf_ArrayElement; i++)
	{
		temp = Array[i];
		for (j = i; j - 1 >= 0 && temp < Array[j - 1]; j--)
		{
			Array[j] = Array[j - 1];
		}
		Array[j] = temp;
	}
}
/*希尔排序
===========================================================//
希尔排序的特点
(1)希尔排序是基于插入排序的以下两点性质提出的改进方法
(2)优点: 快, 移动数据少; 希尔排序在对几乎已经排好序的数据操作时, 效率高, 即可以达到线性排序的效率
(3)缺点: 不稳定, d的取值是多少, 应取多少个不同的值, 都无法确切知道, 只能凭经验来取
(4)平均时间复杂度O(n1.3)
(5)希尔排序的本质还是插入排序
(6)
===========================================================//
*/
void shellSort(int* arr, int n)
{
	int i, j, temp;
	int gap = n / 2;
	while (gap >= 1)
	{
		for (i = gap; i < n; i++)
		{
			temp = arr[i];
			for (j = i; j - gap >= 0 && temp < arr[j - gap]; j -= gap)
			{
				arr[j] = arr[j - gap];
			}
			arr[j] = temp;
		}
		gap /= 2;
	}
}
/*选择排序
===========================================================//
选择排序的特点
===========================================================//
*/
void selectSort(int* arr, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (arr[i] > arr[j])
			{
				arr[i] ^= arr[j];
				arr[j] ^= arr[i];
				arr[i] ^= arr[j];
			}
		}
	}
}
void selectSort_OptimizationVersion(int* arr, int n)
{
	int idx;
	for (int i = 0; i < n - 1; i++)
	{
		idx = i;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[idx] > arr[j])
			{
				idx = j;
			}
		}
		if (idx != i)
		{
			arr[i] ^= arr[idx];
			arr[idx] ^= arr[i];
			arr[i] ^= arr[idx];
		}
	}
}
/*快速排序
===========================================================//
快速排序
this mean needs to master permanently
===========================================================//
*/
void QuikSort(int* arr, int left, int right)
{
	if (left < right)
	{
		int pivot = arr[left], l = left, h = right;
		while (l < h)
		{
			while (l < h&&arr[h] >= pivot)
				h--;
			arr[l] = arr[h];
			while (l < h&&arr[l] <= pivot)
				l++;
			arr[h] = arr[l];
		}
		arr[h] = pivot;
		QuikSort(arr, left, h - 1);
		QuikSort(arr, h + 1, right);
	}
}
void Qsort(int arr[], int low, int high) {
	if (high <= low) return;
	int i = low;
	int j = high + 1;
	int key = arr[low];
	while (true)
	{
		/*从左向右找比key大的值*/
		while (arr[++i] < key)
		{
			if (i == high) {
				break;
			}
		}
		/*从右向左找比key小的值*/
		while (arr[--j] > key)
		{
			if (j == low) {
				break;
			}
		}
		if (i >= j) break;
		/*交换i,j对应的值*/
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
	/*中枢值与j对应值交换*/
	int temp = arr[low];
	arr[low] = arr[j];
	arr[j] = temp;
	Qsort(arr, low, j - 1);
	Qsort(arr, j + 1, high);
}
// 数组聚合函数(将两个有序的数组，合并为一个有序的数组)
void MergeTwoArrsToOneArr(int* a, int an, int* b, int bn, int* c, int cn)
{
	int i = 0; int j = 0; int k = 0;
	while (i != an && j != bn)
	{
		if (a[i] < b[j])
			c[k++] = a[i++];
		else
			c[k++] = b[j++];
	}
	if (i == an)
		while (j != bn)
			c[k++] = b[j++];
	else
		while (i != an)
			c[k++] = a[i++];
}
// 将一个数组里面的有序子数组合并为一个大的有序的数组，例如将int Source[8] = { 2,6,89,99,1,5,56,59 }到int Aim[8]
void MergeOneArrToAnotherArr(int* SourceArray,int* TempArray,int Start,int Mid,int End)
{
	int i = Start; int j = Mid + 1; int k = Start;
	while (i != Mid + 1 && j != End + 1)
	{
		if (SourceArray[i] < SourceArray[j])
			TempArray[k++] = SourceArray[i++];
		else
			TempArray[k++] = SourceArray[j++];
	}
	if (i == Mid + 1)
		while (j != End + 1)
			TempArray[k++] = SourceArray[j++];
	else
		while (i != Mid + 1)
			TempArray[k++] = SourceArray[i++];
	while (Start <= End)
	{
		SourceArray[Start] = TempArray[Start];
		Start++;
	}
}
/*归并排序
===========================================================//
归并排序
this mean needs to master permanently
===========================================================//
*/
void MergeSort(int* arr, int* tmp, int start, int end)
{
	if (start < end)
	{
		int mid = (start + end) / 2;
		MergeSort(arr, tmp, start, mid);
		MergeSort(arr, tmp, mid + 1, end);
		MergeOneArrToAnotherArr(arr, tmp, start, mid, end);
	}
}
#if 0
int main()
{
	int arr[] = { 1,3,5,7,9,2,4,6,8 , 10 };
	//BubbleSort(arr, sizeof(arr) / sizeof(*arr));
	//dis(arr, sizeof(arr) / sizeof(*arr));
	//InsertSortionComplete(arr, sizeof(arr) / sizeof(*arr));
	selectSort_OptimizationVersion(arr, 10);
	dis(arr, sizeof(arr) / sizeof(*arr));
	cout << endl;
	return 0;
}
#endif

#if 0
int main()
{
	int a[5] = { 2,4,45,78,99 };
	int b[3] = { 1,90,101 };
	int c[8];
	MergeTwoArrsToOneArr(a, 5, b, 3, c, 8);
	for (int n = 0; n < 8; n++)
	{
		printf("%d ", c[n]);
	}
	return 0;
}
#endif

#if 1
int main()
{
	int Source[8] = { 2,6,89,99,1,5,56,59 };
	int Aim[8];
	MergeOneArrToAnotherArr(Source, Aim, 0, 3, 7);
	for (int n = 0; n < 8; n++)
	{
		printf("%d ", Aim[n]);
	}
	return 0;
}
#endif
