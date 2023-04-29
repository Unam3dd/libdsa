#ifndef TLIST_H
#define TLIST_H

#include <stddef.h>
#include <stdlib.h>

#define TLIST(T,L)										\
	struct _list##L { 									\
		struct _list##L	*_next;							\
		struct _list##L	*_prev;							\
		T				_data;							\
	} L = { NULL, NULL, 0 };

#define TLIST_TYPE(T, L)								\
	typedef struct _list##L {							\
		struct _list##L	*_next;							\
		struct _list##L	*_prev;							\
		T				_data;							\
	} L;

#define TLIST_T(T, L, D)\
	typeof(T)	L = D;\

#define TLIST_PTR(T, L, D)\
	typeof(T)	*L = D;\

#define TLIST_CAST_PTR(T)\
	typeof(T)*;\

#define TLIST_NEW_STACK(T, L)\
	typeof(T)	L = { NULL, NULL, 0 };

#define TLIST_NEW(T, L)\
	 typeof(T*)	L = (typeof(T *)) malloc(sizeof(*T));

#endif
