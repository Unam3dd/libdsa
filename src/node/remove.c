#include "node.h"
#include <stdlib.h>

bool_t	node_remove(node_t **n, index_t index)
{
	if (!n) return (FALSE);

	node_t	*ptr = node_get(*n, index);

	if (!ptr) return (FALSE);

	if (!ptr->prev && !ptr->next) {
		free(ptr);
		*n = NULL;
		return (TRUE);
	}

	if (ptr->prev) ptr->prev->next = ptr->next;

	if (ptr->next) ptr->next->prev = ptr->prev;

	free(ptr);

	return (TRUE);
}
