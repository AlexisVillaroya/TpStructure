#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "DataStructure/stack.h"
#include "DataStructure/queue.h"

void test_stack(Stack *s);
void test_queue();

int main(int argc, char** argv) {
    //test_queue();
    float a=0.0f;
    Stack *s = malloc(sizeof(Stack));
    test_stack(s);
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

void test_stack(Stack *s){
	init_stack(s);
    assert(s->index == -1);
	push(s, 5.0f);
	push(s, 52.3f);
    assert(s->data[s->index-1] == 5.0f);
    assert(s->data[s->index] == 52.3f);
	pop(s);
    assert(s->data[s->index] == 5.0);
    assert(is_stack_empty(s) == 0);

    assert(peek(s) == 5.0);
	dup(s);
    assert(peek(s) == s->data[s->index-1]);
    push(s, 52.3);
	swap(s);
    assert(peek(s) == 5.0);
	cls(s);
    assert(is_stack_empty(s) == 1);
}