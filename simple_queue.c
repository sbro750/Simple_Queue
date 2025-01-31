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

bool enqueue(Queue* q, int value){
    return false;
}

bool dequeue(Queue* q){
    return false;
}

bool isEmpty(Queue* q){
    return false;
}

bool isFull(Queue* q){
    return false;
}
/** Unity Testing*/ 
void setUp(void) {}     
void tearDown(void) {} 

void testing(void){
    Queue q;
    init(&q);
    TEST_ASSERT_EQUAL(true, enqueue(&q,1));
}

int main(int argc, char *argv[]){
    UNITY_BEGIN();
    RUN_TEST(testing);
    return UNITY_END();
}