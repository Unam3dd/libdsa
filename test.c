#include "tlist.h"
#include <stdio.h>

int main(void)
{
	TLIST(int, mytest);
	TLIST_PTR(mytest, toto, NULL);

	TLIST_NEW(mytest, mdr);

	return (0);
}
