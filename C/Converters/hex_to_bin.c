#include<stdio.h>

void printbin(int n, int t){
    if(t<4){
        int p;
        if(n>0)p=n%2;
        else if(n==0)p=0;
        printbin(n/2, t+1);
        printf("%d", p);
    }
}//printbinfin() is for cutting leading zeroes
void printbinfin(int n){if(n>0){printbinfin(n/2); printf("%d", n%2);}}
//10=10000 20=100000 30=110000
void htob(char *s, int n){
    int i;
    int x=(int)s[0];
    if(47<x && x<58)x-=48;
    else if(64<x && x<71)x-=55;
    if(x!=0)printbinfin(x);
    else if(n==1 && x==0)printf("0");
    for(i=1; i<n; i++){
        int x=(int)s[i];
        if(47<x && x<58)x-=48;
        else if(64<x && x<71)x-=55;
        printbin(x, 0);
    }
}

int main() { 
    char s[1001], *p;
    int n=0;
    scanf("%[^\n]", s);
    if(s[0]=='-'){printf("-"); p=s+1;}
    else p=&s[0];
    while(p[n]!='\0')n++;
    htob(p, n);
}
