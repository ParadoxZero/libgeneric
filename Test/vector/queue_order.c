#include <stdio.h>
#include <data_structure/vqueue.h>

struct order{
	char title[20];
	char content[100];
};

queue_t queue_order;

struct order wakeup={"Wake up","Get off the bed and brush you teeth"};
struct order breakfast={"Breakfast","Eat eggs and drink milk"};
struct order code={"Coding","Open your laptop and code"};

void print_order(struct order *ordr)
{
	printf("%s: %s\n",ordr->title,ordr->content);
}

void add_order(struct order *ordr)
{
	queue_push(&queue_order,ordr);
	printf("New order - ");
	print_order(ordr);
}

void do_order(void)
{
	struct order ordr=*(struct order*)queue_pop(&queue_order);
	printf("Doing \"%s\"...\n",ordr.content);
	printf("Completed \"%s\"\n",ordr.title);
}

int main(void)
{
	queue_new(&queue_order,sizeof(struct order));
	add_order(&wakeup);
	add_order(&breakfast);
	add_order(&code);
	do_order();
	do_order();
	queue_destroy(&queue_order);
	return 0;
}

