#include "node.h"

void	node_pop(node_t **n)
{
	if (!n) return ;

	node_t	*next = (*n)->next;
	free(*n);
	if (next) next->prev = NULL;
	*n = next;
}

void	node_pop_back(node_t **n)
{
	if (!n) return ;

	node_t	*last = node_get_last(*n);

	if (!last) return ;

	if (last->prev) last->prev->next = NULL;
	free(last);
}
