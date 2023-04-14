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
	node_t	*ptr[0x10];
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

TEST	node_test_push_back(void)
{
	node_t	*ptr[0x10];
	node_t	*lst = NULL;
	size_t i = 0;

	for (i = 0; i < sizeof(ptr)/sizeof(node_t*); i++) {
		ptr[i] = node_new((int *)i);
		ASSERT_NEQ(ptr[i], NULL);
		ASSERT_EQ(ptr[i]->content, (int *)i);
	}

	for (i = 0; i < sizeof(ptr)/sizeof(node_t*); i++) {
		node_push_back(&lst, ptr[i]);
		ASSERT_EQ(node_get_last(lst), ptr[i]);
	}

	node_free_all(&lst);
	PASS();
}

TEST	node_test_push_back2(void)
{
	node_t	*ptr[0x10];
	node_t	*lst = NULL;
	node_t	*tmp = NULL;
	size_t i = 0;
	size_t size = 0;
	index_t	idx = 0;

	for (i = 0; i < sizeof(ptr)/sizeof(node_t*); i++) {
		ptr[i] = node_new((int *)i);
		ASSERT_NEQ(ptr[i], NULL);
		ASSERT_EQ(ptr[i]->content, (int *)i);
	}

	for (i = 0; i < sizeof(ptr)/sizeof(node_t*); i++) {
		node_push_back(&lst, ptr[i]);
		ASSERT_EQ(node_get_last(lst), ptr[i]);
	}

	tmp = lst;

	for (i = 0; i < sizeof(ptr)/sizeof(node_t*); i++) {
		ASSERT_EQ(tmp, ptr[i]);
		ASSERT_EQ(tmp->prev, ptr[i]->prev);
		ASSERT_EQ(tmp->next, ptr[i]->next);
		ASSERT_EQ(tmp->content, ptr[i]->content);
		tmp = tmp->next;
	}

	tmp = node_get_last(lst);
	size = node_get_size(lst);
	idx = size - 1; 

	while (idx >= 0 && idx < size) {
		ASSERT_EQ(tmp, ptr[idx]);
		ASSERT_EQ(tmp->content, ptr[idx]->content);
		ASSERT_EQ(tmp->prev, ptr[idx]->prev);
		ASSERT_EQ(tmp->next, ptr[idx]->next);
		tmp = tmp->prev;
		idx--;
	}

	node_free_all(&lst);
	PASS();
}

TEST	node_test_push2(void)
{
	node_t	*ptr[0x10];
	node_t	*lst = NULL;
	node_t	*tmp = NULL;
	size_t i = 0;
	size_t size = 0;
	index_t	idx = 0;

	for (i = 0; i < sizeof(ptr)/sizeof(node_t*); i++) {
		ptr[i] = node_new((int *)i);
		ASSERT_NEQ(ptr[i], NULL);
		ASSERT_EQ(ptr[i]->content, (int *)i);
	}

	for (i = 0; i < sizeof(ptr)/sizeof(node_t*); i++) {
		node_push(&lst, ptr[i]);
		ASSERT_EQ(lst, ptr[i]);
		ASSERT_EQ(lst->content, ptr[i]->content);
		ASSERT_EQ(lst->prev, ptr[i]->prev);
		ASSERT_EQ(lst->next, ptr[i]->next);
	}

	tmp = lst;
	size = node_get_size(lst);
	idx = size - 1; 

	while (idx >= 0 && idx <= size) {
		ASSERT_EQ(tmp, ptr[idx]);
		ASSERT_EQ(tmp->content, ptr[idx]->content);
		ASSERT_EQ(tmp->prev, ptr[idx]->prev);
		ASSERT_EQ(tmp->next, ptr[idx]->next);
		tmp = tmp->next;
		idx--;
	}

	node_free_all(&lst);
	PASS();
}

TEST	node_test_pop(void)
{
	node_t	*ptr[0x10];
	node_t	*lst = NULL, *last = NULL, *next = NULL;
	size_t	i = 0;

	for (i = 0; i < sizeof(ptr)/sizeof(node_t*); i++) {
		ptr[i] = node_new((int *)i);
		ASSERT_NEQ(ptr[i], NULL);
		ASSERT_EQ(ptr[i]->content, (int *)i);
	}

	for (i = 0; i < sizeof(ptr)/sizeof(node_t*); i++) {
		node_push_back(&lst, ptr[i]);
		last = node_get_last(lst);
		ASSERT_EQ(last, ptr[i]);
		ASSERT_EQ(last->content, ptr[i]->content);
	}

	for (i = 0; i < sizeof(ptr)/sizeof(node_t*); i++) {
		next = lst->next;
		node_pop(&lst);
		ASSERT_EQ(lst, next);
		if (lst) ASSERT_EQ(lst->prev, NULL);
	}

	ASSERT_EQ(lst, NULL);

	node_free_all(&lst);

	PASS();
}

