#include "SortAlgorithm.h"

void SelectionSort(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }
        swap(a[i], a[min]);
    }
}

void InsertionSort(int *a, int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}

void BubbleSort(int *a, int n)
{
    bool unSorted = true;
    int i = 0;
    while(unSorted) { // Best case O(n), check if it is already sorted
        unSorted = false;
        i++;
        for(int j = 0; j < n - i; j++) {
            if(a[j] > a[j+1]) {
                swap(a[j], a[j+1]);
                unSorted = true;
            }
        }
    }
}

void heapRebuild(int start, int arr[], int n){
    int leftChild = 2 * start + 1; // A left child must exist
    if (leftChild >= n) return;
    int largerChild = leftChild; // Make assumption about larger child
    int rightChild = 2 * start + 2; // A right child might not exist
    if (rightChild < n){ // Whether a right child exists
    // A right child exists; check whether it is larger
    if (arr[rightChild] > arr[largerChild])
     largerChild = rightChild; // Assumption was wrong

    }
    // If arr[start] is smaller than the larger child, swap values
    if (arr[start] < arr[largerChild]){
        swap(arr[largerChild], arr[start]);
        heapRebuild(largerChild, arr, n); // Recursion at that child
    }
}
void HeapSort(int *a, int n)
{
    for (int index = (n - 1) / 2; index >= 0; index--)
        heapRebuild(index, a, n);
    swap(a[0], a[n - 1]); // swap the largest element to the end
    int heapSize = n - 1; // Heap region size decreases by 1
    while (heapSize > 1) {
        heapRebuild(0, a, heapSize);
        heapSize--;
        swap(a[0], a[heapSize]);
    }
}

int sortFirstMiddleLast(int* a, int first, int last) {
    int mid = first + (last - first) / 2;
    // cout << "a[mid] : " <<  a[mid] << endl;
    if(a[first] > a[mid]) {
        swap(a[first], a[mid]);
    }
    if(a[mid] > a[last]) {
        swap(a[mid], a[last]);
    }
    if(a[first] > a[mid]) {
        swap(a[first], a[mid]);
    }
    return mid;
}

void printarray(int* a, int n) {
    for(int i = 0; i <= n; i++) {
        cout << a[i] << " " ;
    }
    cout << endl << endl;
}

int partition(int* a, int  first, int last) {
    int pivotIndex = sortFirstMiddleLast(a, first, last);
    swap(a[pivotIndex], a[last - 1]);
    pivotIndex = last - 1;
    int pivot = a[pivotIndex];

    int left = first + 1;
    int right = last - 2;
    do {
        while(a[left] < pivot) left++;
        while(a[right] > pivot) right--;
        if(left <= right) {
            swap(a[left], a[right]);
            left++;
            right--;
        }
    } while(left <= right);

    swap(a[left], a[pivotIndex]);
    pivotIndex = left;
    return pivotIndex;
}

void QuickSortInfo(int* a, int n) {
    QuickSortv2(a, 0, n - 1);
}

void QuickSortv2(int *a, int first, int last) 
{
    if(last - first + 1 < 3) {
        // printarray(a, last - first + 1);
        InsertionSort(a, last);
    }
    else {
        int pivot = partition(a, first, last);
        QuickSortv2(a, first, pivot - 1);
        QuickSortv2(a, pivot + 1, last);
    }
}

void RadixSort(int *a, int n)
{
    int max_val = a[0]; // get maximum value in the array
    for (int i = 1; i < n; ++i)
        if (a[i] > max_val) max_val = a[i];
    int digits = 0, div; // find the maximum number of digits
    do{
        digits++;
        div = max_val / pow(10, digits);
    } while (div > 0);
    int **tempArr = new int*[10]; // declare variables for temp store
    for (int i = 0; i < 10; ++i)
        tempArr[i] = new int[n];
    int tempCount[10];
    for (int i = 0; i < digits ; ++i) {
        int exp = pow(10, i);
        for (int j = 0; j < 10; ++j) // reset the counting
            tempCount[j] = 0;
        for (int j = 0; j < n; ++j) { // form groups
            int idx = (a[j] / exp) % 10;
            tempArr[idx][tempCount[idx]++] = a[j];
        }
        int idx = 0; // combine groups
        for (int j = 0; j < 10; ++j)
            for (int k = 0; k < tempCount[j]; ++k)
                a[idx++] = tempArr[j][k];
    }
}

void merge(int* a, int first, int mid, int last, int sizeData) {
    int first1 = first;
    int last1 = mid;
    int first2 = mid + 1;
    int last2 = last;
    int tempArr[sizeData];
    int index = first1;
    while ((first1 <= last1) && (first2 <= last2))
    {
        if(a[first1] <= a[first2])
            tempArr[index++] = a[first1++];
        else 
            tempArr[index++] = a[first2++];
    }
    while(first1 <= last1) 
        tempArr[index++] = a[first1++];
    while (first2 <= last2)
        tempArr[index++] = a[first2++];
    for(index = first; index <= last; index++)
        a[index] = tempArr[index];
}

void MergeSort(int* a, int first, int last, int sizeData) {
    if(first < last) {
        int mid = (last + first) / 2;
        MergeSort(a, first, mid, sizeData);
        MergeSort(a, mid + 1, last, sizeData);
        merge(a, first, mid, last, sizeData);
    }
}

void MergeSortInfo(int* a, int n) {
    MergeSort(a, 0, n-1, n);
}