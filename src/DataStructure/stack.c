/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "stack.h"
#include <limits.h>

// Initialise la pile
void init_stack(Stack *s){
    s->index = -1;
}

// Ajoute un élément à la pile en incrémentant son index conséquent
void push(Stack *s, float value){
    s->index++;
    s->data[s->index] = value;
}

//Supprime un élément de la pile en décrémentant son index conséquent
float pop(Stack *s){
    if(is_stack_empty(s)){
        return INT_MIN;
    }
    s->index--;
    return s->data[s->index];
}

//Renvoie 1 si VRAI, 0 si FAUX
bool is_stack_empty(Stack *s){
    return s->index == -1;
}

//Renvoie l'élément au sommet de la pile
float peek(Stack *s){
    if(is_stack_empty(s)){
        return INT_MIN;
    }
    return s->data[s->index];
} // aka top or front

//Copie le dernier élément de la pile et l'ajoute à la fin de cette dernière
void dup(Stack *s){
    push(s, peek(s));
}

//Echange le dernier élément n avec l'élément n-1
void swap(Stack *s){
    float temp = s->data[s->index];
    s->data[s->index] = s->data[s->index-1];
    s->data[s->index-1] = temp;
}

//Réinitialise la pile 
void cls(Stack *s){
    init_stack(s);
}