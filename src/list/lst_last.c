#include "list.h"

lst_node_t	*lst_get_last(lst_t *lst)
{
	if (!lst) return (NULL);

	lst_node_t	*ptr = lst->lst;

	while (ptr->next) ptr = ptr->next;

	return (ptr);
}
