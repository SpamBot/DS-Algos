#include<stdio.h>

#define max(a, b) ((a)>=(b)) ? (a):(b)
 //scanf("%[^\n]", s);

typedef struct stack{
    int a[100], p;
} stack;
void push(int n, stack *s){(*s).a[s->p]=n; s->p++;}
int pop(stack *s){if((*s).p>0){s->p--; return s->a[s->p];}}
int peek(stack *s){if(s->p>0)return s->a[s->p-1];}
int size(stack *s){return s->p;}
void empty(stack *s){s->p=0;}


typedef struct pstack{ //persistent stack
    stack a[100];
    int p;
} pstack;
void ppush(int n, pstack *ps, int stnum){
    //ps->p++; ps->a[(*ps).p]=ps->a[(*ps).p-1];
    ps->p++; ps->a[(*ps).p]=ps->a[stnum];
    push(n, &(ps->a[(*ps).p]));
}
int ppop(pstack *ps, int stnum){
    //ps->p++; ps->a[(*ps).p]=ps->a[(*ps).p-1];
    ps->p++; ps->a[(*ps).p]=ps->a[stnum];
    pop(&(ps->a[(*ps).p]));
}

int nod(int a, int b){
    while(a!=0 && b!=0){
        if(a>b)a%=b;
        else b%=a;
    }
    return max(a, b);
}

int nok(int a, int b){
    if(a>b) return (a/nod(a, b))*b;
    else return (b/nod(a, b))*a;
}

int isprime(int n){
    if(n==2)return 1;
    else if(n%2==0 || n==1)return 0;
    else{
        int d=3;
        while(d<n && n!=0){
            if(n%d==0) break;
            d+=2;    
        }
        if(n%d==0 && d!=n)return 0;
        else return 1;
    }
}

void eratosphen(unsigned long n){
    unsigned long a[n], i, x=3;
    for(i=0; i<n; i++){if(i%2==0)a[i]=0; else a[i]=1;}
    a[1]=0; a[2]=1;
    while(x*x<n){
        for(i=x*x; i<n; i++)if(a[i]!=0 && i%x==0)a[i]=0;
        x++;
        while(a[x]!=1 && x<n)x++;
    }
    for(i=0; i<n; i++)if(a[i]!=0)printf("%ld ", i);
    //return &a[0];
}

void ishprime(int n){
    int t=0, z=0;
    while(n>0){
        if(isprime(n)==1)t++;
        n/=10; z++;
    }
    if(t==z) printf("YES");
    else printf("NO");
}

int fib(int n){
    int a=1, b=1, x;
    while(n>1){
        x=b; b+=a; a=x;
        n-=1;
    }
    return a;
}
//is n a power of t? returns 1 if YES
int ispow(int n, int t){
    int out=0;
    if(t>1){
        if(n==1)out=1;
        else if(n==0)out=0;
        else if(n%t==0)out=ispow(n/t, t);
    }
    else if(t==1 && n==1)out=1;
    return out;
}
//returns a^n
int fpow(int a, int n){
    int x=1, j=1;
    if(n>0){
        x=a;
        while(j*2<n){x*=x; j*=2;}
        while(j<n){x*=a; j++;}
    }
    return x;
}
//returns rat.fraction approximation for a square root; best used with long arithmetics
void newton(unsigned long a, unsigned long x, unsigned long y, int n){
    long num=x*x+a*y*y, den=2*x*y;//n-max num of iterations
    if(n>=0 && num>0 && den>0){
        long hcf=nod(num, den);
        num/=hcf; den/=hcf;
        newton(a, num, den, n-1);
    }
    else printf("\nsqrt(%lu)=%lu/%lu=%lf", a, x, y, (float)x/y);
}
//sum of digits #1
int dsum(int n){
    char s[12];
    int sum=0, i;
    sprintf(s, "%d", n);
    for(i=0;i<=strlen(s);i++)sum+=(int)s[i]-48;
    return sum;
}
//sum of digits #2
/*int dsum(int n){
    int s=0, x=n; //x=abs(n);
    while(x>0){s+=x%10; x/=10;}
    return s;
}*/

//stone sort
void ssort(int *a, int n){//O(n^2)
    int x;
    for(j=n-1;j>=0;j--)
        for(i=0;i<j;i++) 
            if(a[i]>a[i+1]){
                x=a[i]; a[i]=a[i+1]; a[i+1]=x;
            }
}

void merge(int *a, int l, int r){
    int i=0, j=l, k=0, out[r];
    while(i<l && j<r){
        if(a[i]<a[j]){out[k]=a[i]; k++; i++;}
        else {out[k]=a[j]; k++; j++;}
    }
    while(i<l){out[k]=a[i]; k++; i++;}
    while(j<r) {out[k]=a[j]; k++; j++;}
    for(i=0; i<r; i++)a[i]=out[i];
}
//merge sort
void msort(int *a, int n){
    if(n>1){
        msort(a, n/2); msort(a+n/2, (n+1)/2);
        merge(a, n/2, n);
        //int i;for(i=0;i<n;i++)printf("%d ", a[i]); printf("\n");
    }
}
//quick sort
void qsort(int *a, int s, int e){
    if(s<e){
        int l=s, r=e, m=a[(e+s)/2]; //m!=(e+s)/2
        while(l<=r){
            while(a[l]<m)l++; //a[l]<a[m] does not work
            while(a[r]>m)r--;
            if(l<=r){
                int x=a[l]; a[l]=a[r]; a[r]=x; l++; r--;
            }
        }
        qsort(a, s, r);
        qsort(a, l, e);
    }
}/*
//binary check
int bcheck(int x, int *a, int n){
    int out=-1;
    if(n>0){
        if(x<a[n/2])out=bcheck(x, a, n/2);
        else if(x>a[n/2])out=bcheck(x, &a[(n+1)/2], n/2);
        else out=n/2;
    }
    return out;
}*/
/*
//approximate binary search
int bsearch(int x, int *a, int n){
    int out, l=0, r=n;
    while(l<r){
        out=(l+r)/2; //printf("out=%d, l=%d, r=%d\n", out, l, r);
        if(a[out]<x)l=out;
        else if (a[out]>x)r=out;
        if(a[out]==x || out==(l+r)/2) break;
    } //printf("----------\n");
    //if(a[out]!=x)out=-1; //use this to check for belonging
    return out;
}*/
//checks whether a passed string is a palindrome
int ispalindr(char *s){
    int i=0, len, out=1;
    while(s[i]!='\0')i++; len=i;
    for(i=0; i<len/2; i++)if(s[i]!=s[len-i-1]){out=0; break;}
    return out==1;
}
