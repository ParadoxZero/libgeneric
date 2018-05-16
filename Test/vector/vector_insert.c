#include <generic/vector.h>
#include <stdio.h>

gVector vec;

void insert(size_t pos, int val) {
    gVectorInsert(&vec, pos, &val);
}

int pop(void) {
    int *x = (int *) gVectorPopBack(&vec);
    return *x;
}

int main(void) {
    int i;
    gVectorCreate(&vec, sizeof(int));
    insert(0, 5);
    insert(0, 6);
    insert(0, 7);
    insert(0, 8);
    for (i = 0; i < 4; i++) {
        printf("Popped value: %d\n", pop());
    }
    gVectorDestroy(&vec);
}

