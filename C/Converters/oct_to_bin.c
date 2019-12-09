#include<stdio.h>


void bprint(int n){
    if(n>0){
        bprint(n/2);
        printf("%d", n%2);
    }
}
//000 001 010 011 100 101 110 111
void otob(char *s){
    if(s[0]!='\0'){
        int x=(int)s[0]-48;
        if(x<4)printf("0");
        if(x<2)printf("0");
        if(x==0)printf("0");
        else bprint(x);
        otob(s+1);
    }
}

int main() { 
    char s[100], *p;
    int x;
    scanf("%[^\n]", s);
    if(s[0]=='-'){printf("-"); p=&s[1];}
    else p=&s[0];
    x=(int)p[0]-48;
    if(x==0)printf("0");
    else bprint(x);
    otob(p+1);
}
