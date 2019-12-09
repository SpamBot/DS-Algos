#include<stdio.h>
#include<string.h>


void btoo(char *s, int x){
    if(x>1){
        btoo(s, x-3);
        print(((int)s[x]-48)+((int)s[x-1]-48)*2+((int)s[x-2]-48)*4);
    }
    else if(x==1) print(((int)s[x]-48)+((int)s[x-1]-48)*2);
    else if(x==0) print((int)s[x]-48);
}


int main(){
    char s[1003], *p;
    gets(s);
    if(s[0]=='-'){printf("-"); p=s+1;}
    else p=&s[0];
    btoo(p, strlen(p)-1);
}
