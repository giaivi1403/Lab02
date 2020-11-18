#include"debug.h"

bool isAscending(int *a, int n)
{
    // for (int i = 0; i < n - 1; i++)
    // {
    //     if (a[i] > a[i + 1])
    //         return false;
    // }
    // return true;
    return is_sorted(a, a + n); // Check array is sorted, improve time checking ascending array of large array.
}

void printInfo(int* a, int n, string sortName, double time, string typeData) {
    cout << "--------------------------" << endl << endl;
    cout << "Sort name : " << sortName << endl;
    cout << "Size : " << n << endl;
    cout << "Type data : " << typeData << endl;
    cout << "Condition : " << (isAscending(a, n) == true ? "Ok" : "Fail") << endl;
    cout << "Time executed : " << time << "s" << endl << endl;
}

double timeSorting(int* a, int n,void (*function)(int*, int)) {
    clock_t start, end;
    start = clock();
    function(a, n);
    end = clock();
    double duration_sec = double(end-start)/CLOCKS_PER_SEC;
    return duration_sec;
}

void runningSort(int* a, int n, void (*function)(int*, int), string sortName, int type) {
    double time = timeSorting(a, n, function);
    string typeData;
    if(type == 0) {
        typeData = "Random";
    }
    else if (type == 1) {
        typeData = "Ordered";
    }
    else if (type == 2) {
        typeData = "Reversed Order";
    }
    else if (type == 3) {
        typeData = "Nearly Ordered";
    }
    printInfo(a, n, sortName, time, typeData);
}

void mainRunningSort(int sizeData, string sortName) {
    int type[] = {0, 1, 2, 3};
    for(int i = 0; i < 4; i++) {
        int* a = new int[sizeData];
        GenerateData(a, sizeData, i);
        if (sortName == "select")
            runningSort(a, sizeData, &SelectionSort, "Selection Sort", i);
        else if(sortName == "insert")
            runningSort(a, sizeData, &InsertionSort, "Insertion Sort", i);
        else if(sortName == "bubble")
            runningSort(a, sizeData, &BubbleSort, "Bubble Sort", i);
        else if(sortName == "quick")
            runningSort(a, sizeData, &QuickSortInfo, "Quick Sort", i);
        else if(sortName == "heap")
            runningSort(a, sizeData, &HeapSort, "Heap Sort", i);
        else if(sortName == "merge")
            runningSort(a, sizeData, &MergeSortInfo, "Merge Sort", i);
        else if(sortName == "radix")
            runningSort(a, sizeData, &RadixSort, "Radix Sort", i);
        delete[] a;
        a = nullptr;
     }
}

void printArray(int* a, int n) {
    for(int i = 0; i < n; i++) {
        cout << a[i] << " " ;
    }
    cout << endl << endl;
}

void debugSort(int sizeData, string sortName) {
    int j = 0;
    int* a = new int[sizeData];
    while(j <= 10) {
        // if(j % 2 == 0)
        GenerateRandomData(a, sizeData);
        // else if (j % 2 != 0) 
        //     GenerateReverseData(a, sizeData);
        cout << "Initial Array" << endl;
        printArray(a, sizeData);
        if (sortName == "select")
            SelectionSort(a, sizeData);
        else if(sortName == "insert")
            InsertionSort(a, sizeData);
        else if(sortName == "bubble")
            BubbleSort(a, sizeData);
        else if(sortName == "quick")
            QuickSortInfo(a, sizeData);
        else if(sortName == "heap")
            HeapSort(a, sizeData);
        else if(sortName == "merge")
            MergeSortInfo(a, sizeData);
        else if(sortName == "radix")
            RadixSort(a, sizeData);
        if(is_sorted(a, a + sizeData)) j++;
        else {
            cout << "Fail" << endl;
            delete[] a;
            a = nullptr;
            return;
        }
        cout << "Sorted" << endl;
        printArray(a, sizeData);
    }
    cout << "Success" << endl;
    delete[] a;
    a = nullptr;
}

void debugSort2(int type) {
    int size[] = { 3000, 10000, 30000, 100000, 300000 };
    for(int i = 0 ; i <= 3; i++) {
        int* a = new int[size[i]];

        GenerateData(a, size[i], type);
        runningSort(a, size[i], &SelectionSort, "Selection Sort", type);
        
        GenerateData(a, size[i], type);
        runningSort(a, size[i], &InsertionSort, "Insertion Sort", type);
                
        GenerateData(a, size[i], type);
        runningSort(a, size[i], &BubbleSort, "Bubble Sort", type);
                
        GenerateData(a, size[i], type);
        runningSort(a, size[i], &QuickSortInfo, "Quick Sort", type);
                
        GenerateData(a, size[i], type);
        runningSort(a, size[i], &HeapSort, "Heap Sort", type);
                
        GenerateData(a, size[i], type);
        runningSort(a, size[i], &MergeSortInfo, "Merge Sort", type);
                
        GenerateData(a, size[i], type);
        runningSort(a, size[i], &RadixSort, "Radix Sort", type);
        
        delete[] a;
        a = nullptr;
    }
}