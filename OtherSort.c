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
      bool notMultiple = ((length%3)!= 0);
		size_t length_2 = (2*length/3) + notMultiple;

		sort(t, length_2);
		sort(t+(length_2/2), length - (length_2/2));
      sort(t, length_2);
	}
}
