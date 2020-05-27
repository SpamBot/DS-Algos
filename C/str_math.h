#include<string.h>


void div(char *a, int n){
    int l=strlen(a), x=0, t=0, i;
    char b[251];
    for(i=0; i<l; i++){
        x=x*10+a[i]-'0';
        if(x<n)b[t]='0';
        else{b[t]=(x/n)+'0'; x%=n;}
        t++;
    }
    if(b[0]=='0')x=1; else x=0;
    for(i=0; i<t-x; i++)a[i]=b[i+x];
    for(i=t-x; i<l; i++)a[i]='\0';
}

void add(char *a, char *b){
    int la=strlen(a), lb=strlen(b), i, r=0, x;
    for(i=0; i<max(la, lb); i++){
        if(i<la && i<lb)x=a[i]-'0'+b[i]-'0'+r;
        else if(i<la)x=a[i]-'0'+r;
        else if(i<lb)x=b[i]-'0'+r;
        r=x/10; a[i]=x%10+'0';
    }
    if(r>0){a[i]=r+'0'; i++;}
}
