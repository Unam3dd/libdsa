#include "list.h"

void	lst_set(lst_t *lst, lst_node_t *ptr)
{
	if (!lst || !ptr) return ;

	lst->lst = ptr;
	lst->last = lst_get_last(lst);
	lst->len = lst_size(lst);
}
