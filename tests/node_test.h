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

TEST	node_new_void(void)
{
	node_t	*ptr = node_new_empty();

	ASSERT_NEQ(ptr, NULL);
	ASSERT_EQ(ptr->content, NULL);
	ASSERT_EQ(ptr->next, NULL);
	ASSERT_EQ(ptr->prev, NULL);
	node_free(&ptr);
	ASSERT_EQ(ptr, NULL);
	PASS();
}

TEST	node_free_test1(void)
{
	node_t	*ptr[0x10];
	size_t	i = 0;

	for (i = 0; i < sizeof(ptr)/sizeof(node_t*); i++)
		ptr[i] = node_new_empty();
	for (i = 0; i < sizeof(ptr)/sizeof(node_t*); i++) {
		node_free(&ptr[i]);
		ASSERT_EQ(ptr[i], NULL);
	}
	PASS();
}

#endif
