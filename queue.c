#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>

#define QUEUE_EMPTY INT_MIN

typedef struct node {
    int value;
    struct node* next;
} node;

typedef struct {
    node* head;
    node* tail;
} queue;

void init_queue(queue *q) {
    q->head = NULL;
    q->tail = NULL;
}

bool enqueue(queue *q, int value) {
    //create a new node
    node* newnode = malloc(sizeof(node));
    if (newnode == NULL) return false;
    newnode->value = value;
    newnode->next = NULL;

    //if there is a tail, connect that tail to the new node
    if(q->tail) q->tail->next = newnode;
    q->tail = newnode;

    //if head is null connect it to the new node
    if(!q->head) q->head = newnode;

    return true;
}

int dequeue(queue *q) {
    //check to see if the queue is empty
    if (q->head == NULL ) return QUEUE_EMPTY;

    //save the head of the queue
    node* tmp = q->head;

    //save the result we're going to return
    int result = tmp->value;

    //update the head
    q->head = q->head->next;

    if (!q->head) q->tail == NULL;

    free(tmp);
    return result;
}

int main() {
    queue q1, q2, q3;

    init_queue(&q1);
    init_queue(&q2);
    init_queue(&q3);

    enqueue(&q1, 56);
    enqueue(&q2, 78);
    enqueue(&q2, 23);
    enqueue(&q2, 988);
    enqueue(&q3, 13);

    int t;

    while((t = dequeue(&q2)) != QUEUE_EMPTY) {
        printf("t = %d\n", t);
    }

    return 0;
}
