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

	for (i = 0; i < sizeof(ptr)/sizeof(node_t*); i++) {
		ptr[i] = node_new_empty();
		ASSERT_NEQ(ptr[i], NULL);
	}

	for (i = 0; i < sizeof(ptr)/sizeof(node_t*); i++) {
		node_free(&ptr[i]);
		ASSERT_EQ(ptr[i], NULL);
	}

	PASS();
}

TEST	node_test_push(void)
{
	node_t	*ptr[0x5];
	node_t	*lst = NULL;
	size_t	i = 0;

	for (i = 0; i < sizeof(ptr)/sizeof(node_t*); i++) {
		ptr[i] = node_new((int *)i);
		ASSERT_NEQ(ptr[i], NULL);
		ASSERT_EQ(ptr[i]->content, (int *)i);
	}

	for (i = 0; i < sizeof(ptr)/sizeof(node_t*); i++) {
		node_push(&lst, ptr[i]);
		ASSERT_EQ(lst, ptr[i]);
		ASSERT_EQ(lst->content, (int *)i);
	}

	node_free_all(&lst);

	PASS();
}

#endif
