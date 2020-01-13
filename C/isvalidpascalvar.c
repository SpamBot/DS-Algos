#include<stdio.h>
#include<string.h>
//Program which checks whether a passed string is a valid variable name in PASCAL

int iseq(char *s, char *p){//checks whether s and p are equal strings
    unsigned long i; int tst=1;
    if(strlen(s)!=strlen(p))tst=0;
    else{
        for(i=0; i<strlen(p); i++)
            if(s[i]!=p[i]){
                tst=0;
                break;
            }
    }
    return tst;
}

void lowercase(char *s){//puts s into lowercase
    unsigned long i;
    int x;
    for(i=0; i<strlen(s); i++){
        x=(int)s[i];
        if(64<x && x<91)s[i]+=32;
    }
}

int ispaskey(char *s){//checks whether s is a PASCAL keyword
    char pas[54][15]={"and","array","asm","begin","break","case","const",
    "constructor","continue","destructor","div","do","downto","else",
    "end","false","file","for","function","goto","if","implementation",
    "in","inline","interface","label","mod","nil","not","object",
    "of","on","operator","or","packed","procedure","program","record",
    "repeat","set","shl","shr","string","then","to","true","type",
    "unit","until","uses","var","while","with","xor"};
    int i, out=0;
    if(strlen(s)<16){
        lowercase(s);
        for(i=0; i<54; i++)if(iseq(s, &pas[i][0])==1){out=1; break;}
    }
    return out;
}

int isnumnlet(char *s){//checks whether s is made only from numbers, letters and underscores
    unsigned long i; int out=1, x;
    for(i=0; i<strlen(s); i++){
        x=(int)s[i];
        if(!((47<x && x<58) || (64<x && x<91) || (96<x && x<123) || x==95)){
            out=0; break;
        }
    }
    return out;
}

int main(){
    int out=0, x, y;
    char s[1000000];
    scanf("%1000000[^\n]", s);
    x=ispaskey(&s[0]); y=isnumnlet(&s[0]);
    if(x==0 && ((int)s[0]<48 || (int)s[0]>57) && y==1)out=1;
    if(out==0)printf("NO");
    else printf("YES");
}
