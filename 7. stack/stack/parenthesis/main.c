#include "stack.h"

int main(void) {
	char *test = " (  ( )  ( { } ) ) ";
	char *test2 = " (   ( ) ( { ) ) ";

	check(test);
	check(test2);
	return 0;
}
