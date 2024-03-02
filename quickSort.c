#include "quickSort.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findPivot(int* array, size_t arraySize) {
    int tmpArr[3] = {array[0], array[arraySize / 2 - 1], array[arraySize - 1]};
    if (tmpArr[0] > tmpArr[1]) {
        tmpArr[0] ^= tmpArr[1] ^= tmpArr[0] ^= tmpArr[1];
    }
    if (tmpArr[1] > tmpArr[2]) {
        tmpArr[1] ^= tmpArr[2] ^= tmpArr[1] ^= tmpArr[2];
    }
    if (tmpArr[0] > tmpArr[1]) {
        tmpArr[0] ^= tmpArr[1] ^= tmpArr[0] ^= tmpArr[1];
    }
    return tmpArr[1];
}

void appendToArray(int** array, size_t* arraySize, size_t* arrayFill, int value) {

    if (*arrayFill == *arraySize) {

        *arraySize *= 2;
        *array = realloc(*array, *arraySize * sizeof(int));
    }

    (*array)[*arrayFill] = value;
    (*arrayFill)++;
}

partArr* partitionArray(int* array, int pivot, size_t arraySize) {

    partArr* partitionedArray = malloc(sizeof(partArr));
    partitionedArray->leftArray = memset(malloc(sizeof(int) * arraySize / 2), 0, arraySize / 2);
    partitionedArray->leftArraySize = arraySize / 2;
    size_t leftArrayFill = 0;

    partitionedArray->rightArray = memset(malloc(sizeof(int) * arraySize / 2), 0, arraySize / 2);

    partitionedArray->rightArraySize = arraySize / 2;
    size_t rightArrayFill = 0;

    partitionedArray->pivots = memset(malloc(sizeof(int) * 1), 0, 1);
    partitionedArray->pivotsSize = 1;
    size_t pivotsFill = 0;

    for (int i = 0; i < arraySize; i++) {
        if (array[i] == pivot) {
            appendToArray(&partitionedArray->pivots, &partitionedArray->pivotsSize, &pivotsFill, array[i]);
        } else if (array[i] < pivot) {
            appendToArray(&partitionedArray->leftArray, &partitionedArray->leftArraySize, &leftArrayFill, array[i]);
        } else {
            appendToArray(&partitionedArray->rightArray, &partitionedArray->rightArraySize, &rightArrayFill, array[i]);
        }
    }
    partitionedArray->leftArray = realloc(partitionedArray->leftArray, sizeof(int) * leftArrayFill);
    partitionedArray->leftArraySize = leftArrayFill;

    partitionedArray->rightArray = realloc(partitionedArray->rightArray, sizeof(int) * rightArrayFill);
    partitionedArray->rightArraySize = rightArrayFill;

    partitionedArray->pivots = realloc(partitionedArray->pivots, sizeof(int) * pivotsFill);
    partitionedArray->pivotsSize = pivotsFill;

    return partitionedArray;
}

int* quickSort(int* array, size_t arraySize) {

    if (array == NULL || arraySize == 0) {
        return NULL;
    }
    if (arraySize == 1) {
        return array;
    }
    partArr* partitionedArray = partitionArray(array, findPivot(array, arraySize), arraySize);

    quickSort(partitionedArray->leftArray, partitionedArray->leftArraySize);
    quickSort(partitionedArray->pivots, partitionedArray->pivotsSize);
    quickSort(partitionedArray->rightArray, partitionedArray->rightArraySize);

    memcpy(array, partitionedArray->leftArray, partitionedArray->leftArraySize * sizeof(int));
    memcpy((array + partitionedArray->leftArraySize), partitionedArray->pivots,
           partitionedArray->pivotsSize * sizeof(int));
    memcpy((array + partitionedArray->leftArraySize + partitionedArray->pivotsSize), partitionedArray->rightArray,
           partitionedArray->rightArraySize * sizeof(int));
    freePartitionedArray(partitionedArray);
    return array;
}

void printArray(int* arrayPointer, size_t arraySize) {
    printf("[ ");
    for (int i = 0; i < arraySize; i++) {
        if (i < arraySize - 1) {
            printf("%d, ", arrayPointer[i]);
        } else {
            printf("%d", arrayPointer[i]);
        }
    }
    printf(" ]\n");
}

int freePartitionedArray(partArr* partitionedArray) {
    free(partitionedArray->leftArray);
    free(partitionedArray->rightArray);
    free(partitionedArray->pivots);
    free(partitionedArray);
    return 0;
}
