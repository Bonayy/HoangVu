#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define ctz __builtin_ctzll
ll n, m; 

void solve(){
    if (n == 0){
        puts("0"); return;
    }
    ll t = __gcd(n, m);
    n /= t; m /= t;
    printf("%lld", n / m); n %= m;
    if (n == 0){
        putchar('\n'); return;
    }
    t = m; t >>= ctz(t);
    while (t % 5 == 0) t /= 5;
    putchar('.');
    if (t == 1){
        while (n > 0){
            n *= 10; 
            putchar(n / m + '0');
            n %= m;
        }
        putchar('\n'); return;
    }
    int tor = n * 10 % m;
    int har = tor * 10 % m;
    while (tor != har){
        tor = tor * 10 % m;
        har = (har * 10 % m) * 10 % m;
    }
    tor = n; int lam = 1;
    while (tor != har){
        putchar(tor * 10 / m + '0');
        tor = tor * 10 % m;
        har = har * 10 % m;
    }
    putchar('(');
    har = tor * 10 % m;
    while (tor != har){
        har = har * 10 % m;
        lam++;
    }
    while (lam--){
        putchar(tor * 10 / m + '0');
        tor = tor * 10 % m;
    }
    puts(")");
}

int main(){
    freopen("division.inp", "r", stdin);
    freopen("division.out", "w", stdout);
    while (cin >> n >> m) solve();
}