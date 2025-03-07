#include <stdio.h>
int a;
int f() {
	return a++;
}

int main() {

	for (int i = 0; i < 3; i++)
	{
		printf("%d", f());
	}
	printf("%d", a);
	return 0;
}