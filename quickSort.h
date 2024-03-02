#include <stddef.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int* leftArray;
    int* rightArray;
    int* pivots;
    size_t leftArraySize;
    size_t rightArraySize;
    size_t pivotsSize;
} partArr;

int findPivot(int*, size_t);

partArr* partitionArray(int*, int, size_t);

void appendToArray(int**, size_t*, size_t*, int);

int* quickSort(int*, size_t);

void printArray(int*, size_t);

int freePartitionedArray(partArr*);
