#ifndef TLIST_TEST_H
#define TLIST_TEST_H

#include "greatest/greatest.h"
#include "tlist.h"

TEST	tlist_basic_create(void)
{
	TLIST(int, myint);
	TLIST(double, mydouble);
	TLIST(char*, mycharptr);
	TLIST(short, myshort);
	TLIST(struct { char *name; int age; }, persons);
	PASS();
}

#endif
