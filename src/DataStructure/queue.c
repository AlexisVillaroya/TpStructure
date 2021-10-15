/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

/**
 * @brief Initilise l'index de la queue à zéro
 * 
 * @param
 * 
 * */

void init_queue(Queue *s){
    s->index = 0;
}

/**
 * @brief Rajoute un élément à la queue
 * 
 * @param
 * @param
 * 
 * */

void enqueue(Queue *q, float value){
    if(q->index == 100){
        printf("La queue est remplit");
    }else{
        q->data[q->index] = value;
        q->index++;
    }
}

/**
 * @brief Renvoie le
 * 
 * @param
 * 
 * */

float dequeue(Queue *q){
    float element = 0;

    if(q->data[0] != 0){
        element = q->data[q->index-1];
        q->index--;
    }
    return element;
}

/**
 * @brief 
 * 
 * @param
 * 
 * */

bool is_queue_empty(Queue *q){
    return q->index == 0;
}

/**
 * @brief 
 * 
 * @param
 * 
 * */

float front(Queue *q){
    return q->data[q->index+1];
}

/**
 * @brief 
 * 
 * @param
 * 
 * */

void clear(Queue *q){
    init_queue(q);
}