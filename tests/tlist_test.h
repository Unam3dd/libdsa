#ifndef TLIST_TEST_H
#define TLIST_TEST_H

#include "greatest/greatest.h"
#include "tlist.h"
#include <string.h>

#define MAX_PLAYER 0x20

typedef enum	player_class_t	player_class_t;

enum player_class_t {
	WARRIOR,
	VILLAGER,
	WITCHER,
	SPY
};

TEST	tlist_basic_create(void)
{
	TLIST(int, myint);
	TLIST(double, mydouble);
	TLIST(char*, mycharptr);
	TLIST(short, myshort);
	TLIST(struct { char *name; int age; }, persons);
	PASS();
}

TEST	tlist_basic_type(void)
{
	TLIST_TYPE(unsigned int, myint);
	TLIST_TYPE(const char *, name);
	TLIST_TYPE(struct { const char *name; unsigned short age; }, person);
	
	TLIST_T(myint, test, 0xdeadbeef);
	TLIST_T_(person, test1);

	TLIST_T_(person, test2);
	TLIST_T(name, testname, "bob");

	test1._data.name = "sam";
	test1._data.age = 20;
	
	test2._data.name = "john";
	test2._data.age = 21;

	ASSERT_EQ(test._data, 0xdeadbeef);

	ASSERT_EQ(strcmp(test1._data.name, "sam"), 0);
	ASSERT_EQ(test1._data.age, 0x14);
	
	ASSERT_EQ(strcmp(testname._data, "bob"), 0);

	ASSERT_EQ(test2._data.age, 21);
	ASSERT_EQ(strcmp(test2._data.name, "john"), 0);

	PASS();
}

TEST	tlist_basic_test1(void)
{
	TLIST_TYPE(struct info {
				const char 		*name; 
				unsigned int	id;
				unsigned short	age;
				player_class_t	class;
				}, player);

	TLIST_NEW_STACK_(player, players[MAX_PLAYER]);
	TLIST_NEW_STACK_(player, zero);

	unsigned int i = 0;

	memset(&zero, 0, sizeof(player));
	
	for (i = 0; i < MAX_PLAYER; i++)
		TLIST_ZERO_S(players);

	for (i = 0; i < MAX_PLAYER; i++)
		ASSERT_EQ(memcmp(&players[i], &zero, sizeof(player)), 0);

	PASS();
}

#endif
