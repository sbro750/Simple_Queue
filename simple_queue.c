/**
* Title:    Simple Queue
* Filename: simple_queue.c
* Author:   Stephen Brooks
* Date:     31/01/2024
*/

#include <stdio.h>
#include <stdlib.h>
#include "unity.h"
#include <stdbool.h>

#define SIZE 5

/** Queue */
typedef struct{
    int items[SIZE];
    int head;
    int tail;
} Queue;

// initialisation of the queue
void init(Queue* q){
    q -> head = -1;
    q -> tail = -1;
}

// Checking for if empty
bool isEmpty(Queue* q){
    return (q->head == -1 || q->head > q->tail);    // checking if it is initialised or if all the elements have been removed
}

// Checking for if full
bool isFull(Queue* q){
    return (q->tail == SIZE - 1);
}

// Add an item to the queue
bool enqueue(Queue* q, int value){
    if (isFull(q)){
        printf("Queue is Full\n");
        return false;
    }

    if (isEmpty(q)){
        q->head=0;
    }

    q->tail++;                      // tail goes to next point in the queue
    q->items[q->tail] = value;      // add item to queue

    printf("Added: %d\n", value);
    return true;
}

// Remove an item from the queue
int dequeue(Queue* q){
    if (isEmpty(q)){
        printf("Queue is empty\n");
        return false;
    }

    int value = q->items[q->head];      // value of the item that is being removed
    q->head++;                          // shift head to next element to be removed
    printf("Removed: %d\n", value);     

    return value;
}



/** Unity Testing*/ 
void setUp(void) {}     
void tearDown(void) {} 

// Testing for adding extra items to the queue 
void testing_enqueue(void){
    Queue q;
    init(&q);

    TEST_ASSERT_EQUAL(true, enqueue(&q, 1));
    TEST_ASSERT_EQUAL(true, enqueue(&q, 2));
    TEST_ASSERT_EQUAL(true, enqueue(&q, 3));
    TEST_ASSERT_EQUAL(true, enqueue(&q, 4));
    TEST_ASSERT_EQUAL(true, enqueue(&q, 5));

    TEST_ASSERT_EQUAL(false, enqueue(&q, 6));
    TEST_ASSERT_EQUAL(1, dequeue(&q));
}

// Testing for removing items for the queue
void testing_dequeue(void){
    Queue q;
    init(&q);

    TEST_ASSERT_EQUAL(true, enqueue(&q, 1));
    TEST_ASSERT_EQUAL(true, enqueue(&q, 2));
    TEST_ASSERT_EQUAL(true, enqueue(&q, 3));
    TEST_ASSERT_EQUAL(true, enqueue(&q, 4));
    TEST_ASSERT_EQUAL(true, enqueue(&q, 5));
    TEST_ASSERT_EQUAL(1, dequeue(&q));
    TEST_ASSERT_EQUAL(2, dequeue(&q));
    TEST_ASSERT_EQUAL(3, dequeue(&q));
    TEST_ASSERT_EQUAL(4, dequeue(&q));
    TEST_ASSERT_EQUAL(5, dequeue(&q));
    TEST_ASSERT_EQUAL(false, dequeue(&q));
}

int main(int argc, char *argv[]){
    UNITY_BEGIN();
    RUN_TEST(testing_enqueue);
    RUN_TEST(testing_dequeue);
    return UNITY_END();
}
