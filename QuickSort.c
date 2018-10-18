/* ========================================================================= *
 * QuickSort
 * Implementation of the QuickSort algorithm.
 * ========================================================================= */

#include <stddef.h>
#include "Sort.h"

static size_t Partition(int* array, size_t start, size_t end){
    int pivot = array[end];
    int i = start-1;

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

    return(i+1);
}

static size_t MedianOf3Partitions(int* array, size_t start, size_t end){
    size_t middle = ((start+end)/2);
    size_t median_value_index;
    if((array[start]>=array[middle] && array[start]<= array[end]) || (array[start]<=array[middle] && array[start]>= array[end])){
        // array[start]is the median value
        median_value_index = start;
    }
    if((array[middle]>=array[start] && array[middle]<= array[end]) || (array[middle]<=array[start] && array[middle]>= array[end])){
        // array[middle]is the median value
        median_value_index = middle;
    }
    if((array[end]>=array[start] && array[end]<= array[middle]) || (array[end]<=array[start] && array[end]>= array[middle])){
        // array[end]is the median value
        median_value_index = end;
    }
    int tmp = array[end];
    array[end] = array[median_value_index];
    array[median_value_index] = tmp;

    return Partition(array, start, end);
}


static void QuickSort(int* array, size_t start, size_t end){
    if(start>=end){
        return;
    }
    size_t pivot = MedianOf3Partitions(array, start, end);
    QuickSort(array, start, pivot-1);
    QuickSort(array, pivot+1, end);
 
return;
}

void sort(int* array, size_t length){
    
    if (!array)
        return;

    QuickSort(array, 0, --length);
return;
}