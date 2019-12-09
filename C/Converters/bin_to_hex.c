#include<stdio.h>
#include<string.h>


#define print16(n) if((n)<10)print((n));else printf("%c", (char)((n)+55))

//10000->10
void btoh(char *s, int x){
    if(x>3){
        btoh(s, x-4);
        int n=0, i, d=1;
        for(i=x;i>x-4;i--){n+=((int)s[i]-48)*d; d*=2;}
        print16(n);
        
    }
    else if(x>=0){
        int n=0, i, d=1;
        for(i=x;i>=0;i--){n+=((int)s[i]-48)*d; d*=2;}
        print16(n);
    }
}


int main(){
    char s[1003], *p;
    gets(s);
    if(s[0]=='-'){printf("-"); p=s+1;}
    else p=&s[0];
    btoh(p, strlen(p)-1);
}
