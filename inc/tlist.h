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

#define TYPE_LIST(L) struct _list##L

#define TLIST_TYPE(T, L)								\
	typedef struct _list##L {							\
		struct _list##L	*_next;							\
		struct _list##L	*_prev;							\
		T				_data;							\
	} L;

#define TLIST_T(T, L, D)\
	struct _list##T	L = D;\

#define TLIST_PTR(T, L, D)\
	struct _list##T *L = D;

#define TLIST_NEW_STACK(T, L)\
	struct	_list##T L = { NULL, NULL, 0 };\

#define TLIST_NEW(T, L)\
	 struct _list##T *L = (struct _list##T*) malloc(sizeof(struct _list##T));\

#define TLIST_ALLOC(T) (struct _list##T *)malloc(sizeof(struct _list##T));

#define TLIST_SET(ptr, data)\
	ptr->_data = data;

#define TLIST_ZERO(PTR)\
	PTR->_next = NULL;\
	PTR->_prev = NULL;\
	PTR->_data = 0;

#define TLIST_FREE(LST)\
	({\
	 	typeof(LST)	_next = NULL;\
	 	while (LST) {\
	 		_next = LST->_next;\
			free(LST);\
			LST = _next;\
	 	}\
	 })

#define TLIST_FREE_BLOCK(PTR)\
	free(*ptr);\
	*ptr = NULL;

#define TLIST_FREET(LST, TYPE)\
	({\
	 	struct _list##TYPE	*_next = NULL;\
	 	while (*LST) {\
	 		_next = (*LST)->_next;\
			free(*LST);\
			*LST = _next;\
	 	}\
		*LST = NULL;\
	 })

#endif