TEST	node_test_pop2(void)
{
	node_t	*ptr[0x10];
	node_t	*lst = NULL, *last = NULL;
	size_t	i = 0;

	for (i = 0; i < sizeof(ptr)/sizeof(node_t*); i++) {
		ptr[i] = node_new((int *)i);
		ASSERT_NEQ(ptr[i], NULL);
		ASSERT_EQ(ptr[i]->content, (int *)i);
	}

	for (i = 0; i < sizeof(ptr)/sizeof(node_t*); i++) {
		node_push_back(&lst, ptr[i]);
		last = node_get_last(lst);
		ASSERT_EQ(last, ptr[i]);
		ASSERT_EQ(last->content, ptr[i]->content);
	}

	for (i = 0; i < sizeof(ptr)/sizeof(node_t*); i++) {
		last = node_get_last(lst);
		if (last) {
			node_pop_back(&lst);
			ASSERT_NEQ(node_get_last(lst), last);
		}
	}

	ASSERT_EQ(lst, NULL);

	node_free_all(&lst);

	PASS();
}

TEST	node_test_free_all(void)
{
	node_t	*tmp = NULL;
	node_t	*lst = NULL;

	for (int i = 0; i < 0x100; i++) {
		tmp = node_new_empty();
		node_push(&lst, tmp);
	}

	node_free_all(&lst);
	ASSERT_EQ(lst, NULL);
	PASS();
}

TEST	node_test_get(void)
{
	const char	*hellostr = "hello";
	node_t	*lst = NULL;
	node_t	*tmp = NULL, *toget = NULL;
	size_t	i = 0;

	for (i = 0; i < 0x100; i++) {
		if (i == 55) {
			tmp = node_new((char*)hellostr);
			ASSERT_NEQ(tmp, NULL);
			ASSERT_STR_EQ(hellostr, tmp->content);
		} else {
			tmp = node_new((int *)i);
			ASSERT_NEQ(tmp, NULL);
			ASSERT_EQ(tmp->content, (int *)i);
		}
		node_push_back(&lst, tmp);
	}

	toget = node_get(lst, 55);

	ASSERT_NEQ(toget, NULL);
	ASSERT_EQ(toget->content, hellostr);

	node_free_all(&lst);
	ASSERT_EQ(lst, NULL);

	PASS();
}

TEST	node_test_remove(void)
{
	const char	*hellostr = "hello";
	node_t	*lst = NULL;
	node_t	*tmp = NULL, *toget = NULL, *save = NULL;
	size_t	i = 0;

	for (i = 0; i < 0x100; i++) {
		if (i == 55) {
			tmp = node_new((char*)hellostr);
			ASSERT_NEQ(tmp, NULL);
			ASSERT_STR_EQ(hellostr, tmp->content);
		} else {
			tmp = node_new((int *)i);
			ASSERT_NEQ(tmp, NULL);
			ASSERT_EQ(tmp->content, (int *)i);
		}
		node_push_back(&lst, tmp);
	}
	
	save = node_get(lst, 55);

	node_remove(&lst, 55);

	toget = node_get(lst, 55);

	ASSERT_NEQ(toget, save);

	node_free_all(&lst);
	ASSERT_EQ(lst, NULL);

	PASS();
}

TEST	node_test_remove2(void)
{
	node_t	*first = NULL, *second = NULL, *third = NULL;

	first = node_new("hello");
	second = node_new("world");
	third = node_new("ivoxygen");

	ASSERT_NEQ(first, NULL);
	ASSERT_NEQ(second, NULL);
	ASSERT_NEQ(third, NULL);

	node_push_back(&first, second);
	node_push_back(&first, third);

	node_remove(&first, 1);

	ASSERT_EQ(first->next, third);
	
	node_free_all(&first);

	PASS();
}

TEST	node_test_remove3(void)
{
	node_t	*first = NULL;

	first = node_new("hello");

	node_remove(&first, 0);

	ASSERT_EQ(first, NULL);

	PASS();
}

TEST	node_test_insert(void)
{
	node_t	*first = NULL, *second = NULL, *third = NULL;
	node_t	*four = NULL;

	first = node_new("hello");
	second = node_new("world");
	third = node_new("toto");
	four = node_new("tata");

	ASSERT_NEQ(first, NULL);
	ASSERT_NEQ(second, NULL);
	ASSERT_NEQ(third, NULL);
	ASSERT_NEQ(four, NULL);

	node_push_back(&first, second);
	node_push_back(&first, third);
	node_insert(&first, four, 1);
	ASSERT_EQ(first->next, four);
	node_free_all(&first);
	PASS();
}

TEST	node_test_insert2(void)
{
	node_t	*first = NULL;
	node_t	*lst = NULL;

	first = node_new("hello world");
	ASSERT_NEQ(first, NULL);

	node_insert(&lst, first, 0);
	ASSERT_EQ(lst, first);
	node_free_all(&lst);
	PASS();
}

TEST	node_test_insert3(void)
{
	node_t	*first = NULL;
	node_t	*lst = NULL;

	first = node_new("mdr");
	ASSERT_NEQ(first, NULL);
	node_insert(&lst, first, 234);
	ASSERT_EQ(lst, first);
	node_free_all(&lst);
	PASS();
}

#endif
