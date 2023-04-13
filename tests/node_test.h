#ifndef NODE_TEST_H
#define NODE_TEST_H

#include "greatest/greatest.h"
#include "node.h"

TEST	node_new_test(void)
{
	char	*hello = "hello";
	node_t	*ptr = node_new(hello);
	ASSERT_NEQ(ptr, NULL);
	ASSERT_EQ(ptr->next, NULL);
	ASSERT_EQ(ptr->prev, NULL);
	ASSERT_EQ(ptr->content, hello);
	node_free(&ptr);
	ASSERT_EQ(ptr, NULL);
	PASS();
}

#endif
