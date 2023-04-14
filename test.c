#include "node.h"
#include <stdio.h>

int main(void)
{
	node_t	*lst = NULL;
	node_t	*tmp = NULL;
	unsigned long	i = 0;

	for (i = 0; i < 4; i++) {
		tmp = node_new((void*)i);
		node_push_back(&lst, tmp);
	}

	node_show_all(lst);
	node_free_all(&lst);
	return (0);
}
