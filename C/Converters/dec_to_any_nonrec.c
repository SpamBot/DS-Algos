#include <stdio.h>

#define abs(x) ((x)>=0) ? (x):-(x)
#define print(x) printf("%d", x)

void sis(int n, int b){
    int t=abs(n), a[32], f=0;
    while(t>0){a[f]=t%b; f++; t/=b;}
    if(n<0)printf("-");
    else if(n==0) print(0);
    while(f>0){
        if(a[f-1]<10)print(a[f-1]);
        else putchar((char)(a[f-1]+55)); f--;
    }
}

int main(){
    int n, b;
    scanf("%d %d", &n, &b);
    sis(n, b);
}
