#include<stdlib.h>


typedef struct{
    int *a, size, msize;
}stack;

stack initstack(int n){//n is the starting stack size
    stack s;
    s.size=0;
    s.msize=n;
    s.a=(int *)calloc(s.msize, sizeof(int));
    return s;
}

void push(int n, stack *s){
    s->size++;
    if(s->size>s->msize){
        s->msize+=50;
        s->a=(int *)realloc(s->a, sizeof(int)*s->msize);
    }
    (*s).a[s->size-1]=n;
}

int pop(stack *s){
    if((*s).size>0){
        s->size--;
        return s->a[s->size];
    }
}

int peek(stack *s){if(s->size>0)return s->a[s->size-1];}

int size(stack *s){return s->size;}

void empty(stack *s){s->size=0;}//free(s->a);
