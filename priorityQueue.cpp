#include <stdio.h>
#include <stdlib.h>

// PRIORITY QUEUE = QUEUE but prioritized larger value

// Priority Queue with double linked list
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

void pushPriority(int query){ //enqueue - sort kecil ke besar
    Node *temp = createNode(query);
    if(!first){ //kalau gak ada first, berarti new node = first
        first = last = temp;
    }
    else if(query > first->value){ // kalau temp adalah value terbesar
        first->next = temp;
        temp->prev = first;
        first = temp;
    }
    else if(query < last->value){ // kalau temp adalah value terkecil
        first->prev = temp;
        temp->next = first;
        last = temp;
    }
    else{
        Node *current = last;
        while(current->value < query){ // loop sampai posisi <= sama current
            current = current -> next;
        }
        // NULL <- 5 <-> 10 <-> 15 <-> 20 -> NULL
        //                            (18) - current position sama kek 20 (current is 20)

        temp -> prev = current -> prev;
        temp -> next = current;
        current -> prev -> next = temp;
        current -> prev = temp;
    }
}

void popPriority(){ //dequeue - popHead()
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

void firstPriority(){
    printf("First in the priority queue is %d\n", first->value);
}

// function buat printLinkedList untuk check sort
void readNode(Node *currentNode){
    printf("%d\n", currentNode -> value);
}

void printLinkedList(){ // sama kayak loop biasa, ini formatnya
    puts("Current Priority Queue (ascending):");
    for(Node *temp = last; temp != NULL; temp = temp -> next){
        readNode(temp);
    }
}

int main(){
    pushPriority(1);
    pushPriority(5);
    pushPriority(9);
    pushPriority(4);
    pushPriority(14);
    pushPriority(19);
    pushPriority(12);
    pushPriority(7);
    pushPriority(98);
    pushPriority(67);
    pushPriority(52);
    pushPriority(45);
    pushPriority(40);
    pushPriority(28);
    pushPriority(17);
    // printLinkedList(); //sorted succesfully (ascending)

/* SORTED PRIORITY QUEUE RESULT
1
4
5
7
9
12
14
17
19
28
40
45
52
67
98
*/
 
    firstPriority(); // return 98
    popPriority(); // 98 -> 67
    firstPriority(); // return 67
    popPriority(); // 67 -> 52
    popPriority(); // 52 -> 45
    firstPriority(); // return 45
}