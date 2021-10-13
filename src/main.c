#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "DataStructure/stack.h"
#include "DataStructure/queue.h"

float test(int a) {
    //errno = a;
    assert(a == 5);
    //int errnum = errno;
    //fprintf(stderr, "Value of errno: %d\n", errnum);
    perror("Error printed by perror");
    //fprintf(stderr, "Error opening file: %s\n", strerror(errnum));

}

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
    //assert(q.data[0] == 15);

    for(int i=100; i > 0; i--){
        printf("%.01f ", q.data[i]);
    }

    printf("%.01f ", q.data[0]);
    printf("%.01f\n", q.data[1]);
    dequeue(&q);
    assert(q.index == 1);
    printf("%.01f\n", q.data[0]);
    printf("Tous c'est bien passé !\n");	
}