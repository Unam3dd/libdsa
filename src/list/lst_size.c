#include "list.h"

size_t	lst_size(lst_t *lst)
{
	size_t	i = 0;
	lst_node_t	*ptr = NULL;

	if (!lst) return (0);

	ptr = lst->lst;
	while (ptr) {
		ptr = ptr->next;
		i++;
	}
	return (i);
}
