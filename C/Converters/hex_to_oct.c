#include<stdio.h>

//0 1 2 0 4 5 6 0 8 9 10 0 12 13
//0 1 2   3 4 5   6 7 8    9  10
int fpow(int a, int n){
    int x=1, j=1;
    if(n>0){
        x=a;
        while(j*2<n){x*=x; j*=2;}
        while(j<n){x*=a; j++;}
    }
    return x;
}//80=200 //F00000=74000000
//a+16s+16^2d+16^3f+16^4g+...=
//a+8*2s+8^2*4d+8^4f+8^5*2g+...
void htoo(char *s, int n, int i, int c){
    if(n>=0){
        int x=(int)s[n], zf=-1;
        if(47<x && x<58)x-=48;
        else if(64<x && x<71)x-=55;
        x*=fpow(2, i%3); x+=c; c=x/8;
        if((i+1)%3==0){zf=c%8; c/=8;}
        htoo(s, n-1, i+1, c);
        if(zf>0)printf("%d", zf);
        else if(zf==0 && n!=0)printf("0");
        printf("%d", x%8);
    }
    else if(c!=0)printf("%d", c);
}

int main() {
    char s[1001], *p;
    int n=0;
    scanf("%[^\n]", s);
    if(s[0]=='-'){printf("-"); p=s+1;}
    else p=&s[0];
    while(p[n]!='\0')n++;
    htoo(p, n-1, 0, 0);
}
