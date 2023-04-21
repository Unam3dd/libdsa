#include "list.h"

void	lst_swap(lst_node_t *a, lst_node_t *b)
{
	if (!a || !b) return ;

	void	*tmp = a->content;

	a->content = b->content;
	b->content = tmp;
}

