int rom_to_dec(char *s, int l){
    int out=0, i=0, prev=1001, curr, count=0;
    while(i<l){
        if(s[i]=='I'){
            if(s[i+1]=='V'){out+=4; curr=4; i+=2;}
            else if(s[i+1]=='X'){out+=9; curr=9; i+=2;}
            else{out+=1; curr=1; i++;}
        }
        else if(s[i]=='X'){
            if(s[i+1]=='L'){out+=40; curr=40; i+=2;}
            else if(s[i+1]=='C'){out+=90; curr=90; i+=2;}
            else{out+=10; curr=10; i++;}
        }
        else if(s[i]=='C'){
            if(s[i+1]=='D'){out+=400; curr=400; i+=2;}
            else if(s[i+1]=='M'){out+=900; curr=900; i+=2;}
            else{out+=100; curr=100; i++;}
        }
        else if(s[i]=='V'){out+=5; curr=5; i++;}
        else if(s[i]=='L'){out+=50; curr=50; i++;}
        else if(s[i]=='D'){out+=500; curr=500; i++;}
        else if(s[i]=='M'){out+=1000; curr=1000; i++;}
        else{out=-1; break;}
        if(curr>prev){out=-1; break;}
        else if(curr==prev)count++;
        else count=0;
        if(count>3){out=-1; break;}
        prev=curr;
    }
    return out; //out is -1 if input is not a valid roman number
}
