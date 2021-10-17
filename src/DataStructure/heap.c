/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include "heap.h"

void init_heap(Heap *h){
    h->index = -1;
}
bool is_heap_empty(Heap *h){
    if(h->index == -1){
        return true;
    }
    return false;
}
float popHeap(Heap *h){
    h->data[0] = INT_MAX;
    heapSort(h, h->index);
    h->index--;
} //pop the root value
void pushHeap(Heap *h, float value){
    h->index++;
    h->data[h->index] = value;
    heapSort(h, h->index);
}
float replace(Heap *h, float value){
    popHeap(h);
    pushHeap(h, value);
} // pop root and push a new key.
float peekHeap(Heap *h){
    return h->data[0];
}// return root value but dont remove it

void selfHeapify(Heap *h, int nodeIndex){
    int leftChild = 2 * nodeIndex + 1; // Formule de calul de l'indice de la branche gauche du noeud
    int rightChild = 2 * nodeIndex + 2; // Formule de calul de l'indice de la branche droite du noeud
    int highestElement = nodeIndex; // Indice du parent du noeud souhaité

    if (leftChild <= h->index && h->data[leftChild] > h->data[highestElement]){
        highestElement = leftChild;
    }
 

    if (rightChild <= h->index && h->data[rightChild] > h->data[highestElement]){
        highestElement = rightChild;
    }
    

    if (highestElement != nodeIndex) {
        float temp = h->data[nodeIndex];
        h->data[nodeIndex] = h->data[highestElement];
        h->data[highestElement] = temp;
 

        selfHeapify(h, nodeIndex);
    }
} // Trie un noeud de l'arbre

void heapSort(Heap *h, int nodeIndex){
    for(int i = h->index /2 -1; i>=0; i--){
        selfHeapify(h, nodeIndex);
    }

    for(int i = nodeIndex - 1; i>=0;i--){
        float temp = h->data[0];
        h->data[0] = h->data[i];
        h->data[i] = temp;
        selfHeapify(h, 0);
        printf("Tas à cette étape : %f \n", h->data[i]) ;
    }
}

//En option
void heapify(Heap *s, float array[], size_t array_size){

} // Heapify from array
void merge(Heap *dest, Heap *src){
    
}//merge src into dest
