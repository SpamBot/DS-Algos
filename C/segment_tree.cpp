#include<vector>
//based on: https://codeforces.com/blog/entry/18051

typedef struct{
  std::vector<int> val;
  int s;
  void init(int *a, int n){
    s=n;
    val.resize(2*n);
    for(int i=0; i<n; i++)val[n+i]=a[i];
    for(int i=n-1; i>0; i--)val[i]=val[i<<1]+val[i<<1|1];
` }
  void upd(int k, int d){
    k+=s;
    while(k>0){
      val[k]+=d;
      k>>=1;
    }
  }
  int get(int l, int r){
    int out=0;
    l+=s; r+=s;
    while(l<r){
      if(l&1)out+=val[l++];
      if(r&1)out+=val[--r];
      l>>=1; r>>=1;
    }
    return out;
  }
}segtree;
