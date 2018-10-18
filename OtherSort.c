#include<stdlib.h>
#include<stdbool.h>

#include"Sort.h"

void sort(int*t, size_t length){
	if(length <= 1)
		return;

	if(*t > *(t+length-1)){
		int tmp = *t;
		*t = *(t+length-1);
		*(t+length-1) = tmp;
	}

	if(length >= 3){
      bool notMultiple = ((length%3)!=0);
		size_t length_1 = (length/3) + notMultiple;
		size_t length_2 = (2*length/3) + notMultiple - length_1;

		sort(t, length_1 + length_2);
		sort(t+(length_1), length - length_1);
      sort(t, length_1 + length_2);
	}
}
