#include "node.h"

node_t	*node_get_last(node_t *n)
{
	if (!n) return (NULL);

	while (n->next) n = n->next;

	return (n);
}
