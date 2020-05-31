#include <bits/stdc++.h>
using namespace std;
 
namespace modular{
    using ll = long long;
 
    const int mod = 998244353;
 
    int mul_mod(ll a, ll b){
        if (a < 0) a += mod;
        if (b < 0) b += mod;
        return a * b % mod;
    }
 
    int plus_mod(ll a, ll b){
        if (a < 0) a += mod;
        if (b < 0) b += mod;
        return (a + b) % mod;
    }
 
    int minus_mod(ll a, ll b){
        if (a < 0) a += mod;
        if (b < 0) b += mod;
        return (a - b + mod) % mod;
    }
 
    int pow_mod(ll a, ll k){
        ll res = 1;
        for (; k; k >>= 1, a = mul_mod(a, a))
            if (k & 1) res = mul_mod(res, a);
        return res;
    }
 
    ll ext_euclid(ll a, ll b, ll &x, ll &y){
        int g = a; x = 1; y = 0;
        if (b != 0){
            g = ext_euclid(b, a % b, y, x);
            y -= (a / b) * x;
        }
        return g;
    }
 
    int inverse(ll a){
        return pow_mod(a, mod - 2);
    }
 
    int div_mod(ll a, ll b){
        return mul_mod(a, inverse(b));
    }
};
 
using namespace modular;
 
const int N = 2e5 + 5;
const int C = 1e6 + 5;
int a[N], sum[C], w[C];
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, res = 0, maxv = 0; cin >> n;
    for (int i = 1, x; i <= n; i++){
        cin >> x; maxv = max(maxv, x);
        sum[x] = plus_mod(sum[x], x);
    }
    for (int i = 1; i <= maxv; i++){
        w[i] += inverse(i);
        for (int j = 2 * i; j <= maxv; j += i)
            w[j] = minus_mod(w[j], w[i]);
        int x = 0, y = 0;
        for (int j = i; j <= maxv; j += i){
            x = plus_mod(x, sum[j]);
            y = plus_mod(y, mul_mod(sum[j], j));
        }
        res = plus_mod(res, mul_mod(w[i],
            minus_mod(mul_mod(x, x), y)));
    }
    cout << div_mod(res, 2) << '\n';
}