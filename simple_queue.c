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

void init(Queue* q){
    q -> head = -1;
    q -> tail = -1;
}

bool isEmpty(Queue* q){
    return (q->head == -1 || q->head > q->tail);
}

bool isFull(Queue* q){
    return (q->tail == SIZE - 1);
}

bool enqueue(Queue* q, int value){
    if (isFull(q)){
        printf("Queue is Full\n");
        return false;
    }

    if (isEmpty(q)){
        q->head=0;
    }

    q->tail++;
    q->items[q->tail] = value;

    printf("Added: %d\n", value);
    return true;
}

int dequeue(Queue* q){
    if (isEmpty(q)){
        printf("Queue is empty\n");
        return false;
    }

    int value = q->items[q->head];
    q->head++;
    printf("Removed: %d\n", value);

    if (q->head > q->tail){
        init(q);
    }

    return value;
}



/** Unity Testing*/ 
void setUp(void) {}     
void tearDown(void) {} 

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

void testing_final(void){
    Queue q;
    init(&q);

    TEST_ASSERT_EQUAL(true, enqueue(&q, 1));
    TEST_ASSERT_EQUAL(true, enqueue(&q, 2));
    TEST_ASSERT_EQUAL(1, dequeue(&q));
    TEST_ASSERT_EQUAL(true, enqueue(&q, 3));
    TEST_ASSERT_EQUAL(2, dequeue(&q));
    TEST_ASSERT_EQUAL(true, enqueue(&q, 4));
    TEST_ASSERT_EQUAL(true, enqueue(&q, 5));
    TEST_ASSERT_EQUAL(3, dequeue(&q));
    TEST_ASSERT_EQUAL(4, dequeue(&q));
    TEST_ASSERT_EQUAL(true, enqueue(&q, 6));
    TEST_ASSERT_EQUAL(5, dequeue(&q));
    TEST_ASSERT_EQUAL(6, dequeue(&q));
    TEST_ASSERT_EQUAL(false, dequeue(&q));
    TEST_ASSERT_EQUAL(true, enqueue(&q, 7));
    TEST_ASSERT_EQUAL(true, enqueue(&q, 8));
    TEST_ASSERT_EQUAL(true, enqueue(&q, 9));
    TEST_ASSERT_EQUAL(7, dequeue(&q));
    TEST_ASSERT_EQUAL(8, dequeue(&q));
    TEST_ASSERT_EQUAL(9, dequeue(&q));


    

}

int main(int argc, char *argv[]){
    UNITY_BEGIN();
    RUN_TEST(testing_enqueue);
    RUN_TEST(testing_dequeue);
    RUN_TEST(testing_final);
    return UNITY_END();
}
