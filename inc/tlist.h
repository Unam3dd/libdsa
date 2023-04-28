#ifndef TLIST_H
#define TLIST_H

#include <stddef.h>
#include <stdlib.h>

#define TLIST(T,L)				\
	struct _list##L { 			\
		struct _list##L	*_next;	\
		struct _list##L	*_prev;	\
		T				_data;	\
	} L = { NULL, NULL };

#define TLIST_TYPE(T, L)				\
	typedef struct _list##L {			\
		struct _list##L	*_next;			\
		struct _list##L	*_prev;			\
		T				_data;			\
	} L;

#endif
