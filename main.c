#include "quickSort.h"
#include <stddef.h>
#include <stdio.h>
//  expected output:
// {3, 5, 6, 7, 9, 10, 12, 13, 14, 16, 18, 20, 22, 23, 25, 27, 28, 29, 31, 34,
// 36, 37, 38, 40, 41, 42, 45, 47, 50, 53, 54, 56, 59, 61, 63, 64, 67, 68, 71,
// 72, 75, 78, 81, 82, 86, 88, 89, 90, 95, 96}

void printArray(int*, size_t);

int main() {

    int array[] = {20, 34, 12, 45, 7,  89, 3,  56, 72, 18, 63, 29, 41, 50, 6,  81, 14, 38, 95, 27, 68, 5,  23, 37, 10,
                   59, 16, 78, 90, 42, 53, 75, 9,  61, 31, 86, 25, 47, 82, 71, 13, 67, 40, 28, 54, 64, 22, 96, 36, 88};
    size_t arraySize = sizeof(array) / sizeof(array[0]);

    printArray(quickSort(array, arraySize), arraySize);
    return 0;
}
