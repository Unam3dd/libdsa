#include "list.h"

static size_t	lst_direct_copy(lst_node_t *d, lst_node_t *s, size_t *i)
{
	if (!d || !s) return (0);

	*i = 0;
	while (s) {
		d->content = s->content;
		s = s->next;
		d = d->next;
		*i += 1;
	}
	return (*i);
}

size_t	lst_copy(lst_t *dst, lst_t *src)
{
	size_t	i = 0;

	if (!dst || !src) return (0);

	lst_node_t	*d = dst->lst;
	lst_node_t	*s = src->lst;

	if (dst->lst == src->lst)
		return (lst_direct_copy(d, s, &i));

	while (s) {
		if (d) d->content = s->content;
		
		if (!d) {
			d = lst_node_new(s->content);
			lst_push_back(dst, d);
			d = dst->last;
		}

		s = s->next;
		d = d->next;
		i++;
	}

	return (i);
}
