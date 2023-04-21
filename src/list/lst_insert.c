#include "bool.h"
#include "list.h"

bool_t	lst_insert(lst_t *lst, lst_node_t *new, node_index_t index)
{
	lst_node_t	*ptr = NULL;

	if (!lst || !new) return (FALSE);

	if (!index) return (lst_push(lst, new), TRUE);
	
	ptr = lst_get(lst, index);

	if (!ptr)
		return (lst_push_back(lst, new), TRUE);

	new->next = ptr;
	new->prev = ptr->prev;

	if (ptr->prev)
		ptr->prev->next = new;
	if (ptr->next)
		ptr->next->prev = new;

	lst->len++;

	return (TRUE);
}
