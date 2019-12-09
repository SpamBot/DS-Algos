#include <stdio.h>

#define abs(x) ((x)>=0) ? (x):-(x)
#define print(x) printf("%d", x)

void sis(int n, int b){
    if(n<0)printf("-");
    if(n!=0){
        int t=abs(n);
        sis(t/b, b);
        if(t%b<10)print(t%b);
        else putchar((char)(t%b+55));
    }
}

int main(){
    int n, b;
    scanf("%d %d", &n, &b);
    if(n==0)print(0);
    else sis(n, b);
}
