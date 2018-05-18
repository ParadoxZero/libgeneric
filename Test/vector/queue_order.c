#include <stdio.h>
#include <generic/vqueue.h>

struct order {
    char title[20];
    char content[100];
};

gQueue queue_order;

struct order wakeup = {"Wake up", "Get off the bed and brush you teeth"};
struct order breakfast = {"Breakfast", "Eat eggs and drink milk"};
struct order code = {"Coding", "Open your laptop and code"};

void print_order(struct order *ordr) {
    printf("%s: %s\n", ordr->title, ordr->content);
}

void add_order(struct order *ordr) {
    gQueueInsert(&queue_order, ordr);
    printf("New order - ");
    print_order(ordr);
}

void do_order(void) {
    struct order ordr = *(struct order *) gQueueRemove(&queue_order);
    printf("Doing \"%s\"...\n", ordr.content);
    printf("Completed \"%s\"\n", ordr.title);
}

int main(void) {
    gQueueCreate(&queue_order, sizeof(struct order));
    add_order(&wakeup);
    add_order(&breakfast);
    add_order(&code);
    do_order();
    do_order();
    gQueueDestroy(&queue_order);
    return 0;
}

