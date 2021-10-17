/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   heap.h
 * Author: aurelio
 *
 */

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef HEAP_H
#define HEAP_H


#define HEAP_MAX_SIZE 100

typedef struct {
    float data[HEAP_MAX_SIZE];
    int index;
} Heap;


#endif /* HEAP_H */

void init_heap(Heap *h);
bool is_heap_empty(Heap *h);
float popHeap(Heap *h); // Extrait la valeur de la racine
void pushHeap(Heap *h, float value);
float replace(Heap *h, float value); // Retire la valeur de la racine et ajoute une valeur à la place
float peekHeap(Heap *h); // Retourne la racine sans la retirer
void heapSort(Heap *h, int nodeIndex); // Trie de façon récursive les noeuds de l'arbre
void selfHeapify(Heap *h, int nodeIndex); // Trie un noeud spécifique de l'arbres

//En option
void heapify(Heap *s, float array[], size_t array_size); //create Heap from array
void merge(Heap *dest, Heap *src); //merge src into dest


