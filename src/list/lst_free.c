#include "list.h"
#include <stdlib.h>

void	lst_free_node(lst_node_t **node)
{
	if (!node) return ;
	free(*node);
	*node = NULL;
}

void	lst_free(lst_t *lst)
{
	if (!lst) return ;

	lst_node_t	*next = NULL, *actual = NULL;

	actual = lst->lst;

	while (actual) {
		next = actual->next;
		free(actual);
		actual = next;
	}

	lst->lst = NULL;
	lst->last = NULL;
	lst->len = 0;
}
