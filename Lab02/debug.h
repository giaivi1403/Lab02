#ifndef __MAIN__DEBUG__
#define __MAIN__DEBUG__
#include "SortAlgorithm.h"
#include"DataGenerator.h"
#include"SortAlgorithm.h"
#include <algorithm>
#include <time.h>
#include <iostream>
using namespace std;

double timeSorting(int*, int,void (*function)(int*, int));
bool isAscending(int *, int);
void printInfo(int*, int, string, double, string);
void Sorting(int* a, int n, void (*function)(int*, int), string sortName, int type); 
void mainRunningSort(int sizeData, string sortName);
void debugSort(int sizeData, string sortName);
void printArray(int* a, int n);
void debugSort2(int type);
#endif