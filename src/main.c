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
	Queue q;
    clear(&q);
    init_queue(&q);
    assert(q.index == 0);
    enqueue(&q, 254);
    assert(q.data[0] == 254);
    enqueue(&q, 15);
    assert(q.data[1] == 15);

    printf("%.01f ", q.data[0]);
    printf("%.01f\n", q.data[1]);
    dequeue(&q);
    assert(q.index == 1);
    dequeue(&q);
    assert(q.index == 0);
    printf("%.01f\n", q.data[0]);

    for(int i=100; i > 0; i--){
        printf("%.01f ", q.data[i]);
    }

    printf("Tout s'est bien passé !\n");
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