#include "list.h"

int	lst_iter(lst_t *lst, cb_t func, void *ptr)
{
	if (!lst) return (1);
	lst_node_t	*tmp = lst->lst;

	while (tmp) {
		if (func) func(tmp, ptr);
		tmp = tmp->next;
	}
	return (0);
}
