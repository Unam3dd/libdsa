#include "list.h"
#include <stdlib.h>

void	lst_pop(lst_t *lst)
{
	if (!lst) return ;

	lst_node_t	*next = NULL;

	if (lst->lst) next = lst->lst->next;
	if (next) next->prev = NULL;
	free(lst->lst);
	lst->lst = next;
	if (lst->len > 0) lst->len = ~-lst->len;
}

void	lst_pop_back(lst_t *lst)
{
	if (!lst) return ;

	lst_node_t	*prev = NULL;

	if (!lst->last) lst->last = lst_get_last(lst);

	if (!lst->last) return ;

	prev = lst->last->prev;
	if (prev) prev->next = NULL;
	free(lst->last);
	lst->last = prev;
	if (lst->len > 0) lst->len = ~-lst->len;
}
