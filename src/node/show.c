#include "node.h"
#include <stdio.h>

void	node_show(node_t *n)
{
	if (!n) {
		dprintf(2, "[!] No Node to show !\n");
		return ;
	}

	printf("[+]\tAddress of Node : %p\n[+]\tContent : %p\n[+]\tNext : %p\n[+]\tPrev : %p\n",
			&n, n->content, n->next, n->prev);
}

void	node_show_all(node_t *n)
{
	if (!n) {
		dprintf(2, "[!] No Nodes to show !\n");
		return ;
	}
	
	index_t	i = 0;

	while (n) {
		printf("\nNode[%p|%d]:\n", n, i);
		node_show(n);
		n = n->next;
		i++;
	}
}
