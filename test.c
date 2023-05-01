#include "tlist.h"
#include <stdio.h>
#include <stdlib.h>

TLIST_TYPE(int, mytest);

void	free_lst(TYPE_LIST(mytest**) ptr)
{
	TLIST_FREET(ptr, mytest);
	*ptr = NULL;
}

int main(void)
{
	TLIST_PTR(mytest, toto, NULL);
	TLIST_PTR(mytest, tata, NULL);

	toto = TLIST_ALLOC(mytest);
	tata = TLIST_ALLOC(mytest);

	TLIST_ZERO(toto);
	TLIST_ZERO(tata);

	toto->_data = 1;
	tata->_data = 2;

	TLIST_PUSH(&toto, tata);

	TLIST_FOREACH(toto);

	free_lst(&toto);

	return (0);
}
