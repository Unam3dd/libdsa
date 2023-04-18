#include "defs.h"
#include "node_test.h"

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

int main(int argc, char **argv)
{
	GREATEST_MAIN_BEGIN();
	RUN_SUITE(node_tests);
	GREATEST_MAIN_END();
	return (0);
}
