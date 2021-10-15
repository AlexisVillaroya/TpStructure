#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "DataStructure/stack.h"
#include "DataStructure/queue.h"
#include "DataStructure/array_list.h"

void test_stack(Stack *s);
void test_queue();
void test_array();

int main(int argc, char** argv) {
    //test_queue();
    // float a=0.0f;
    // Stack *s = malloc(sizeof(Stack));
    // test_stack(s);
    test_array();
    //test_heap();
    float a=0.0f;
    Stack *s = malloc(sizeof(Stack));
    //test_stack(s);
    return (EXIT_SUCCESS);
}

void test_array(){
    Array_list *l = malloc(sizeof(Array_list));
    init_array_list(l);
    assert(l->index == 0);
    add(l, 1.0);
    assert(l->data[0] == 1.0);
    add(l, 2.0);
    assert(l->data[1] == 2.0);
    add(l, 3.0);
    assert(l->data[2] == 3.0);
    assert(l->index == 3);
    insert_at(l, 2, 13.0);
    assert(l->data[1] == 13.0);
    assert(l->data[2] == 2.0);
    remove_at(l, 2);
    //assert(l->data[2] == 2);
    //assert(get_at(l, 2) == 2);
    for (size_t i = 0; i < 5; i++)
    {
        printf("%f ", l->data[i]);
    }
    printf("Test réussi\n");
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

    printf("#  TEST UNITAIRES EFFECTUES AVEC SUCCES SUR QUEUE.C  #\n");
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
    printf("#  TEST UNITAIRES EFFECTUES AVEC SUCCES SUR STACK.C  #\n");

}