#include "node.h"

void	node_push(node_t **n, node_t *new)
{
	if (!n) return ;

	new->prev = NULL;
	new->next = *n;
	(*n)->prev = new;
	*n = new;
}

void	node_push_back(node_t **n, node_t *new)
{
	if (!n) return ;

	node_t	*tmp = node_get_last(*n);
	
	if (!tmp) {
		new->prev = NULL;
		new->next = NULL;
		*n = new;
		return ;
	}

	new->prev = tmp;
	new->next = NULL;
	tmp->next = new;
}
