#include <data_structure/new_stack.h>
#include <assert.h>
#include <malloc.h>
#include <string.h>	// memcpy

void stack_init(stack_t *stack,size_t sz)
{
	stack->alloc=(sz==0)?DEFAULT_STACKSZ : sz;
	stack->logical=0;
	stack->elems=malloc(stack->alloc);
}

void stack_push(stack_t *stack,void* val,size_t sz)
{
	assert(stack!=NULL);
	if(stack->elems==NULL){	// If nothing in the stack, initialize it
		stack_init(stack,0);
	}
	char *ptr=stack->elems;
	size_t tmp=stack->logical;
	stack->logical+=sz;
	if(stack->logical>stack->alloc){
		// Double the size of the stack if not enough space
		stack->alloc*=2;
		stack->elems=realloc(stack->elems,stack->alloc);
	}
	memcpy(ptr+tmp,val,sz);	// Push the values to the stack;
}

void *stack_pop(stack_t *stack,size_t sz)
{
	assert(stack!=NULL);
	if(stack->elems==NULL){
		return NULL;
	}
	assert(stack->logical>=sz);
	char *ptr=stack->elems;
	stack->logical-=sz;	// Pop the value
	return ptr+stack->logical;
}

void stack_destroy(stack_t *stack)
{
	assert(stack!=NULL);
	free(stack->elems);
}

