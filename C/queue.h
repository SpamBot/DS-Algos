#include<stdlib.h>


typedef struct{
    int *data, size, msize;
}queue;

queue initq(int n){
    queue q;
    q.size=0; q.msize=n+1;
    q.data=(int *)calloc(q.msize, sizeof(int));
    return q;
}

void push(int n, queue *q){
    q->size++;
    if(q->size==q->msize){
        q->msize+=20;
        q->data=(int *)realloc(q->data, sizeof(int)*q->msize);
    }
    q->data[q->size-1]=n;
}

int pop(queue *q){
    if(q->size>0){
        q->size--;
        int n=q->data[0], i;
        for(i=0; i<q->size; i++)q->data[i]=q->data[i+1];
        return n;
    }
}

int peek(queue *q){if(q->size>0)return q->data[0];}

int size(queue *q){return q->size;}

void empty(queue *q){q->size=0;}//free(s->a);
