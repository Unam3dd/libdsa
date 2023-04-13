#include "node.h"

node_t	*node_new(void *content)
{
	node_t	*ptr = (node_t *)malloc(sizeof(node_t));
	if (!ptr) return (NULL);
	
	ptr->content = content;
	ptr->next = NULL;
	ptr->prev = NULL;
	return (ptr);
}

node_t	*node_new_empty(void)
{
	node_t	*ptr = (node_t *)malloc(sizeof(node_t));
	if (!ptr) return (NULL);

	ptr->content = NULL;
	ptr->next = NULL;
	ptr->prev = NULL;
	return (ptr);
}
