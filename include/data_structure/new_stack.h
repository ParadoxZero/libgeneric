#ifndef _DATA_STRUCTURE_STACK_H_
#define	_DATA_STRUCTURE_STACK_H_
#include <stddef.h>	// size_t

/** Default size of the stack */
#define	DEFAULT_STACKSZ	16

/**
 * The data structure of stack
 * Assuming the members are invisible to users
 */
typedef struct stack_struct{
	void *elems;	/** The pointer to the elements of the stack */
	size_t logical;	/** Logical size of the stack */
	size_t alloc;	/** Allocated size of the stack */
}stack_t;

/** Create a new stack
 *
 * The size of the new stack will be DEFAULT_STACKSZ if sz is zero
 */
extern void stack_init(stack_t *stack,size_t sz);
/** Push bytes to the stack
 *
 * It will double the size of the stack if there is no more space
 */
extern void stack_push(stack_t *stack,void *val,size_t sz);
/** Pop bytes from stack
 *
 * It pops sz bytes from the stack
 */
extern void *stack_pop(stack_t *stack,size_t sz);
/** Destroy the stack */
extern void stack_destroy(stack_t *stack);
#endif
