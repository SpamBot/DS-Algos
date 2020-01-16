#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct{
    int num;
    char val[50];//wsize=50
}word;
//word list
typedef struct{
    int size, msize;
    word *data;//speed can be gained if data[0] is unused
}wlist;

void printlist(wlist *l){
    int i;
    for(i=0;i<l->size;i++)printf("%s:%d ",l->data[i].val, l->data[i].num);
    printf("size=%d\n",l->size);}

wlist initwlist(){
    wlist l;
    l.size=0;
    l.msize=20;
    l.data=(word *)calloc(l.msize, sizeof(word));
    return l;
}

int searchwl(wlist *li, char *s){//O(wsize*(log(size)+1))
    int l=0, r=li->size, m, tst, t=1;//t is <0 if we found string and >0 otherwise
    while(l<r-1){
        m=(l+r)/2;
        tst=strcmp(s, &li->data[m].val[0]);
        if(tst<0)r=m;
        else if(tst>0)l=m;
        else {l=m; t=-1; break;}
    }
    if(li->size>0 &&  strcmp(s, &li->data[l].val[0])>0)l=r;
    return l*t;
}
//if i<0 we increase counter, if i>0 we add s to data[]
void insertwl(wlist *l, char *s, int i){//O(wsize+2*size)
    if(i<0 || (i==0 && l->size>0 && strcmp(l->data[0].val, s)==0))l->data[-i].num++;
    else{
        int j;
        l->size++;
        if(l->size==l->msize){
            l->msize+=20;
            l->data=(word *)realloc(l->data, sizeof(word)*l->msize);
        }
        for(j=l->size-1; j>i; j--)l->data[j]=l->data[j-1];
        l->data[i].num=1;
        strcpy(l->data[i].val, s);
    }
}
//bubble sort for sorting list by word frequency without changing the relative order
void bsortli(wlist *li, int n){
    int i, j;
    for(i=1; i<n; i++){
        for(j=n-1; j>=i; j--)if(li->data[j-1].num<li->data[j].num){
            word w=li->data[j-1];
            li->data[j-1]=li->data[j];
            li->data[j]=w;
        }
    }
}

void mergew(word *a, int n, int m){
    int i=0, j=n, t=0;
    word out[m];
    while(i<n && j<m){
        if(a[i].num<a[j].num){out[t]=a[j]; t++; j++;}//this line causes "stability" property
        else {out[t]=a[i]; t++; i++;}                //and this one too
    }
    while(i<n){out[t]=a[i]; t++; i++;}
    while(j<m){out[t]=a[j]; t++; j++;}
    for(i=0; i<m; i++)a[i]=out[i];
}
//merge sort
void msortw(word *a, int n){
    if(n>1){
        msortw(a, n/2);
        msortw(&a[n/2], (n+1)/2);
        mergew(a, n/2, n);
    }
}
