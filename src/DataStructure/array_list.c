/**
 * Auteur : Alexis Villaroya et Roman Lecomte
 * */

#include <stdio.h>
#include "array_list.h"


/** @brief Initilisatioin de la liste (remet l'index à 0) 
 * 
 * @param l : liste à initialiser
 * 
 * */

void init_array_list(Array_list *l){
    l->index = 0;
}

/** @brief Insert une valeur dans un endroit spécifique de la liste 
 *
 * @param l : liste à remplir
 * @param position : position à laquelle insérer la valeur
 * @param value : valeur à insérer
 * 
 * */

void insert_at(Array_list *l, int position, float value){
    if(l->index < position){
        add(l, value);
    }else{
        for(int i = l->index; i >= position; i--)
            l->data[i] = l->data[i-1];
        l->data[position-1] = value;
    }    
}

/** @brief ajoute une valeur à la fin de la liste
 * 
 * @param l : liste à remplir
 * @param value : valeur à insérer
 * 
 * */

void add(Array_list *l, float value){
    l->data[l->index] = value;
    l->index++;
}

/** @brief enlève une valeur de la liste 
 * 
 * @param l : liste à vider
 * @param position : position à laquelle enlever la valeur
 * 
 * */

float remove_at(Array_list *l, int position){
    float temp;
    int i;
    for(i = position-1; i < l->index; i++){ 
        l->data[i] = l->data[i+1];
        l->data[i+1] = 0;       
    }
    l->index--;
    return 0;
}

/** @brief renvoie une valeur dans la liste
 * 
 * @param l : liste visée
 * @param position : position où rechercher la valeur 
 * 
 * */

float get_at(Array_list *l,int position){
    return l->data[position-1];
}

/** @brief réinitialise la liste
 * 
 * @param l : liste à réinitialiser
 * 
 * */

void clearl(Array_list *l){
    init_array_list(l);
}