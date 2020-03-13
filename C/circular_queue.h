#include<stdlib.h>


typedef struct{int *val, size, msize, s, e;}queue;

queue initqueue(int n){
    queue q;
    q.val=(int*)calloc(n, sizeof(int));
    q.size=0; q.msize=n; q.s=0; q.e=0;
    return q;
}

void push(int n, queue *q){
    q->size++;
    if(q->size==q->msize){
        q->msize*=2;
        q->val=(int*)realloc(q->val, sizeof(int)*q->msize);
    }
    q->val[q->e]=n;
    q->e=(q->e+1)%q->msize;
}

int pop(queue *q){
    int out=-1;
    if(q->size>0){
        q->size--;
        out=q->val[q->s];
        q->s=(q->s+1)%q->msize;
    }
    return out;
}
