#include<stdio.h>

#define min(a, b) ((a)>(b)) ? (b):(a)


typedef struct{
    int n, val[10000];
}hyper;

void inith(hyper *h){
    h->n=1; h->val[0]=0;
}

void addh(hyper *a, hyper *b){
    int n=min(a->n, b->n), r=0, x;
    for(int i=0; i<n; i++){
        x=a->val[i]+b->val[i]+r;
        r=x/10000;
        a->val[i]=x%10000;
    }
    if(a->n<b->n)for(int i=n; i<b->n; i++){
        x=b->val[i]+r;
        r=x/10000;
        a->val[i]=x%10000;
        a->n++;
    }
    if(r>0){a->val[n]=r; a->n++;}
}

void mult(hyper *h, int n){
    long r=0, x;//6561*3 19683 9683
    for(int i=0; i<h->n; i++){
        x=h->val[i]*n+r; //printf("x=%ld\n", x);
        r=x/10000;
        h->val[i]=x%10000;
    }
    if(r>0){h->val[h->n]=r; h->n++;}
}

void print(hyper *a){
    printf("%d", a->val[a->n-1]);
    for(int i=a->n-2; i>=0; i--)
        printf("%.4d", a->val[i]);
}
