//
// Created by luax2 on 07/10/2021.
//

#ifndef QUEUES_QUEUES_H
#define QUEUES_QUEUES_H
typedef void *TYPE;
typedef struct STRNODE NODE;
typedef struct STRQUEUE QUEUE;

QUEUE *newQueue();
void enqueue(QUEUE* queue, void *value);
void *dequeue(QUEUE* queue);
void *next(QUEUE* queue);
void printQueueOfIntegers(QUEUE *queue);


int nextInt(QUEUE *queue);
void compararQueues(QUEUE *helper, QUEUE *finalQueue, QUEUE *focusQueue);
QUEUE* reduceQueues(QUEUE *input);
#endif //QUEUES_QUEUES_H
