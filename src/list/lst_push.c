#include "list.h"

void	lst_push(lst_t *lst, lst_node_t *new)
{
	if (!lst || !new) return ;

	if (!lst->lst) {
		lst->lst = new;
		lst->last = lst->lst;
		return ;
	}

	new->next = lst->lst;
	new->prev = NULL;
	if (lst->lst) lst->lst->prev = new;
	lst->lst = new;
}

