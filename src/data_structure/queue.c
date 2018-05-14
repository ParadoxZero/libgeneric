#include <data_structure/vqueue.h>

void queue_new(queue_t *queue,size_t size)
{
	vector_new((vector_t*)queue,size);
}

void *queue_pop(queue_t *queue)
{
	return vector_pop_back((vector_t*)queue);
}

void queue_push(queue_t *queue,void *val)
{
	vector_insert((vector_t*)queue,0,val);
}

void queue_destroy(queue_t *queue)
{
	vector_destroy((queue_t*)queue);
}

