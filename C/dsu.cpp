typedef struct{//disjoint set union
    long dad[200000], h[200000];
    void init(long n){for(long i=0; i<n; i++){dad[i]=i; h[i]=0;}}
    long get(long x){
        if(dad[x]!=x)dad[x]=get(dad[x]);
        return dad[x];
    }
    bool join(long x, long y){
        long dx=get(x), dy=get(y);
        if(dx==dy)return 0;
        if(h[dx]>h[dy])std::swap(dx, dy);
        dad[dx]=dy;
        h[dy]=std::max(h[dy], h[dx]+1);
        return 1;
    }
}dsu;
