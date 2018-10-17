#include<stdlib.h>
#include<stdbool.h>

int* sort(int*t, size_t length){
	if(length <= 1)
		return t;

	if(*t > *(t+length-1)){
		int tmp = *t;
		*t = *(t+length-1);
		*(t+length-1) = tmp;
	}

	if(length >= 3){
      bool notMultiple = ((length%3)!=0);
		size_t length_1 = (length/3) + notMultiple;
		size_t length_2 = (2*length/3) + notMultiple - length_1;

	   int* t_2 = t+(length_1);

		t = sort(t, length_1 + length_2);
		t_2 = sort(t_2, length - length_1);
      t = sort(t, length_1 + length_2);
	}

	return t;
}
