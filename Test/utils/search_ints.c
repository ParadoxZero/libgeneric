#include <data_structure/utils.h>
#include <stdio.h>

const int stuff[]={
	1,4,5,3,2,6,9,10
};

const int key=5;

int main(void)
{
	int i;
	int *result;
	printf("stuff[]: %d",stuff[0]);
	for(i=1;i<8;i++){
		printf(", %d",stuff[i]);
	}
	result=(int*)search_generic(&key,stuff,8,sizeof(int));
	printf("\nFound %d at index %lu\n",key,result-stuff);
	return 0;
}

