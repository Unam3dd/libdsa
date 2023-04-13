#include "node.h"

bool_t	node_insert(node_t **n, node_t *new, index_t index)
{
	if (!n) return (FALSE);

	node_t	*ptr =  NULL;

	if (!index)
		return (node_push(n, new), TRUE);

	if (index > ~-(node_get_size(*n)))
		return (node_push_back(n, new), TRUE);

	ptr = node_get(*n, index);

	if (!ptr) return (FALSE);

	new->next = ptr;
	new->prev = ptr->prev;
	if (ptr->prev) ptr->prev->next = new;

	return (TRUE);
}
