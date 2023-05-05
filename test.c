#include "tlist.h"
#include <stdio.h>
#include <stdlib.h>

TLIST_TYPE(int, mytest);
TLIST_TYPE(struct { char *name; int age; }, persons);

void	free_lst(TYPE_LIST(mytest**) ptr)
{
	TLIST_FREET(ptr, mytest);
	*ptr = NULL;
}

int main(void)
{
	TLIST_PTR(mytest, toto, NULL);
	TLIST_PTR(mytest, tata, NULL);
	TLIST_PTR(mytest, titi, NULL);
	TLIST_PTR(mytest, get, NULL);
	TLIST_PTR(mytest, insert, NULL);
	size_t	len_lst = 0;

	toto = TLIST_ALLOC(mytest);
	tata = TLIST_ALLOC(mytest);
	titi = TLIST_ALLOC(mytest);
	insert = TLIST_ALLOC(mytest);

	TLIST_NEW_STACK(persons, robert);

	robert._data.name = "Robert";
	robert._data.age = 21;

	printf("Name : %s | Age : %d\n", robert._data.name, robert._data.age);

	TLIST_ZERO(toto);
	TLIST_ZERO(tata);
	TLIST_ZERO(titi);

	toto->_data = 1;
	tata->_data = 2;
	titi->_data = 3;
	insert->_data = 4;

	TLIST_PUSH(&toto, tata);

	printf("Push tata in toto\n");

	TLIST_FOREACH(toto);

	printf("\nPush titi in toto\n");

	TLIST_PUSH_BACK(&toto, titi);

	TLIST_FOREACH(toto);

	printf("\nPop Top of the list\n");

	TLIST_POP(&toto);

	TLIST_FOREACH(toto);

	printf("\nGet Index 1\n");
	get = TLIST_GET(toto, 1);
	len_lst = TLIST_LENGTH(toto);

	printf("Length of list : %ld\n", len_lst);

	printf("Get : %p | %d\n", get, get->_data);

	printf("\nPop Back\n");

	TLIST_POP_BACK(&toto);

	TLIST_FOREACH(toto);

	printf("\nAnother pop back\n");

	TLIST_POP_BACK(&toto);

	TLIST_FOREACH(toto);

	free_lst(&toto);

	return (0);
}
