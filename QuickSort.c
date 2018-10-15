/* ========================================================================= *
 * QuickSort
 * Implementation of the QuickSort algorithm.
 * ========================================================================= */

#include <stddef.h>
#include "Sort.h"


static void Partition(int* array, size_t start, size_t end){

}

static void QuickSort(int* array, size_t start, size_t end){

    size_t pivot = Partiton(array, start, end);
    if(){//aims to do the smallest part of the tree to improve memory use(to be completed)
        QuickSort(array, start, pivot-1);
    }else{
        QuickSort(array, pivot+1, end);
    }
    
return;
}

void sort(int* array, size_t length){
    
    if (!array)
        return;

    size_t pivot = random_pivot();
    QuickSort(array, 0, lenght);
}