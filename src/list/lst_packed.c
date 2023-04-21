#include "list.h"
#include <stdlib.h>

lst_node_t	*lst_node_new_packed(size_t size)
{
	lst_node_t	*ptr = (lst_node_t *)malloc(sizeof(lst_node_t) * size);

	if (!ptr) return (NULL);

	for (size_t i = 0; i < size; i++) {
		ptr[i].content = NULL;
		ptr[i].next = (i+1 == size) ? NULL : (lst_node_t*)&ptr[i+1];
		ptr[i].prev = (i) ? (lst_node_t *)&ptr[i-1] : NULL; 
	}

	return (ptr);
}
