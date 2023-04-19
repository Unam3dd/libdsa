#include "list.h"

lst_node_t	*lst_get(lst_t *lst, node_index_t index)
{
	if (!lst) return (NULL);

	if (index > lst->len) return (NULL);

	lst_node_t	*node = lst->lst;

	for (node_index_t i = 0; i != index && node; i++) node = node->next;
	return (node);
}
