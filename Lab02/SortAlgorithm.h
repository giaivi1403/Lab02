#ifndef __SORT__ALGORITHM__
#define __SORT__ALGORITHM__
#include <iostream>
#include <string>

using namespace std;

void SelectionSort(int *a, int n);
void InsertionSort(int *a, int n);
void BubbleSort(int *a, int n);
void HeapSort(int *a, int n);
void QuickSortInfo(int* a, int n);
void QuickSortv2(int *a, int first, int last);
void RadixSort(int *a, int n);
void MergeSortInfo(int* a, int n);
#endif