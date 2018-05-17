#include <stdio.h>
#include <algorithm/mergesort.h>

struct person{
	char name[32];
	int age;
};

struct person people[]={
	{"Harry",13},
	{"John",17},
	{"Tom",14},
	{"Tim",16}
};

int compare_person(void *a,void *b)
{
	struct person *x=(struct person*)a;
	struct person *y=(struct person*)b;
	return (x->age)-(y->age);
}

void print_people(struct person *people,size_t npeople)
{
	size_t i;
	for(i=0;i<npeople;i++){
		printf("%s is %d years old\n",people[i].name,people[i].age);
	}
}

int main(void)
{
	printf("Before sorted:\n");
	print_people(people,sizeof(people)/sizeof(struct person));
	merge_sort_generic(people,sizeof(people)/sizeof(struct person),sizeof(struct person),compare_person);
	printf("After sorted:\n");
	print_people(people,sizeof(people)/sizeof(struct person));
	return 0;
}

