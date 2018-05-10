#include <data_structure/vector.h>
#include <stdio.h>

vector_t vec;

void push(int x)
{
	vector_push_back(&vec,&x);
}

int pop(void)
{
	int *x=(int*)vector_pop_back(&vec);
	return *x;
}

int main(void)
{
	int i;
	vector_new(&vec,sizeof(int));
	push(5);
	push(10);
	push(20);
	push(40);
	push(50);
	printf("Top: %d\n",*(int*)vector_back(&vec));
	printf("Bottom: %d\n",*(int*)vector_front(&vec));
	for(i=0;i<5;i++){
		printf("Popped Value: %d\n",pop());
	}
	vector_destroy(&vec);
	return 0;
}

