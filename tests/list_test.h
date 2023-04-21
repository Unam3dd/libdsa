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

TEST	list_test_basic4(void)
{
	LIST_CREATE(lst);
	lst_node_t	*ptr[0x2] = { NULL, NULL };

	ptr[0] = lst_node_new((char *)"hello");
	ASSERT_NEQ(ptr[0], NULL);
	ptr[1] = lst_node_new((char *)"world");
	ASSERT_NEQ(ptr[1], NULL);
	lst_push_back(&lst, ptr[0]);
	lst_push_back(&lst, ptr[1]);
	ASSERT_EQ(lst.lst, ptr[0]);
	ASSERT_EQ(lst.lst->next, ptr[1]);
	ASSERT_EQ(lst.lst->next->prev, ptr[0]);
	ASSERT_EQ(lst.lst->prev, NULL);
	ASSERT_EQ(lst.len, 2);
	ASSERT_EQ(lst.last, ptr[1]);
	lst_free(&lst);
	ASSERT_EQ(lst.lst, NULL);
	PASS();
}

TEST	list_test_basic5(void)
{
	LIST_CREATE(lst);
	lst_node_t	*ptr[0x2] = { NULL, NULL };

	ptr[0] = lst_node_new((char *)"hello");
	ASSERT_NEQ(ptr[0], NULL);
	ptr[1] = lst_node_new((char *)"world");
	ASSERT_NEQ(ptr[1], NULL);
	lst_push_back(&lst, ptr[0]);
	lst_push_back(&lst, ptr[1]);
	ASSERT_EQ(lst.lst, ptr[0]);
	ASSERT_EQ(lst.lst->next, ptr[1]);
	ASSERT_EQ(lst.lst->next->prev, ptr[0]);
	ASSERT_EQ(lst.lst->prev, NULL);
	ASSERT_EQ(lst.len, 2);
	ASSERT_EQ(lst.last, ptr[1]);
	lst_pop(&lst);
	ASSERT_EQ(lst.lst, ptr[1]);
	ASSERT_EQ(lst.len, 1);
	ASSERT_EQ(lst.lst->next, NULL);
	lst_free(&lst);
	ASSERT_EQ(lst.lst, NULL);
	PASS();
}

TEST	list_test_basic6(void)
{
	LIST_CREATE(lst);
	lst_node_t	*ptr[0x2] = { NULL, NULL };

	ptr[0] = lst_node_new((char *)"hello");
	ASSERT_NEQ(ptr[0], NULL);
	ptr[1] = lst_node_new((char *)"world");
	ASSERT_NEQ(ptr[1], NULL);
	lst_push_back(&lst, ptr[0]);
	lst_push_back(&lst, ptr[1]);
	ASSERT_EQ(lst.lst, ptr[0]);
	ASSERT_EQ(lst.lst->next, ptr[1]);
	ASSERT_EQ(lst.lst->next->prev, ptr[0]);
	ASSERT_EQ(lst.lst->prev, NULL);
	ASSERT_EQ(lst.len, 2);
	ASSERT_EQ(lst.last, ptr[1]);
	lst_pop(&lst);
	ASSERT_EQ(lst.lst, ptr[1]);
	ASSERT_EQ(lst.len, 1);
	ASSERT_EQ(lst.lst->next, NULL);
	lst_pop(&lst);
	ASSERT_EQ(lst.lst, NULL);
	ASSERT_EQ(lst.len, 0);
	lst_free(&lst);
	ASSERT_EQ(lst.lst, NULL);
	PASS();
}

TEST	list_test_basic7(void)
{
	LIST_CREATE(lst);
	lst_node_t	*ptr = NULL;
	lst_node_t	*get = NULL;

	for (size_t i = 0; i < 0xFFFF; i++) {
		ptr = lst_node_new((size_t *)i);
		ASSERT_NEQ(ptr, NULL);
		lst_push_back(&lst, ptr);
		ASSERT_EQ(lst.last, ptr);
	}

	ASSERT_NEQ(lst.last,NULL);
	ASSERT_EQ(lst.len, 0xFFFF);

	get = lst_get(&lst, 44);
	ASSERT_NEQ(get, NULL);
	ASSERT_EQ(get->content, (size_t*)44);
	ASSERT_NEQ(get->next, NULL);
	ASSERT_NEQ(get->prev, NULL);
	ASSERT_EQ(get->next->content, (size_t*)45);
	ASSERT_EQ(get->prev->content, (size_t*)43);
	lst_free(&lst);
	ASSERT_EQ(lst.lst, NULL);
	ASSERT_EQ(lst.last, NULL);
	ASSERT_EQ(lst.len, 0);
	PASS();
}

TEST	list_test_basic8(void)
{
	LIST_CREATE(lst);
	lst_node_t	*ptr = NULL;
	lst_node_t	*insert = NULL;
	lst_node_t	*get = NULL;

	for (size_t i = 0; i < 0x100; i++) {
		ptr = lst_node_new((size_t*)i);
		ASSERT_NEQ(ptr, NULL);
		lst_push(&lst, ptr);
		ASSERT_EQ(lst.lst->content, ptr->content);
	}
	ASSERT_EQ(lst_length(&lst), 0x100);
	insert = lst_node_new((size_t*)0x666);
	ASSERT_NEQ(insert, NULL);
	lst_insert(&lst, insert, 3);
	get = lst_get(&lst, 3);
	ASSERT_NEQ(get, NULL);
	ASSERT_EQ(get->content, insert->content);
	ASSERT_EQ(lst_length(&lst), 0x101);
	lst_free(&lst);
	ASSERT_EQ(lst.lst, NULL);
	PASS();
}

