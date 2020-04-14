#include <bits/stdc++.h>
using namespace std;

const int N = 1e7 + 5;
using ll = long long;
ll a[N], mas[N];

namespace fast_io{
    template <typename T>
    void read(T &x){
        char c; bool nega = 0; x = 0;
        while (!isdigit(c = getchar()) && c != '-');
        if (c == '-'){
            nega = 1; c = getchar();
        }
        for (; isdigit(c); c = getchar())
            x = (x << 1) + (x << 3) + c - 48;
        if (nega) x = -x;
    }

    template <typename T>
    void writep(T x){
        if (x > 9) writep(x / 10);
        putchar(x % 10 + 48);
    }

    template <typename T>
    void write(T x){
        if (x < 0){
            x = -x; putchar('-');
        }
        writep(x);
    }

    template <typename T>
    void writeln(T x){
        write(x); putchar('\n');
    }
}

int main(){
    freopen("arrmax.inp", "r", stdin);
    freopen("arrmax.out", "w", stdout);
    using namespace fast_io;
    int n; read(n); 
    ll mis = 0, res = LLONG_MIN, s = 0;
    for (int i = 1; i <= n; i++){
        read(a[i]); s += a[i];
        res = max(res, s - mis);
        mis = min(mis, s);
        mas[i] = max(mas[i - 1], s);
    }
    s = 0;
    for (int i = n; i > 0; i--){
        s += a[i]; 
        res = max(res, s + mas[i - 1]);
    }
    writeln(res);
}