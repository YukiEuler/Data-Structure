#ifndef FLEXARR_C
#define FLEXARR_C

#include <stdlib.h>
#include <stdbool.h>
#include "FlexArr.h"

FlexArr* createFlexArr(){
    FlexArr* A = (FlexArr*) malloc(sizeof(FlexArr));
    if (A == NULL){
        printf("Allocation of FlexArr failed!");
        exit(EXIT_FAILURE);
    }
    T* arr = (T*) malloc(sizeof(T));
    if (arr == NULL){
        printf("Allocation of FlexArr failed!");
        exit(EXIT_FAILURE);
    }
    A->arr = arr;
    A->size = 0;
    A->capacity = 1;
    return A;
}

void resizeFlexArr(FlexArr* A){
    T* new = (T*) malloc(2 * A->capacity * sizeof(T));
    if (A->arr == NULL){
        printf("Reallocation of FlexArr failed!");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < A->capacity; i++){
        new[i] = A->arr[i];
    }
    T* temp = A->arr;
    A->arr = new;
    A->capacity *= 2;
    free(temp);
}

void destroyFlexArr(FlexArr* A){
    free(A->arr);
    free(A);
}

int getSizeFA(FlexArr* A){
    return A->size;
}

int getCapacityFA(FlexArr* A){
    return A->capacity;
}

T getElementFA(FlexArr* A, int index){
    if (index < 0 || index >= getSizeFA(A)){
        printf("Index out of bounds!");
        exit(EXIT_FAILURE);
    }
    return A->arr[index];
}

void insertElementFA(FlexArr* A, int index, T data){
    if (index < 0 || index >= getSizeFA(A) + 1){
        printf("Index out of bounds!");
        exit(EXIT_FAILURE);
    }
    if (getSizeFA(A) == getCapacityFA(A)){
        resizeFlexArr(A);
    }
    for (int i = getSizeFA(A); i > index; i--){
        A->arr[i] = A->arr[i-1];
    }
    A->arr[index] = data;
    A->size++;
}

void deleteElementIndexFA(FlexArr* A, int index){
    if (index < 0 || index >= getSizeFA(A)){
        printf("Index out of bounds!");
        exit(EXIT_FAILURE);
    }
    for (int i = index; i < getSizeFA(A)-1; i++){
        A->arr[i] = A->arr[i+1];
    }
    A->size--;
}

void setElementFA(FlexArr* A, int index, T value){
    if (index < 0 || index >= getSizeFA(A)){
        printf("Index out of bounds!");
        exit(EXIT_FAILURE);
    }
    A->arr[index] = value;
}

int searchElementFA(FlexArr* A, T value){
    for (int i = 0; i < getSizeFA(A); i++){
        if (getElementFA(A, i) == value){
            return i;
        }
    }
    return -1;
}

void deleteOneElementFA(FlexArr* A, T value){
    int idx = searchElementFA(A, value); 
    if (idx == -1){
        return;
    }
    deleteElementIndexFA(A, idx);
}

void deleteAllElementFA(FlexArr* A, T value){
    int idx = searchElementFA(A, value); 
    while (idx >= 0){
        deleteElementIndexFA(A, idx);
        idx = searchElementFA(A, value);
    }
}

// Note: Change print format specifier for different T
void printFA(FlexArr* A){
    for (int i = 0; i < getSizeFA(A); i++){
        printf("%d ", getElementFA(A, i));
    }
    printf("\n\n");
}

#endif