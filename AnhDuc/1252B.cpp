#include <bits/stdc++.h>
using namespace std;

<<<<<<< HEAD
=======
struct modular{
    using ll = long long; ll val;
    static const int mod = 1e9 + 7;

    modular(): val(0){}

    template <typename T>
    modular(T _val): val(_val % mod){
        if (val < 0) val += mod;
    }

    bool operator != (const modular &o){
        return val != o.val;
    }

    bool operator == (const modular &o){
        return val == o.val;
    }
};

modular operator + (const modular &a, const modular &b){
    return modular(a.val + b.val);
}

void operator += (modular &a, const modular &b){
    a = a + b;
}

modular operator - (const modular &a, const modular &b){
    return modular(a.val - b.val);
}

void operator -= (modular &a, const modular &b){
    a = a - b;
}

modular operator * (const modular &a, const modular &b){
    return modular(a.val * b.val);
}

void operator *= (modular &a, const modular &b){
    a = a * b;
}

modular pow(const modular &a, const int &k){
    modular res(1), x(a);
    for (int i = k; i > 0; i >>= 1){
        if (i & 1) res *= x; x *= x;
    }
    return res;
}

modular inverse(const modular &a){
    return pow(a, modular::mod - 2);
}

modular operator / (const modular &a, const modular &b){
    return a * inverse(b);
}

modular operator /= (modular &a, const modular &b){
    a = a / b;
}

istream& operator >> (istream &is, modular &a){
    modular::ll x; is >> x; a = modular(x); return is;
}

ostream& operator << (ostream &os, const modular &a){
    return os << a.val;
}

const int N = 1e5 + 5;
modular dp[N][3]; vector <int> adj[N];

modular opt0(int u, int p, int cs1, int cs2){
    modular prod = 1;
    for (int v : adj[u]) if (v != p)
        if (dp[v][cs2] == 0)
            prod *= dp[v][cs1];
        else prod *= dp[v][cs2];
    return prod;
}

modular opt1(int u, int p, int cs1, int cs2){
    modular a = 1, b = 0;
    for (int v : adj[u]) if (v != p){
        a *= dp[v][cs2];
        b += dp[v][cs1] / dp[v][cs2];
    }
    return a * b;
}

modular opt2(int u, int p, int cs1, int cs2){
    
}

void dfs(int u, int p){
    for (int v : adj[u]) if (v != p) dfs(v, u);
}

>>>>>>> b969cce8d37618750f176a1d3fc2a142a971a0fa
int main(){
    int n; cin >> n;
}