#include <stdio.h>
#include <stdlib.h>

// Stack = LIFO (LAST IN FIRST OUT)

// stack with double linked list
struct Node{
    int value;
    Node *next, *prev; // next ke atas, prev ke bawah
};

Node *top; // store the address of very top element in stack

Node *createNode(int value){
    Node *newNode = (Node *)malloc(sizeof(Node));

    newNode -> value = value;
    newNode -> next = newNode->prev = NULL;

    return newNode;
}

void pushStack(int value){
    Node *temp = createNode(value);
    if(!top){ //kalau gak ada top, berarti new node = top
        top = temp;
    }
    else{ // jika ada lebih dari 1 node
        top->next = temp;
        temp->prev = top;
        top = temp;
    }
}

void popStack(){
    if(!top){ // kalau gak ada elemen sama sekali
        return ;
    }
    else if(!top->prev){ // kalau cuman ada 1 elemen
        // top -> prev, berarti bawahnya udah gak ada elemen
        free(top);
        top = NULL;
    }
    else{ // kalau ada lebih dari 1
        Node *newTop = top->prev; // candidate for newTop
        top->prev = newTop ->next = NULL; // isolate node
        free(top); // free old top
        top = newTop; // change top to new candidate
    }
}

void topStack(){
    printf("Top of the stack is %d\n", top->value);
}

int main(){
    pushStack(1);
    pushStack(5);
    pushStack(9);
    pushStack(4);
    pushStack(14);
    pushStack(19);
    pushStack(12);
    pushStack(7);
    pushStack(98);
    pushStack(67);
    pushStack(52);
    pushStack(45);
    pushStack(40);
    pushStack(28);
    pushStack(17);

    popStack(); // 17 -> 28 (new top)
    popStack(); // 28 -> 40 (new top)
    popStack(); // 40 -> 45 (new top)
    topStack(); // return 45

    popStack(); // 45 -> 52
    topStack(); // return 52


    return 0;
}