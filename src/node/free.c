#include "node.h"

void	node_free(node_t **node)
{
	if (!node || !*node) return ;
	free(*node);
	*node = NULL;
}

void	node_free_all(node_t **n)
{
	if (!n) return ;

	node_t	*next = NULL;

	while (n) {
		next = (*n)->next;
		free(*n);
		*n = next;
	}
	*n = NULL;
}
