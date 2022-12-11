#include <stdio.h>
#include <stdlib.h>

// QUEUE = FIFO (FIRST IN FIRST OUT)

// Queue with double linked list
struct Node{
    int value;
    Node *next, *prev;
};

Node *first, *last; // store the address of the very first and last element in Queue

Node *createNode(int value){
    Node *newNode = (Node *)malloc(sizeof(Node));

    newNode -> value = value;
    newNode -> next = newNode->prev = NULL;

    return newNode;
}

void pushQueue(int value){ //enqueue
    Node *temp = createNode(value);
    if(!first){ //kalau gak ada first, berarti new node = first
        first = last = temp;
    }
    else if(!first->prev){ // jika hanya ada 1 node (first->prev == NULL)
        first->prev = temp;
        temp->next = first;
        last = temp;
    }
    else{ // lebih dari 1 node
        last->prev = temp;
        temp->next = last;
        last = temp;
    }
}

void popQueue(){ //dequeue
    if(!first){ // kalau gak ada elemen sama sekali
        return ;
    }
    else if(!first->prev){ // kalau cuman ada 1 elemen
        free(first);
        first = last = NULL;
    }
    else{ // kalau ada lebih dari 1
        Node *newFirst = first->prev; 
        first->prev = newFirst ->next = NULL; 
        free(first); 
        first = newFirst; 
    }
}

void firstQueue(){
    printf("First in the queue is %d\n", first->value);
}



int main(){
    pushQueue(1);
    pushQueue(5);
    pushQueue(9);
    pushQueue(4);
    pushQueue(14);
    pushQueue(19);
    pushQueue(12);
    pushQueue(7);
    pushQueue(98);
    pushQueue(67);
    pushQueue(52);
    pushQueue(45);
    pushQueue(40);
    pushQueue(28);
    pushQueue(17);

    firstQueue(); // return 1
    popQueue(); // 1 -> 5 (new first)
    popQueue(); // 5 -> 9 (new first)
    popQueue(); // 9 -> 4 (new first)
    firstQueue(); // return 4

    popQueue(); // 4 -> 14
    firstQueue(); // return 14



    return 0;
}