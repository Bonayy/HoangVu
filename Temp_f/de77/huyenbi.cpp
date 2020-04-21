#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll mod = 20122007;

ll mexp(ll a, ll k){
    ll res = 1;
    for (; k > 0; k >>= 1){
        if (k & 1) res = res * a % mod;
        a = a * a % mod;
    }
    return res;
}

ll mystery(ll a){
    ll t = ll(sqrt(a)), res = 1;
    if (t * t == a) 
        res = res * (mexp(3, t) - 1) % mod;
    for (int d = 1; d < t; d++)
        if (a % d == 0){
            res = res * (mexp(3, d) - 1) % mod;
            res = res * (mexp(3, a / d) - 1) % mod;
        }
    return res;
}

int main(){
    freopen("huyenbi.inp", "r", stdin);
    freopen("huyenbi.out", "w", stdout);
    ll a; cin >> a; cout << mystery(a) << '\n';
}