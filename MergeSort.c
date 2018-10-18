/* ========================================================================= *
 * MergeSort
 * Implementation of the MergeSort algorithm.
 * ========================================================================= */

#include <stdlib.h>
#include "Sort.h"

static void Merge(int* array, int* tmp_array, size_t start, size_t middle, size_t end ){

    size_t i = start, j = middle, k = 0;
    while(i <= middle && j<= end){// and k<end-start ??
        if(array[i] <= array[j] && (i < middle)){
            tmp_array[k] = array[i];
            i++;
        }else{
            tmp_array[k] = array[j];
            j++;
        }
        k++;
    }

    for(; i<= middle ; k++, i++){
        tmp_array[k] = array[i];
    }
    for(; j<= end ; k++, j++){
        tmp_array[k] = array[j];
    }


    for(i = start, k = 0 ; i <= end; k++, i++){//cpy back into array from tmp array
        array[i] = tmp_array[k];
    }

    return;
}

static void MergeSort(int* array,int* tmp_array, size_t start, size_t end){
    if(start < end){
        size_t middle = (start + end) / 2;
        MergeSort(array, tmp_array, start, middle);
        MergeSort(array, tmp_array, ++middle, end);
        Merge(array, tmp_array, start, middle, end);
    }
return;
}

void sort(int* array, size_t length){

    if (!array)
        return;

    int* tmp_array = malloc(length*sizeof(int));
    if(!tmp_array)
        return;
        
    MergeSort(array, tmp_array, 0 ,--length);
    free(tmp_array);
    return;
}