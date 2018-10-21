/* ========================================================================= *
 * quickSort
 * Implementation of the quickSort algorithm.
 * ========================================================================= */

#include <stddef.h>
#include "Sort.h"

static size_t partition(int* array, size_t start, size_t end){
    
    int pivot = array[end];
    int i = (start-1);

    for(size_t j = start; j < end; j++){
        if(array[j] <= pivot){
            i++;
            int tmp = array[i];
            array[i] = array[j];
            array[j] = tmp;
        }
    }
    int tmp = array[end];
    array[end] = array[i+1];
    array[i+1] = tmp;
    ++i;
return i;
} 

/* -------------------------------------------------------------------- *
 * Swaps the pivot value (array[end]) with the median value from: array[start], array[end] and array[(start+end)/2]
 * and calls the fonction partition at the end.
 *
 * ARGUMENTS
 * array: pointer to first element of an array
 * start: index of the lower boundary where the sorting takes effect in the array
 * end: index of the top boundary where the sorting takes effect in the array
 *
 * RETURN
 * Partiton function returned value.
 * --------------------------------------------------------------------*/
static size_t MedianOf3Partitions(int* array, long int start, long int end){
    size_t middle = ((start + end) / 2);
    size_t medianValueIndex;
    if((array[start] >= array[middle] && array[start] <= array[end]) || (array[start] <= array[middle] && array[start] >= array[end])){
        // array[start]is the median value
        medianValueIndex = start;
    }
    if((array[middle] >= array[start] && array[middle] <= array[end]) || (array[middle]<=array[start] && array[middle] >= array[end])){
        // array[middle]is the median value
        medianValueIndex = middle;
    }
    if((array[end] >= array[start] && array[end] <= array[middle]) || (array[end] <= array[start] && array[end] >= array[middle])){
        // array[end]is the median value
        medianValueIndex = end;
    }
    int tmp = array[end];
    array[end] = array[medianValueIndex];
    array[medianValueIndex] = tmp;

return partition(array, start, end);
}

/* -------------------------------------------------------------------- *
 * Sorting algorithm, ascending order
 *
 * ARGUMENTS
 * array: pointer to first element of an array
 * start: index of the lower boundary where the sorting takes effect in the array
 * end: index of the top boundary where the sorting takes effect in the array
 *
 * RETURN
 * array sorted from array[start] to array[end]
 * --------------------------------------------------------------------*/
static void quickSort(int* array, long int start, long int end){
    
    if(start < end){
    size_t pivot = MedianOf3Partitions(array, start, end);
    quickSort(array, start, pivot - 1);
    quickSort(array, pivot + 1, end);
    }
    
return;
}

void sort(int* array, size_t length){
    
    if (!array)
        return;

    quickSort(array, 0, (--length));
return;
}