#include "function.h"
#include <iostream>

int Add(int a, int b) {
	g_iExtern += 30;
	printf("%d", g_iExtern);
	return a + b;
}