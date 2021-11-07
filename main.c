#include <stdio.h>
#include "queues.h"

int main(void) {
    QUEUE *queueChilo=newQueue();
    int n=8;
    int n1=2;
    int n2=3;
    int n3=7;
    void *ptrN=&n;
    void *ptrN1=&n1;
    void *ptrN2=&n2;
    void *ptrN3=&n3;

    enqueue(queueChilo, ptrN);
    enqueue(queueChilo, ptrN1);
    enqueue(queueChilo, ptrN2);
    enqueue(queueChilo, ptrN3);

    printQueueOfIntegers(queueChilo);

    dequeue(queueChilo);

    printQueueOfIntegers(queueChilo);

    printf("%d\n",*(int*)(next(queueChilo)));


    printf("prueba\n");

    QUEUE *q = newQueue();


    int nums[]={1,2,3,5,7,9,11,13,17};
    for(int i=0;i<9;i++){
        enqueue(q, nums+i);
    }

    void *marker =next(q);

    //enqueue(q, dequeue(q));

    do{
        void *d = next(q);
        printf("%d ", *(int*)d);
        enqueue(q, dequeue(q));

    }while(marker!=next(q));


    printf("\n");
    printf("QUEUES OF QUEUES\n");


    int n0[]={1,3,4};
    int na[]={-10,-5,-1,5};
    int nb[]={0,2,2,4,8,10};

    void *ptr=NULL;

    QUEUE *q0=newQueue();
    QUEUE *q1=newQueue();
    QUEUE *q2=newQueue();

    for(int i=0;i<sizeof(n0)/4;i++)
        enqueue(q0, n0+i);

    for(int i=0;i<sizeof(na)/4;i++)
        enqueue(q1, na+i);

    for(int i=0;i<sizeof(nb)/4;i++)
        enqueue(q2, nb+i);


    void *ptr0=q0;
    void *ptr1=q1;
    void *ptr2=q2;

    QUEUE *input=newQueue();

    enqueue(input, ptr0);
    enqueue(input, ptr1);
    enqueue(input, ptr2);
    /*
    printQueueOfIntegers(q0);
    printQueueOfIntegers(q1);
    printQueueOfIntegers(q2);
    */

    QUEUE *newOrganized=newQueue();
    newOrganized=reduceQueues(input);
    printQueueOfIntegers(newOrganized);
    return 0;





}