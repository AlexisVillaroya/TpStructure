/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <heap.h>

void init_heap(Heap *h){
    h->index = -1;
}
bool is_heap_empty(Heap *h){
    if(h->index == -1){
        return true;
    }
    return false;
}
float pop(Heap *h){
    h->data[0] = 0;
} //pop the root value
void push(Heap *h, float value){
    h->data[h->index] = value;
}
float replace(Heap *h, float value){
    pop(h);
    push(h, value);
} // pop root and push a new key.
float peek(Heap *h){
    return h->data[0];
}// return root value but dont remove it

void selfHeapify(Heap *h, int nodeIndex){
    int leftChild = 2 * nodeIndex + 1;
    int rightChild = 2 * nodeIndex + 2;
    int highestElement = nodeIndex;

    if (leftChild <= h->index && arr[leftChild] > arr[highestElement]){
        highestElement = leftChild;
    }
 

    if (rightChild <= h->index && h->data[rightChild] > h->data[highestElement]){
        highestElement = rightChild;
    }
    

    if (highestElement != nodeIndex) {
        swap(h->data[nodeIndex], h->data[highestElement]);
 

        heapify(h, nodeIndex);
    }
} // Trie un noeud de l'arbre
void heapSort(Heap *h, int nodeIndex){

    for (int i = h->index / 2 - 1; i >= 0; i--)
        heapify(h, nodeIndex);
 
    for (int i = h->index - 1; i > 0; i--) {

        swap(h->data[0], h->data[i]);
 
        heapify(h, 0);
    }
}
//En option
void heapify(Heap *s, float array[], size_t array_size){

} // Heapify from array
void merge(Heap *dest, Heap *src){
    
}//merge src into dest
