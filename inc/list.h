#ifndef LIST_H
#define LIST_H

#include <stddef.h>
#include "bool.h"

typedef struct lst_node_t lst_node_t;
typedef struct lst_t lst_t;
typedef unsigned int node_index_t;
typedef int	(*cb_t)(lst_node_t *lst, void *ptr);

struct lst_node_t
{
	lst_node_t		*next;
	lst_node_t		*prev;
	void			*content;
};

struct lst_t
{
	lst_node_t	*lst;
	lst_node_t	*last;
	size_t		len;
};

#define LIST_CREATE(name) lst_t name = { NULL, NULL, 0};
#define LIST_RESET(lst) lst.len = 0, lst.last = NULL, lst.lst = NULL;

static inline size_t		lst_length(lst_t *lst) { return (lst ? (lst->len) : 0); }
static inline lst_node_t	*lst_begin(lst_t *lst) { return (lst ? (lst->lst) : NULL); }
static inline lst_node_t	*lst_end(lst_t *lst) { return (lst ? (lst->last) : NULL); }

lst_t		*lst_dup(lst_t *lst);
lst_node_t	*lst_node_new(void *content);
lst_node_t	*lst_node_new_packed(size_t size);
lst_node_t	*lst_get(lst_t *lst, node_index_t index);
lst_node_t	*lst_get_last(lst_t *lst);
size_t		lst_copy(lst_t *dst, lst_t *src);
size_t		lst_size(lst_t *lst);
bool_t		lst_insert(lst_t *lst, lst_node_t *new, node_index_t index);
int			lst_iter(lst_t *lst, cb_t func, void *ptr);
void		lst_set(lst_t *lst, lst_node_t *ptr);
void		lst_swap(lst_node_t *a, lst_node_t *b);
void		lst_push(lst_t *lst, lst_node_t *new);
void		lst_push_back(lst_t *lst, lst_node_t *new);
void		lst_pop(lst_t *lst);
void		lst_pop_back(lst_t *lst);
void		lst_free_node(lst_node_t **node);
void		lst_free(lst_t *lst);

#endif
