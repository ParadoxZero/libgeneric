#include <data_structure/vector.h>
#include <stdio.h>

vector_t vec;

void insert(size_t pos,int val)
{
	vector_insert(&vec,pos,&val);
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
	insert(0,5);
	insert(0,6);
	insert(0,7);
	insert(0,8);
	for(i=0;i<4;i++){
		printf("Popped value: %d\n",pop());
	}
	vector_destroy(&vec);
}

