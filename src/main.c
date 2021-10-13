#include <stdio.h>
#include <stdbool.h>
#include "DataStructure/stack.h"
void test_stack(Stack *s);

int main()
{
	printf("Hello World!\n");
	Stack *s;
	test_stack(s);
	return (0);
}

void test_stack(Stack *s){
	init_stack(s);
	push(s, 5.0);
	pop(s);
	is_stack_empty(s);
	peek(s);
	dup(s);
	swap(s);
	clear(s);
}