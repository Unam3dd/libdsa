#ifndef TLIST_H
#define TLIST_H

#include <stddef.h>
#include <stdlib.h>

#define TLIST(T,L)										\
	struct _list##L { 									\
		struct _list##L	*_next;							\
		struct _list##L	*_prev;							\
		T				_data;							\
	} L = { NULL, NULL };

#define TLIST_TYPE(T, L)								\
	typedef struct _list##L {							\
		struct _list##L	*_next;							\
		struct _list##L	*_prev;							\
		T				_data;							\
	} L;

#define TLIST_T(T, L, D)\
	typeof(T)	L = D;

#define TLIST_PTR(T, L, D)\
	typeof(T)	*L = D;

#define TLIST_NEW_STACK(T, L)							\
	 typeof(T)	L;\

#define TLIST_NEW(T, L)									\
	({\
	 typeof(T)	*L = typeof(T)malloc(sizeof(T));		\
	 })

#define TLIST_FREE(ptr)\
	free(ptr);\
	ptr = NULL;

#endif
