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
}

int main(int argc, char **argv)
{
	GREATEST_MAIN_BEGIN();
	RUN_SUITE(node_tests);
	GREATEST_MAIN_END();
	return (0);
}
