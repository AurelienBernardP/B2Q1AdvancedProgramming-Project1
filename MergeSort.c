/* ========================================================================= *
 * mergeSort
 * Implementation of the mergeSort algorithm.
 * ========================================================================= */

#include <stdlib.h>
#include "Sort.h"

/* -------------------------------------------------------------------- *
 * Merges two sorted in ascending order portions of an array in to one sorted portion in ascending order.
 *
 * ARGUMENTS
 * array: pointer to first element of an array
 * tmpArray: pointer to first element of array used to store temparary values for algorithm
 * start: index of the lower boundary where the sorting takes effect in the array
 * middle:index of the boundary value between the two separete sorted portions of the array.
 * end: index of the top boundary where the sorting takes effect in the array
 *
 * RETURN
 * array sorted from array[start] to array[end] in ascending order.
 * --------------------------------------------------------------------*/
static void merge(int* array, int* tmpArray, size_t start, size_t middle, size_t end ){

    size_t i = start, j = middle, k = 0;
    while(i <= middle && j <= end){
        if(array[i] <= array[j] && (i < middle)){
            tmpArray[k] = array[i];
            i++;
        }else{
            tmpArray[k] = array[j];
            j++;
        }
        k++;
    }

    for(; i <= middle ; k++, i++){//cpy what is left from one of the portions into tmpArray
        tmpArray[k] = array[i];
    }
    for(; j <= end ; k++, j++){
        tmpArray[k] = array[j];
    }

    for(i = start, k = 0 ; i <= end; k++, i++){//cpy back into array from tmp array
        array[i] = tmpArray[k];
    }
return;
}

/* -------------------------------------------------------------------- *
 * Sorting algorithm, ascending order
 *
 * ARGUMENTS
 * array: pointer to first element of an array
 * tmpArray: pointer to first element of array used to store temparary values for algorith
 * start: index of the lower boundary where the sorting takes effect in the array
 * end: index of the top boundary where the sorting takes effect in the array
 *
 * RETURN
 * array sorted from array[start] to array[end]
 * --------------------------------------------------------------------*/
static void mergeSort(int* array,int* tmpArray, size_t start, size_t end){
    
    if(start < end){
        size_t middle = (start + end) / 2;
        mergeSort(array, tmpArray, start, middle);
        mergeSort(array, tmpArray, ++middle, end);
        merge(array, tmpArray, start, middle, end);
    }
return;
}

void sort(int* array, size_t length){

    if (!array)
        return;

    int* tmpArray =(int*)malloc((length+1) * sizeof(int));
    if(!tmpArray)
        return;
        
    mergeSort(array, tmpArray, 0, --length);
    free(tmpArray);
return;
}