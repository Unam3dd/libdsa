#include "defs.h"
#include "node_test.h"
#include "list_test.h"
#include "tlist_test.h"

SUITE(node_tests)
{
	RUN_TEST(node_new_test);
	RUN_TEST(node_new_void);
	RUN_TEST(node_free_test1);
	RUN_TEST(node_test_push);
	RUN_TEST(node_test_push_back);
	RUN_TEST(node_test_push_back2);
	RUN_TEST(node_test_push2);
	RUN_TEST(node_test_pop);
	RUN_TEST(node_test_pop2);
	RUN_TEST(node_test_free_all);
	RUN_TEST(node_test_get);
	RUN_TEST(node_test_remove);
	RUN_TEST(node_test_remove2);
	RUN_TEST(node_test_remove3);
	RUN_TEST(node_test_insert);
	RUN_TEST(node_test_insert2);
	RUN_TEST(node_test_insert3);
	RUN_TEST(node_test_cmp);
	RUN_TEST(node_mega_test);
}

SUITE(list_tests)
{
	RUN_TEST(list_test_basic1);
	RUN_TEST(list_test_basic2);
	RUN_TEST(list_test_basic3);
	RUN_TEST(list_test_basic4);
	RUN_TEST(list_test_basic5);
	RUN_TEST(list_test_basic6);
	RUN_TEST(list_test_basic7);
	RUN_TEST(list_test_basic8);
	RUN_TEST(list_test_basic9);
	RUN_TEST(list_test_basic10);
	RUN_TEST(list_test_basic11);
	RUN_TEST(list_test_basic12);
	RUN_TEST(list_test_basic13);
	RUN_TEST(list_test_basic14);
}

SUITE(tlist_tests)
{
	RUN_TEST(tlist_basic_create);
	RUN_TEST(tlist_basic_type);
	RUN_TEST(tlist_basic_test1);
}

int main(int argc, char **argv)
{
	GREATEST_MAIN_BEGIN();
	RUN_SUITE(node_tests);
	RUN_SUITE(list_tests);
	RUN_SUITE(tlist_tests);
	GREATEST_MAIN_END();
	return (0);
}
