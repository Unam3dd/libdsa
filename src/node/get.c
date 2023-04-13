#include "node.h"

node_t	*node_get(node_t *n, index_t index)
{
	if (!n) return (NULL);
	
	if (index > ~-node_get_size(n)) return (NULL);

	for (index_t i = 0; n && i < index; i++)
		n = n->next;
	return (n);
}

node_t	*node_get_by_content(node_t *n, cmpfunc_t f, void *content)
{
	if (!n) return (NULL);

	while (n) {
		if (f && !f(n->content, content)) return (n);
		else if (!f && (content == n->content)) return (n);
		n = n->next;
	}

	return (n);
}
