#ifndef __GENERATE_DATA__
#define __GENERATE_DATA__
#include <iostream>
#include <fstream>
#include <cmath>
#include <ctime>
#include <stdlib.h>     
#include <time.h>
#include <stdio.h>    
#include <random>


using namespace std;
void GenerateRandomData(int a[], int n);
void GenerateSortedData(int a[], int n);
void GenerateReverseData(int a[], int n);
void GenerateNearlySortedData(int a[], int n);
void GenerateData(int a[], int n, int dataType);
#endif