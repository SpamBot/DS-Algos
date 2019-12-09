#include<stdio.h>


long atod(char *s, long m, long b){
    long l=0;
    if(s[0]!='\0')l+=((long)s[0]-48)*m+atod(s+1, m*b, b);
    return l;
}

void reverse(char *s, int n){
    char c;
    int i;
    for(i=0; i<n/2; i++){
        c=s[i]; s[i]=s[n-1-i]; s[n-1-i]=c;
    }
}

int main() { 
    char s[100], *p;
    int b, n=0;
    scanf("%d %[^\n]", &b, s);
    if(s[0]=='-'){printf("-"); p=&s[1];}
    else p=&s[0];
    while(p[n]!='\0')n++;
    reverse(p, n);
    printf("%ld", atod(p, 1, b));
}