TEST	list_test_basic9(void)
{
	LIST_CREATE(lst);
	lst_node_t	*ptr = NULL;

	ptr = lst_get(&lst, -12);
	ASSERT_EQ(ptr, NULL);
	PASS();
}

int	callback_test(lst_node_t *node, void *ptr)
{
	(void)ptr;
	printf("%p: %s\n", node, (char *)node->content);
	return (0);
}

TEST	list_test_basic10(void)
{
	const char	*strs[0x3] = {
		"hello",
		"world",
		"toto"
	};

	LIST_CREATE(lst);
	lst_node_t	*ptr = NULL;
	for (size_t i = 0; i < 0x100; i++) {
		ptr = lst_node_new((void *)strs[i % 3]);
		lst_push_back(&lst, ptr);
	}
	lst_iter(&lst, callback_test, NULL);
	lst_free(&lst);
	ASSERT_EQ(lst.lst, NULL);
	PASS();
}

TEST	list_test_basic11(void)
{
	lst_node_t	*a = NULL, *b = NULL;

	a = lst_node_new((unsigned long*)0x1337);
	ASSERT_NEQ(a, NULL);
	b = lst_node_new((unsigned long*)0x666);
	ASSERT_NEQ(b, NULL);

	ASSERT_EQ(a->content, (unsigned long*)0x1337);
	ASSERT_EQ(b->content, (unsigned long*)0x666);

	lst_swap(a, b);
	ASSERT_EQ(a->content, (unsigned long*)0x666);
	ASSERT_EQ(b->content, (unsigned long*)0x1337);

	lst_free_node(&a);
	lst_free_node(&b);

	PASS();
}

TEST	list_test_basic12(void)
{
	LIST_CREATE(lst1);
	LIST_CREATE(lst2);
	LIST_CREATE(lst3);

	lst_node_t	*t1 = NULL, *t2 = NULL;
	size_t		i = 0;

	for (i = 0; i < 5; i++) {
		t1 = lst_node_new((unsigned long *)i);
		ASSERT_NEQ(t1, NULL);
		lst_push_back(&lst1, t1);
		ASSERT_EQ(lst1.last, t1);
	}

	ASSERT_EQ(lst1.len, 5);

	for (i = 0; i < 3; i++) {
		t1 = lst_node_new((unsigned long*)(i + 0x1337));
		ASSERT_NEQ(t1, NULL);
		lst_push_back(&lst2, t1);
		ASSERT_EQ(lst2.last, t1);
	}

	lst_copy(&lst2, &lst1);
	ASSERT_EQ(lst2.len, lst1.len);

	t1 = lst1.lst; t2 = lst2.lst;

	for (i = 0; i < 5; i++) {
		ASSERT_EQ(t1->content, t2->content);
		t1 = t1->next;
		t2 = t2->next;
	}

	lst_copy(&lst3, &lst1);
	ASSERT_EQ(lst3.len, lst1.len);

	t1 = lst3.lst; t2 = lst1.lst;

	for (i = 0; i < 5; i++) {
		ASSERT_EQ(t1->content, t2->content);
		t1 = t1->next;
		t2 = t2->next;
	}

	lst_free(&lst1);
	lst_free(&lst2);
	lst_free(&lst3);
	ASSERT_EQ(lst1.lst, NULL);
	ASSERT_EQ(lst2.lst, NULL);
	ASSERT_EQ(lst3.lst, NULL);

	PASS();
}

TEST	list_test_basic13(void)
{
	LIST_CREATE(lst);
	lst_node_t	*ptr = NULL;
	lst_node_t	*begin = NULL;
	lst_node_t	*end = NULL;

	for (size_t i = 0; i < 5; i++) {
		ptr = lst_node_new((unsigned long*)i);
		ASSERT_NEQ(ptr, NULL);
		lst_push_back(&lst, ptr);
		ASSERT_EQ(lst.last, ptr);
	}

	begin = lst_begin(&lst);
	end = lst_end(&lst);

	ASSERT_EQ(lst.lst, begin);
	ASSERT_EQ(lst.last, end);

	lst_free(&lst);

	PASS();
}

TEST	list_test_basic14(void)
{
	LIST_CREATE(lst);
	lst_t		*na = NULL;
	lst_node_t	*ptr = NULL, *tmp = NULL;
	size_t		i = 0;

	for (i = 0; i < 10; i++) {
		ptr = lst_node_new((size_t*)i);
		lst_push_back(&lst, ptr);
	}

	na = lst_dup(&lst);
	tmp = na->lst;
	ptr = lst.lst;
	ASSERT_NEQ(na, NULL);
	ASSERT_EQ(na->len, lst.len);

	for (i = 0; i < 10; i++) {
		ASSERT_EQ(ptr->content, tmp->content);
		ptr = ptr->next;
		tmp = tmp->next;
	}

	lst_free(&lst);
	lst_free(na);
	free(na);
	PASS();
}

#endif
