#include "list.h"
#include <stdlib.h>

lst_t	*lst_dup(lst_t *lst)
{
	if (!lst) return (NULL);

	lst_t		*n = NULL;
	lst_node_t	*ptr = NULL, *tmp = NULL;

	n = (lst_t *)malloc(sizeof(lst_t));
	if (!n) return (NULL);

	n->last = NULL;
	n->len = 0;
	n->lst = NULL;

	tmp = lst->lst;

	while (tmp) {
		ptr = lst_node_new(tmp->content);
		lst_push_back(n, ptr);
		tmp = tmp->next;
	}

	return (n);
}
