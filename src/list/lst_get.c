#include "list.h"

lst_node_t	*lst_get(lst_t *lst, node_index_t index)
{
	if (!lst) return (NULL);

	lst_node_t	*node = lst->lst;

	while (node && index != node->index)
		node = node->next;
	return (node);
}
