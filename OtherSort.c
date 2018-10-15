#include<stdio.h>
#include <stdlib.h>

/*unsigned int* split(unsigned int* t, unsigned int min, unsigned int max){
	assert(FALSE);
	unsigned int* sst = malloc(sizeof(unsigned int) * (max - min + 1));

	if(min == max)
		return sst[0] = t[min - 1];

	for(i = min-1; i == max-1; i++)
		sst[i] = t[i];
	return sst;
}*/

unsigned int* tri(unsigned int*t, unsigned int* start, unsigned int* end,unsigned int taille){
	if(taille <= 1)
		return t;
	if(*start > *end){
		unsigned int tmp = *start;
		*start = *end;
		*end = tmp;
		printf("switched %d %d\n", *end, *start);
	}

	if(taille >= 3){
		/*unsigned int* t_1 = split(t, 1, (taille/3) + !(taille%3));
		unsigned int* t_2 = split(t, (taille/3) + !(taille%3) + 1, (2*taille/3) + !(taille%3));
		unsigned int* t_3 = split(t, (2*taille/3) + !(taille%3) + 1, taille);
		*/

		unsigned int taille_1 = (taille/3) + ((taille%3)>0);
		unsigned int taille_2 = (2*taille/3) + ((taille%3)>0) - taille_1;
		unsigned int taille_3 = taille - (taille_2 + taille_1);
		printf("taille = %d %d %d\n", taille_1, taille_2, taille_3);

		unsigned int* t_1 = t;
		unsigned int* t_2 = t+(taille_1);
		unsigned int* t_3 = t+(taille_1 + taille_2);
		printf("sst = ");
		for(int i = 0; i < taille; i++)
			printf("%d,", t[i]);
		printf("\n");
		printf("début sst = %d %d %d\n\n", *t_1, *t_2, *t_3);


		t = tri(t, t_1, t_2+taille_2-1, taille_1 + taille_2);
		printf("1 t = ");
		for(int i = 0; i < taille; i++)
			printf("%d,", t[i]);
		printf("\n");
		printf("début sst = %d %d %d\n", *t_1, *t_2, *t_3);


		//Probleme ici dans la deuxieme partie du tri il y a un déphasage
		//lors de l'execution on commence par le debut du vrai tableau
		//et non celui du tableau qui est pointé par t_2
		//peut etre envoyer en premier argument t_2 et enlever la taille_2 du
		//du dernier argument. 
		t = tri(t, t_2, t_3, taille - taille_1);
		printf("2 t = ");
		for(int i = 0; i < taille; i++)
			printf("%d,", t[i]);
		printf("\n");
		printf("début sst = %d %d %d\n\n", *t_1, *t_2, *t_3);


		t = tri(t, t_1, t_2+taille_2-1, taille_1 + taille_2);
		printf("3 t = ");
		for(int i = 0; i < taille; i++)
			printf("%d,", t[i]);
		printf("\n");
		printf("début sst = %d %d %d\n\n", *t_1, *t_2, *t_3);

	}

	return t;
}

int main(){
	unsigned n = 5;
	unsigned int t[n];
	unsigned int *a = malloc(sizeof(unsigned int) * 20);
	for(int i=0; i < n; i++)
		t[i]= n - i;
	printf("t =");
	for(int i=0; i < n; i++)
		printf("%d, ", t[i]);
	printf("\n \n");
	a = tri(t, a, a, n);
	printf("a =");
	for(int i=0; i < n; i++)
		printf("%d, ", a[i]);
	printf("\n");
	return 0;
}
