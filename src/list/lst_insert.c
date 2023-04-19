#include "bool.h"
#include "list.h"

bool_t	lst_insert(lst_t *lst, lst_node_t *new, node_index_t index)
{
	lst_node_t	*ptr = NULL;
	lst_node_t	*prev = NULL, *next = NULL;

	if (!lst || !new) return (FALSE);
	
	ptr = lst_get(lst, index);

	if (!ptr)
		return (lst_push_back(lst, new), TRUE);

	prev = ptr->prev;
	next = ptr->next;
	
	new->next = next;
	new->prev = prev;

	if (prev) prev->next = new;
	if (next) next->prev = new;

	lst->len++;

	return (TRUE);
}
