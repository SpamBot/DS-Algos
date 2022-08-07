typedef struct{//aka binary indexed tree
    std::vector<ll> val;
    long size;
    ll psum(long n){
        ll out=0;
        while(n>0){
            out+=val[n];
            n=(n & (n+1)) - 1;
        }
        return out;
    }
    ll rsq(long l, long r){return psum(r)-psum(l-1);}
    void upd(long k, long d){
        while(k<size){
            val[k]+=d;
            k=k | (k+1);
        }
    }
}BiT;
