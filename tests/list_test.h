#ifndef LIST_TEST_H
#define LIST_TEST_H

#include "greatest/greatest.h"
#include "list.h"

TEST	list_test_basic1(void)
{
	lst_node_t	*ptr = NULL;

	ptr = lst_node_new((char *)"hello");
	ASSERT_NEQ(ptr, NULL);
	ASSERT_STR_EQ(ptr->content, "hello");
	lst_free_node(&ptr);
	ASSERT_EQ(ptr, NULL);
	PASS();
}

TEST	list_test_basic2(void)
{
	LIST_CREATE(lst);
	lst_node_t	*ptr = NULL;
	ptr = lst_node_new((char *)"hello");
	ASSERT_NEQ(ptr, NULL);
	lst_push(&lst, ptr);
	ASSERT_EQ(lst.lst, ptr);
	ASSERT_EQ(lst.last, ptr);
	ASSERT_EQ(lst.len, 1);
	lst_free(&lst);
	ASSERT_NEQ(lst.lst, ptr);
	PASS();
}

TEST	list_test_basic3(void)
{
	LIST_CREATE(lst);
	lst_node_t	*ptr[0x2] = {NULL, NULL};

	ptr[0] = lst_node_new((char *)"hello");
	ASSERT_NEQ(ptr[0], NULL);
	ptr[1] = lst_node_new((char *)"world");
	ASSERT_NEQ(ptr[1], NULL);
	lst_push(&lst, ptr[0]);
	lst_push(&lst, ptr[1]);
	ASSERT_EQ(lst.lst, ptr[1]);
	ASSERT_EQ(lst.lst->next, ptr[0]);
	ASSERT_EQ(lst.lst->next->prev, ptr[1]);
	ASSERT_EQ(lst.lst->prev, NULL);
	ASSERT_EQ(lst.len, 2);
	ASSERT_EQ(lst.last, ptr[0]);
	lst_free(&lst);
	ASSERT_EQ(lst.lst, NULL);
	PASS();
}

#endif
