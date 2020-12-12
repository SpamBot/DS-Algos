int get_closest(int x){
    int m=1, a[13]={1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
    for(int i=0; i<13; i++)if(x-m>x-a[i] && x-a[i]>=0)m=a[i];
    return m;
}

void dec_to_rom(int x, char *s){
    int t, i=0;
    if(x>4999)throw 1;
    while(x>0){
        t=get_closest(x);
        switch(t){
            case 1:{s[i]='I'; i++; break;}
            case 4:{s[i]='I'; s[i+1]='V'; i+=2; break;}
            case 5:{s[i]='V'; i++; break;}
            case 9:{s[i]='I'; s[i+1]='X'; i+=2; break;}
            case 10:{s[i]='X'; i++; break;}
            case 40:{s[i]='X'; s[i+1]='L'; i+=2; break;}
            case 50:{s[i]='L'; i++; break;}
            case 90:{s[i]='X'; s[i+1]='C'; i+=2; break;}
            case 100:{s[i]='C'; i++; break;}
            case 400:{s[i]='C'; s[i+1]='D'; i+=2; break;}
            case 500:{s[i]='D'; i++; break;}
            case 900:{s[i]='C'; s[i+1]='M'; i+=2; break;}
            case 1000:{s[i]='M'; i++; break;}
            default:{s[i]='\0'; break;}
        }
        x-=t;
    }
    s[i]='\0';
}
