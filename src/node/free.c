#include "node.h"

void	node_free(node_t **node)
{
	if (!node) return ;
	free(*node);
	*node = NULL;
}
