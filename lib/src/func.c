#include <stdio.h>
#include "func.h"

int func()
{
	LOG("%s\n", __func__);
	return 0;
}