#include <stdio.h>
#include "list.h"

int main(void)
{
	lst_node_t	*ptr = NULL;

	LIST_CREATE(lst);

	ptr = lst_node_new("hello");
	lst_push_back(&lst, ptr);
	return (0);
}
