#include <data_structure/new_stack.h>
#include <stdio.h>

stack_t stack;

void push(int val)
{
	stack_push(&stack,&val,sizeof(int));
}

int pop(void)
{
	int *res=stack_pop(&stack,sizeof(int));
	return *res;
}

int main(void)
{
	stack_init(&stack,0);
	push(4);
	push(1);
	push(5);
	push(20);
	push(10);
	int i=5;
	while(i--){
		printf("Value: %d\n",pop());
	}
	stack_destroy(&stack);
	return 0;
}

