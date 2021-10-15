#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "DataStructure/stack.h"
#include "DataStructure/queue.h"

void test_stack(Stack *s);
void test_queue();

int main(int argc, char** argv) {
    test_queue();
    return (EXIT_SUCCESS);
}

void test_queue(){
    
    Queue *q = malloc(sizeof(Queue));
	init_queue(q);
	assert(q->index == 0);
	assert(is_queue_empty(q) == true);
	enqueue(q, 3);
    assert(q->data[0] == 3);
	enqueue(q, 2);
    assert(q->data[1] == 2);
    assert(q->index == 2);
	assert(front(q) == 0);
	assert(is_queue_empty(q) == false);
	dequeue(q);
	assert(q->index == 1);
	clear(q);
	assert(q->index == 0);
}	

// void test_stack(Stack *s){
// 	init_stack(s);
// 	push(s, 5.0);
// 	pop(s);
// 	is_stack_empty(s);
// 	peek(s);
// 	dup(s);
// 	swap(s);
// 	cls(&s);
// }