#ifndef NODE_H
#define NODE_H

#include <stdlib.h>
#include "bool.h"

/**
 * @typedef struct node_t
 */
typedef struct node_t	node_t;

/**
 * @typedef unsigned int index
 */
typedef unsigned int	index_t;

/**
 * @typedef callback function
 */
typedef int (*cmpfunc_t)(void *, void *);

/**
 * @struct node_t
 *
 */
struct node_t
{
	node_t	*next;
	node_t	*prev;
	void	*content;
};

/*********************************************************************
* @brief    Create new node from heap and set content
* @param	void *:	content 
* @return   new pointer from heap memory
*********************************************************************/
node_t	*node_new(void *content);

/*********************************************************************
* @brief    Create new node from heap
* @return   new pointer from heap memory
*********************************************************************/
node_t	*node_new_empty(void);

/*********************************************************************
* @brief    Get size of list
* @param    node_t*: head of the list
* @return	size_t:	size of the list
*********************************************************************/
size_t	node_get_size(node_t *n);

/*********************************************************************
* @brief    Get a node in list
* @param    node_t*: head of the list
* @param	index_t: index of the element in list to get
* @return	node_t*: pointer to a node in the list at index set
*********************************************************************/
node_t	*node_get(node_t *n, index_t index);

/*********************************************************************
* @brief    Remove the node on top of the list
* @param    node_t*		: head of the list
* @param	cmpfunc_t	: callback function to compare the content
* @return	node_t*		: pointer to a node in the list
*********************************************************************/
node_t	*node_get_by_content(node_t *n, cmpfunc_t f, void *content);

/*********************************************************************
* @brief    Get last element of the list
* @param    node_t*		: head of the list
* @return	node_t*		: pointer to a node which is a last element in the
* list
*********************************************************************/
node_t	*node_get_last(node_t *n);

/*********************************************************************
* @brief    Insert a new node in list
* @param    node_t**	: reference to head of the list
* @param	node_t*		: pointer node that will be inserted
* @return	bool_t		: true if node has been inserted otherwise false
* 					if it has not been
* 					inserted
*********************************************************************/
bool_t	node_insert(node_t **n, node_t *new);

/*********************************************************************
* @brief    Free node from heap
* @param    node_t **: reference to a node pointer
*********************************************************************/
void	node_free(node_t **node);

/*********************************************************************
* @brief    Push a new node at the top of the list
* @param    node_t**: reference to a head of list
* @param	node_t *: The new node that will be push at top of the list
*********************************************************************/
void	node_push(node_t **n, node_t *new);

/*********************************************************************
* @brief    Push a new node at end of the list
* @param    node_t**: reference to a head of list
* @param	node_t*: The new node that will be push at end of the list
*********************************************************************/
void	node_push_back(node_t **n, node_t *new);

/*********************************************************************
* @brief    Remove the node on top of the list
* @param    node_t**: reference of head list
*********************************************************************/
void	node_pop(node_t **n);

/*********************************************************************
* @brief    Remove the node at end of the list
* @param    node_t**: reference of head list
*********************************************************************/
void	node_pop_back(node_t **n);

/*********************************************************************
* @brief    Free all list
* @param    node_t**: reference of head list
*********************************************************************/
void	node_free_all(node_t **n);

#endif
