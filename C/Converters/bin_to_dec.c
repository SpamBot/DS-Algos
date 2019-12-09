#include<stdio.h>
#include<string.h>


define abs(x) ((x)>=0) ? (x):-(x)
int btod(char *s, int d){
    int n=strlen(s);
    if(n>0){
        return d*((int)s[0]-48)+btod(s+1, 2*d);
    }
    else return 0;
}

void reverse(char *s){
    int i;
    char c;
    for(i=0;i<strlen(s)/2;i++){
        c=s[i];
        s[i]=s[strlen(s)-1-i];
        s[strlen(s)-1-i]=c;
    }
}

int main(){
    char s[100], *p;
    gets(s);
    if(s[0]=='-'){printf("-"); p=s+1;}
    else p=&s;
    reverse(p);
    print(btod(p, 1));
}
