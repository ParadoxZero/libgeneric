#include <stdio.h>
#include <algorithm/merge_sort.h>

int arr[]={
	5,3,6,1,7,9,4
};

void print_array(int *arr,size_t n)
{
	size_t i;
	printf("%d",arr[0]);
	for(i=1;i<n;i++){
		printf(", %d",arr[i]);
	}
	putchar('\n');
}

int main(void)
{
	printf("Before sorted: ");
	print_array(arr,7);
	merge_sort(arr,7);
	printf("After sorted: ");
	print_array(arr,7);
	return 0;
}

