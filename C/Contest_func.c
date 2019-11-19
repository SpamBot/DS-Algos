#include<stdio.h>

#define max(a, b) ((a)>=(b)) ? (a):(b)
 //scanf("%[^\n]", s);

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

void eratosphen(int n){
    int a[n], i, x=3;
    for(i=0; i<n; i++){if(i%2==0)a[i]=0; else a[i]=1;}
    a[1]=0; a[2]=1;
    while(x*x<n){
        for(i=x*x; i<n; i++)if(a[i]!=0 && i%x==0)a[i]=0;
        x++;
        while(a[x]!=1 && x<n)x++;
    }
    for(i=0; i<n; i++)if(a[i]!=0)printf("%d ", i);
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

int dsum(int n){
    char s[12];
    int sum=0, i;
    sprintf(s, "%d", n);
    for(i=0;i<=strlen(s);i++)sum+=(int)s[i]-48;
    return sum;
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


int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d", nod(a, b));
}
