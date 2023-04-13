#include "defs.h"
#include "node_test.h"

SUITE(node_tests)
{
	RUN_TEST(node_new_test);
}

int main(int argc, char **argv)
{
	GREATEST_MAIN_BEGIN();
	RUN_SUITE(node_tests);
	GREATEST_MAIN_END();
	return (0);
}
