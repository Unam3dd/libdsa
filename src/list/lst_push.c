#include "list.h"

void	lst_push(lst_t *lst, lst_node_t *new)
{
	if (!lst || !new) return ;

	if (!lst->lst) {
		lst->lst = new;
		lst->last = lst->lst;
		lst->len++;
		return ;
	}

	new->next = lst->lst;
	new->prev = NULL;
	if (lst->lst) lst->lst->prev = new;
	lst->lst = new;
	lst->len++;
}

void	lst_push_back(lst_t *lst, lst_node_t *new)
{
	if (!lst || !new) return ;

	if (!lst->lst) {
		new->prev = NULL;
		new->next = NULL;
		lst->lst = new;
		lst->last = lst->lst;
		lst->len++;
		return ;
	}

	if (!lst->last) lst->last = lst_get_last(lst);

	if (lst->last) {
		new->prev = lst->last;
		new->next = NULL;
		lst->last->next = new;
		lst->last = lst->last->next;
		lst->len++;
	}
}
