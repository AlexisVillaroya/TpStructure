#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "DataStructure/stack.h"
#include "DataStructure/queue.h"
#include "DataStructure/array_list.h"
#include "DataStructure/heap.h"

void test_stack(Stack *s);
void test_heap(Heap *h);
void test_queue();
void test_array();

int main(int argc, char** argv) {
    // test_queue();
    // test_array();
    // test_heap();
    // Stack *s = malloc(sizeof(Stack));
    //test_stack(s);
    Heap *h = malloc(sizeof(Heap));
    test_heap(h);

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

void test_heap(Heap *h){

	init_heap(h);
    assert(h->index == -1);
    assert(is_heap_empty(h) == 1);
	pushHeap(h, 5.0f);
	pushHeap(h, 12.3f);
	pushHeap(h, 1.3f);
	pushHeap(h, 23.3f);
	pushHeap(h, 7.63f);
    for(int i=0; i<=h->index;i++){
        printf(" %f ", h->data[i]);
    }
    assert(h->data[h->index] == 5.0f);
    assert(h->data[h->index-1] == 12.3f);
    assert(h->data[h->index-2] == 1.3f);
    assert(h->data[h->index-3] == 23.3f);
    assert(h->data[h->index-4] == 7.63f);
	pop(h);
    assert(h->data[0] == 5.0f);
    assert(h->data[1] == 7.63f);
    assert(h->data[2] == 12.3f);
    assert(h->data[3] == 23.3);
    assert(is_heap_empty(h) == 0);
    assert(peek(h) == 5.0);
	replace(h, 56.0f);
    assert(peek(h) == 7.63);
    printf("#  TEST UNITAIRES EFFECTUES AVEC SUCCES SUR HEAP.C  #\n");

}