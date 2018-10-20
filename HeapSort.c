/* ========================================================================= *
 * HeapSort
 * Implementation of the HeapSort algorithm.
 * ========================================================================= */

#include <stdlib.h>
#include "Sort.h"

static void MaxHeapify(int* array, size_t NodeIndex, size_t lenght){
    size_t LeftSon = NodeIndex*2;
    size_t RightSon = (NodeIndex * 2 + 1);
    size_t IndexOfLargest = NodeIndex;
    if((LeftSon < lenght) && (array[LeftSon] > array[NodeIndex])){
        IndexOfLargest = LeftSon;     
    }
    if((RightSon < lenght)&&(array[RightSon] > array[IndexOfLargest])){
        IndexOfLargest = RightSon;
    }
    if(IndexOfLargest != NodeIndex){
        int tmp = array[IndexOfLargest]; // swap aray[IndexOfLargest] and array[NodeIndex].
        array[IndexOfLargest] = array[NodeIndex];
        array[NodeIndex] = tmp;
        MaxHeapify(array, IndexOfLargest, lenght);
        return;
    }
return;
}

static void BuildMaxHeap(int* array, size_t lenght){

    for(long int i = (lenght/2); i >= 0; i-- ){
        MaxHeapify(array, i, lenght);
    }
return;
}

static void HeapSort(int* array, size_t lenght){
    BuildMaxHeap(array, lenght);
    for(long int i = --lenght; i >= 0; i--){
        
        int swap = array[i];// swap aray[i] and array[0].
        array[i] = array[0];
        array[0] = swap;

        MaxHeapify(array,0, i);
    }
return;    
}

void sort(int* array, size_t length){

    if (!array)
        return;

    HeapSort(array, length);
return;
}