#include "node.h"
#include <stdio.h>
#include "colors.h"

void	node_show(node_t *n)
{
	if (!n) {
		dprintf(2, "[!] No Node to show !\n");
		return ;
	}

	printf("[+]\tAddress of Node : \033[32m%p\033[00m\n[+]\tContent : %p\n[+]\tNext : %p \033[31m(+%ld offset)\033[00m\n[+]\tPrev : %p \033[31m(%ld offset)\033[00m\n",
			&n, n->content, n->next, NODE_DELTA(n->next, n), n->prev, NODE_DELTA(n->prev, n));
}

void	node_show_all(node_t *n)
{
	if (!n) {
		dprintf(2, "[!] No Nodes to show !\n");
		return ;
	}
	
	index_t	i = 0;

	while (n) {
		printf("\nNode[\033[32m%p\033[00m|\033[32m%d\033[00m]:\n", n, i);
		node_show(n);
		n = n->next;
		i++;
	}
}
