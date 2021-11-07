
#include <stdio.h>
#include <stdlib.h>
#include "queues.h"

struct STRNODE
{
    TYPE data;
    struct STRNODE *next;
};

struct STRQUEUE
{
    NODE  *top;
    int size;
};

QUEUE *newQueue(){
    QUEUE *newQueue=malloc(sizeof(QUEUE));
    newQueue->size=0;

    newQueue->top = malloc(sizeof(NODE));
    newQueue->top->next = NULL;
    return newQueue;
}


void enqueue(QUEUE* queue, void *value){
    NODE *newElement=malloc(sizeof(NODE));
    NODE *focusNode = queue->top;
    while(focusNode->next!=NULL){
        focusNode=focusNode->next;
    }
    focusNode->next=newElement;
    focusNode->data=value;
    newElement->next=NULL;
    queue->size++;

}


void *dequeue(QUEUE* queue){
    if(queue->size==0){
        printf("El queue ya esta vacío.");
    }else{
        NODE *elementDelete=queue->top;
        queue->top=queue->top->next;
        void *elementReturned = elementDelete->data;
        free(elementDelete);
        queue->size--;
        return elementReturned;
    }
    return NULL;
}


void *next(QUEUE* queue){
    if(queue->size==0)
    {
        return NULL;
    }else{
        return queue->top->data;
    }

}

void printQueueOfIntegers(QUEUE *queue){
    NODE *focusNode = queue->top;
    while(focusNode->next!=NULL){
        printf("%d ", *(int*)(focusNode->data));
        focusNode=focusNode->next;
    }
    printf("\n");
}




//queues of queues


int nextInt(QUEUE *queue){
    return *(int*)next(queue);
}

void compararQueues(QUEUE *helper, QUEUE *finalQueue, QUEUE *focusQueue){
    while(next(helper)!=NULL && next(finalQueue)!=NULL){
        //comparacion valores
        if(nextInt(helper)>nextInt(finalQueue)){
            enqueue(focusQueue,dequeue(finalQueue));
        }
        else if (nextInt(helper)<nextInt(finalQueue)){
            enqueue(focusQueue,dequeue(helper));
        }
        else if(nextInt(helper)==nextInt(finalQueue)){
            enqueue(focusQueue,dequeue(finalQueue));
            enqueue(focusQueue,dequeue(helper));
        }
    }

    if(next(finalQueue)==NULL){
        while(next(helper)!=NULL){
            enqueue(focusQueue,dequeue(helper));
        }
    }
    else if(next(helper)==NULL){
        while(next(finalQueue)!=NULL){
            enqueue(focusQueue,dequeue(finalQueue));
        }
    }
}

QUEUE* reduceQueues(QUEUE *input)
{

    QUEUE *helper=newQueue();
    QUEUE *finalQueue=newQueue();
    QUEUE *focusQueue=newQueue();

    if(next(input)==NULL){
        return input;
    }

    while(next(input)!=NULL){
        //helper ya es la primera q
        helper=dequeue(input);

        //comparar helper con final
        compararQueues(helper,finalQueue,focusQueue);
        //por si input se queda vacia antes de salir del while
        if(next(input)==NULL){
            break;
        }
        helper=dequeue(input);
        //comparar helper con focus
        compararQueues(helper,focusQueue,finalQueue);
    }
    if(next(focusQueue)==NULL){
        return finalQueue;
    }
    else if(next(finalQueue)==NULL){
        return focusQueue;
    }
    return newQueue();

}