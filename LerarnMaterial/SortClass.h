#ifndef SORTCLASS_H
#define SORTCLASS_H
#include "Common.h"
namespace SortSequence{
	class SortClass
	{
	public:
		SortClass();
		~SortClass();
		/******************************************************************************
		�������ƣ� MergeSort
		����˵���� �鲢����
		��    ���� T a[]
		��    ���� int n
		�� �� ֵ�� void
		��    �ߣ� Ru Long
		��    �ڣ� 2019/11/01
		******************************************************************************/
		template<typename T>
		void MergeSort(T a[], int n);
		/******************************************************************************
		�������ƣ� QuickSort
		����˵���� ��������
		��    ���� T a[]
		��    ���� int n
		�� �� ֵ�� void
		��    �ߣ� Ru Long
		��    �ڣ� 2019/11/01
		******************************************************************************/
		template<typename T>
		void QuickSort(T a[], int n);
	private:
		template<typename T>
		void MergeSortAdd(T a[], int start, int end, T result[]);
		template<typename T>
		void Merge(T a[], int start, int end, T result[]);
		template<typename T>
		void QuickSort(T a[], int leftEnd, int rightEnd);
	};
	//ģ���������ʵ��Ҫ����ͬһ���ļ�������
	template<typename T>
	void SortClass::MergeSort(T a[], int n)
	{
		if (n <= 1)
		{
			return;
		}
		T * result = new T[n];
		MergeSortAdd(a, 0, n - 1, result);
		delete[] result;
		result = nullptr;
	}

	template<typename T>
	void SortClass::QuickSort(T a[], int n)
	{
		if (n <= 1)
		{
			return;
		}
		int maxPos = 0;
		for (int i = 1; i < n; i++)
		{
			if (a[i]>a[maxPos])
			{
				maxPos = i;
			}
		}
		swap(a[n - 1], a[maxPos]);
		QuickSort(a, 0, n - 2);
	}

	template<typename T>
	void SortClass::QuickSort(T a[], int leftEnd, int rightEnd)
	{
		if (leftEnd >= rightEnd)
		{
			return;
		}
		int leftCur = leftEnd;        //���������ƶ�������
		int rightCur = rightEnd + 1;  //���������ƶ�������
		T priVot = a[leftEnd];
		//��λ����಻С��֧���Ԫ�غ�λ���Ҳ಻����֧���Ԫ�ؽ���
		while (true)
		{
			do
			{
				++leftCur;
			} while (a[leftCur]<priVot);
			do
			{
				--rightCur;
			} while (a[rightCur]>priVot);
			if (leftCur >= rightCur)
			{
				//û���ҵ�������Ԫ��
				break;
			}
			swap(a[leftCur], a[rightCur]);
		}
		//����֧��
		swap(a[leftEnd], a[rightCur]);
// 		a[leftEnd] = a[rightCur];
// 		a[rightCur] = priVot;
		QuickSort(a, leftEnd, rightCur - 1);
		QuickSort(a, rightCur + 1, rightEnd);
	}

	template<typename T>
	void SortClass::MergeSortAdd(T a[], int start, int end, T result[])
	{
		if (end - start == 1)
		{
			//����ֻ��2��Ԫ��ֱ������
			if (a[start] > a[end])
			{
				swap(a[start], a[end]);
			}
			return;
		}
		else if (end == start)
		{
			//ֻ��һ��Ԫ��ֱ�Ӳ�������
			return;
		}
		else
		{
			MergeSortAdd(a, start, start + (end - start + 1) / 2, result);
			MergeSortAdd(a, start + (end - start + 1) / 2 + 1, end, result);
			Merge(a, start, end, result);
			for (int i = start; i <= end; ++i)
			{
				a[i] = result[i];
			}
		}
	}

	template<typename T>
	void SortClass::Merge(T a[], int start, int end, T result[])
	{
		int left_num = (end - start + 1) / 2 + 1;
		int left_index = start;
		int right_index = start + left_num;
		int result_index = start;
		while (left_index < start + left_num&&right_index < end + 1)
		{
			if (a[left_index] < a[right_index])
			{
				result[result_index++] = a[left_index++];
			}
			else
			{
				result[result_index++] = a[right_index++];
			}
		}
		while (left_index < start + left_num)
			result[result_index++] = a[left_index++];
		while (right_index < end + 1)
			result[result_index++] = a[right_index++];
	}
}
#endif 

