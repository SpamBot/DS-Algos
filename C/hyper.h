#include<stdio.h>

#define min(a, b) ((a)>(b)) ? (b):(a)


typedef struct{
    int len; long val[10000];
}hyper;

void inith(hyper *h){
    h->len=1; h->val[0]=0;
}

void copyh(hyper *a, hyper *b){
    for(int i=0; i<b->len; i++)a->val[i]=b->val[i];
    a->len=b->len;
}

void addh(hyper *a, hyper *b, int shift){
    int i=0;
    long x, rem=0;
    while(i<b->len || rem>0){
        x=rem;
        if(i+shift<a->len)x+=a->val[i+shift];
        else while(i+shift>=a->len){a->val[a->len]=0; a->len++;}
        if(i<b->len)x+=b->val[i];
        a->val[i+shift]=x%10000;
        rem=x/10000;
        i++;
    }
}

void mult_short(hyper *a, int b){
    int i;
    long x, rem=0;
    for(i=0; i<a->len; i++){
        x=a->val[i]*b+rem;
        a->val[i]=x%10000;
        rem=x/10000;
    }
    while(rem>0){a->len++; a->val[i]=rem%10000; rem/=10000; i++;}
}

void mult_hyper(hyper *a, hyper *b){
    hyper a_tmp, tmp;
    copy(&a_tmp, a);
    copy(&tmp, &a_tmp);
    mult_short(&tmp, b->val[0]);
    copy(a, &tmp);
    for(int i=1; i<b->len; i++){
        copy(&tmp, &a_tmp);
        lmults(&tmp, b->val[i]);
        add(a, &tmp, i);
    }
}

void print_hyper(hyper *a){
    printf("%d", a->val[a->len-1]);
    for(int i=a->len-2; i>=0; i--)
        printf("%.4d", a->val[i]);
}
