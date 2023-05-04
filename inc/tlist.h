#ifndef TLIST_H
#define TLIST_H

#include <stddef.h>
#include <stdio.h>
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

#define TLIST_PUSH(LST, NEW)\
	NEW->_prev = NULL;\
	NEW->_next = *LST;\
	if (*LST) (*LST)->_prev = NEW;\
	*LST = NEW;

#define TLIST_POP(LST)\
	({\
	 typeof(*LST)	next = NULL;\
	 next = (*LST)->_next;\
	 if (next) next->_prev = NULL;\
	 free(*LST);\
	 *LST = next;\
	 })

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

#define TLIST_PUSH_BACK(LST, NEW)\
	({\
	 typeof(*LST)	tmp = *LST;\
	 while (tmp && tmp->_next) tmp = tmp->_next;\
	 if (NEW){\
	 	NEW->_next = NULL;\
		NEW->_prev = tmp;}\
	 if (tmp) tmp->_next = NEW;\
	 })

#define TLIST_POP_BACK(LST)\
	({\
	 typeof(*LST)	tmp = *LST;\
	 typeof(*LST)	prev = NULL;\
	 while (tmp && tmp->_next) tmp = tmp->_next;\
	 if (tmp) prev = tmp->_prev;\
	 if (prev) prev->_next = NULL;\
	 if (!prev) *LST = NULL;\
	 free(tmp);\
	 })

#define TLIST_FOREACH(LST)\
		({\
		 	typeof(LST)	tmp = LST;\
			if (!tmp) printf("NULL\n");\
			for (unsigned int i = 0; tmp; tmp = tmp->_next, i++) printf("[%d]:	%p | %p\n", i, tmp, tmp->_data);\
		})

#define	TLIST_GET(LST, idx)\
	({\
	 typeof(LST)	tmp = LST;\
	 for (size_t i = 0; i < idx && tmp; i++, tmp = tmp->_next);\
	 tmp;\
	 })

#define TLIST_LENGTH(LST)\
	({\
	 	typeof(LST)	tmp = LST;\
	 	size_t	len = 0;\
		while (tmp){\
			len++;\
			tmp = tmp->_next;\
		}\
		len;\
	 })

#endif
