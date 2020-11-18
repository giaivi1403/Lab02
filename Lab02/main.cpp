#include"debug.h"

using namespace std;

int main(int argc, char *argv[]) {
    // string sortName = argv[1];
    // int sizeData = stoi(argv[2]);
    // std::transform(sortName.begin(), sortName.end(), sortName.begin(), ::tolower);
    // mainRunningSort(sizeData, sortName);
    // debugSort(sizeData, sortName);
    debugSort2(stoi(argv[1]));
}