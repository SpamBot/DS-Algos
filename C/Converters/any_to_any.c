#include<stdio.h>
#include<string.h>
#include "hyper.h"

void to_dec(char *s, hyper *x, int base){
    int l=strlen(s), curr;
    hyper tmp, base_pow;
    base_pow.len=1; base_pow.val[0]=1;
    for(int i=l-1; i>=0; i--){
        if('0'<=s[i] && s[i]<='9')curr=s[i]-'0';
        else curr=s[i]-'A'+10;
        copyh(&tmp, &base_pow);
        mult_short(&tmp, curr);
        addh(x, &tmp, 0);
        mult_short(&base_pow, base);
    }
}

void to_any(hyper *x, int *base){
    char out;
    if(x->len>1 || x->val[0]!=0){
        out=mod_short(x, *base);
        div_short(x, *base);
        to_any(x, base);
        if(out<10)printf("%d", out);
        else printf("%c", out-10+'A');
    }
}

int main(){
  int curr_base, new_base;
  char s[1001];
  hyper x;
  scanf("%d %d%*c", &curr_base, &new_base);
  scanf("%[^\n]", s);
  to_dec(&s[0], &x, curr_base);
  if(x.len==1 && x.val[0]==0)printf("0");
  else to_any(&x, &new_base);
}
