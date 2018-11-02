#include<stdlib.h>
#include<stdbool.h>

#include"Sort.h"

void sort(int*array, size_t length){
    if(length <= 1)
        return;

    if(*array > *(array + length-1)){
        int tmp = *array;
        *array = *(array + length-1);
        *(array + length-1) = tmp;
    }

    if(length >= 3){
        bool notMultiple = ((length % 3) != 0);
        size_t length_1 = (length / 3) + notMultiple;
        size_t length_2 = (2 * length / 3) + notMultiple;

        sort(array, length_2);
        sort(array + (length_1), length - length_1);
        sort(array, length_2);
    }
}
