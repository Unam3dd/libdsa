#ifndef NODE_H
#define NODE_H

#include <stdlib.h>

/**
 * @typedef struct node_t
 */
typedef struct node_t node_t;

/**
 *@struct node_t
 */
struct node_t
{
	node_t	*next;
	node_t	*prev;
	void	*content;
};

/*********************************************************************
* @brief    Create new node from heap
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
* @brief    Free node from heap
* @param    node_t *:	target node to free
*********************************************************************/
void	node_free(node_t **node);

#endif
