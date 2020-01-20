#include "postfix.h"

int main(void) {
	char exp[] = "( 3 + (4 + 5  ) * 6)";
	char* tmp;
	Stack s;
	int res;
	printf("* original exp : \"%s\"\n", exp);
	init(&s, exp);
	tmp = toPostfix(&s, exp);
	printf("* postfix exp : \"%s\"\n", tmp);
	init(&s, tmp);
	res = calPostfix(&s, tmp);
	printf("* operation result : %d\n", res);
	return 0;
}
