#include "list.h"
#include <stdlib.h>

lst_node_t	*lst_node_new(void *content)
{
	lst_node_t	*ptr = NULL;

	ptr = (lst_node_t*)malloc(sizeof(lst_node_t));
	if (!ptr) return (NULL);
	
	ptr->content = content;
	ptr->index = 0;
	ptr->next = NULL;
	ptr->prev = NULL;

	return (ptr);
}
