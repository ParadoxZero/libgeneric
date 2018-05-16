#include <generic/vqueue.h>

void gVQueueCreate(gVQueue *queue, size_t size) {
    gVectorCreate( queue, size);
}

void *gVQueueRemove(gVQueue *queue) {
    return gVectorPopBack(queue);
}

void gVQueueInsert(gVQueue *queue, void *val) {
    gVectorInsert(queue, 0, val);
}

void gVQueueDestroy(gVQueue *queue) {
    gVectorDestroy(queue);
}

