#ifndef FLEXARR_H
#define FLEXARR_H

#include <stdbool.h>
#define T int

typedef struct {
    int *arr;
    int size;
    int capacity;
} FlexArr;

FlexArr* createFlexArr();

void destroyFlexArr(FlexArr* A);

int getSizeFA(FlexArr* A);

int getCapacityFA(FlexArr* A);

T getElementFA(FlexArr* A, int index);

void insertElementFA(FlexArr* A, int index, T data);

void deleteElementIndexFA(FlexArr* A, int index);

void setElementFA(FlexArr* A, int index, T value);

int searchElementFA(FlexArr* A, T value);

void deleteOneElementFA(FlexArr* A, T value);

void deleteAllElementFA(FlexArr* A, T value);

void printFA(FlexArr* A);

#endif