#include <bits/stdc++.h>
using namespace std;

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

void operator /= (modular &a, const modular &b){
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
    for (int v : adj[u]) if (v != p){
        if (dp[v][cs2] == 0)
            prod *= dp[v][cs1];
        else prod *= dp[v][cs2];
    }
    return prod;
}

modular opt1(int u, int p, int cs1, int cs2, int exc = 0){
    modular a = 1, b = 0;
    for (int v : adj[u]) if (v != p && v != exc){
        a *= dp[v][cs2];
        b += dp[v][cs1] / dp[v][cs2];
    }
    return a * b;
}

modular opt2(int u, int p, int cs1, int cs2){
    modular a = 1, b = 0;
    for (int v : adj[u]) if (v != p)
        a *= dp[v][cs2];
    int n = adj[u].size() - (p != 0);
    vector <modular> pre(n + 1), suf(n + 1);
    int cnt = 0;
    for (int i = 0; i < adj[u].size(); i++)
        if (adj[u][i] != p)
            pre[cnt++] = dp[adj[u][i]][cs1] / dp[adj[u][i]][cs2];
    for (int i = adj[u].size() - 1; ~i; i--)
        if (adj[u][i] != p){
            suf[cnt - 1] = suf[cnt] + pre[cnt - 1]; cnt--;
        }
    for (int i = 0; i < adj[u].size(); i++)
        if (adj[u][i] != p)
            b += pre[i] * suf[i + 1];
    return a * b;
}

modular h1(int u, int p, int cs){
    int cnt_zero = 0;
    for (int v : adj[u])
        if (v != p && dp[v][cs] == 0) cnt_zero++;
    if (cnt_zero == 0) return opt1(u, p, 2, cs);
    if (cnt_zero == 1) return opt0(u, p, 2, cs);
    return 0;
}

modular h2(int u, int p){
    int cnt_zero = 0;
    for (int v : adj[u])
        if (v != p && dp[v][0] == 0) cnt_zero++;
    if (cnt_zero == 0) return opt2(u, p, 2, 0);
    if (cnt_zero == 1)
        for (int v : adj[u])
            if (v != p && dp[v][0] == 0)
                return dp[v][2] * opt1(u, p, 2, 0, v);
    if (cnt_zero == 2) return opt0(u, p, 2, 0);
    return 0;
}

modular h3(int u, int p){
    modular prod = 1;
    for (int v : adj[u]) if (v != p)
        prod *= dp[v][1];
    return prod;
}

void dfs(int u, int p){
    for (int v : adj[u]) if (v != p) dfs(v, u);
    dp[u][0] = h1(u, p, 1) + h2(u, p) + h3(u, p);
    dp[u][1] = h2(u, p);
    dp[u][2] = h1(u, p, 0) + h3(u, p);
}

int main(){
    int n; cin >> n;
    for (int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0); cout << dp[1][0] << '\n';
}