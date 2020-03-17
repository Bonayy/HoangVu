/**
 * type 1: increase ith element in [l,r] by (i-l)*a+b
 * type 2: print sum of range [l,r] mod 1e9+7
 * */
#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
using ll = long long;using pll = pair <ll,ll>;
const int N = 1e5 + 5;const int mod = 1e9 + 7;
ll seg[N*4]; pll lazy[N*4];int lo[N*4], hi[N*4];

void fix(pll lz){
    lz.fi%=mod;lz.se%=mod;
}

void build(int i,int low,int high){
    lo[i]=low;hi[i]=high;if(lo[i]==hi[i])return;
    int med=(low+high)/2;
    build(i*2,low,med);build(i*2+1,med+1,high);
}

void lazy_down(int i){
    if(lazy[i]==pll(0,0)) return;
    if(lo[i]!=hi[i]){
        lazy[i*2].fi+=lazy[i].fi;lazy[i*2].se+=lazy[i].se;
        lazy[i*2+1].se+=lazy[i].se+lazy[i].fi*(lo[i*2+1]-lo[i]);
        lazy[i*2+1].fi+=lazy[i].fi;fix(lazy[i*2]);fix(lazy[i*2+1]);
    }
    seg[i]=(seg[i]+lazy[i].fi*(hi[i]-lo[i]+1)*(hi[i]-lo[i])/2)%mod;
    seg[i]=(seg[i]+lazy[i].se*(hi[i]-lo[i]+1))%mod; lazy[i]={0, 0};
}

void update(int i,int l,int r,ll a,ll b){
    lazy_down(i);if(lo[i]>r||hi[i]<l)return;
    if(lo[i]>=l&&hi[i]<=r){
        if(lo[i]!=hi[i]){
            lazy[i*2].fi+=a;lazy[i*2].se+=b+a*(lo[i]-l);
            lazy[i*2+1].fi+=a;lazy[i*2+1].se+=b+a*(lo[i*2+1]-l);
            fix(lazy[i*2]);fix(lazy[i*2+1]);
        }
        seg[i]=(seg[i]+a*(hi[i]-lo[i]+1)*(hi[i]+lo[i]-2*l)/2)%mod;
        seg[i]=(seg[i]+b*(hi[i]-lo[i]+1))%mod;return; 
    }
    update(i*2,l,r,a,b);update(i*2+1,l,r,a,b);
    seg[i]=(seg[i*2]+seg[i*2+1])%mod;
}

ll get_sum(int i,int l, int r){
    lazy_down(i); if(lo[i]>r||hi[i]<l)return 0;
    if(lo[i]>=l&&hi[i]<=r)return seg[i];
    return (get_sum(i*2,l,r)+get_sum(i*2+1,l,r))%mod;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,q,cmd,l,r;ll a,b;
    cin>>n>>q;build(1,1,n);
    while(q--){
        cin>>cmd>>l>>r;
        if(cmd==1){
            cin>>a>>b;update(1,l,r,a,b);
        }
        else cout<<get_sum(1,l,r)<<'\n';
    }
}