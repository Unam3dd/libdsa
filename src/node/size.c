#include "node.h"

size_t	node_get_size(node_t *n)
{
	size_t	i = 0;

	while (n) {
		i++;
		n = n->next;
	}

	return (i);
}
