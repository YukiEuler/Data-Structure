#include <stdio.h>
#include "FlexArr.c"

int main(){
    FlexArr* A = createFlexArr();

    printf("Inserting 5, 10, ..., 100\n");
    for (int i = 5; i <= 100; i += 5){
        insertElementFA(A, getSizeFA(A), i);
    }
    printFA(A);

    printf("Inserting 1 in even index\n");
    for (int i = 0; i < 10; i++){
        insertElementFA(A, 2*i, 1);
    }
    printFA(A);

    printf("Delete one element 1\n");
    deleteOneElementFA(A, 1);
    printFA(A);

    printf("Delete all element 1\n");
    deleteAllElementFA(A, 1);
    printFA(A);

    printf("Set last element to 1000\n");
    setElementFA(A, getSizeFA(A)-1, 1000);
    printFA(A);

    printf("Size of FlexArr: %d\n", getSizeFA(A));
    printf("Capacity of FlexArr: %d\n", getCapacityFA(A));
    
    destroyFlexArr(A);
}