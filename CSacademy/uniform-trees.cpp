#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 2e5 + 5;
const int mod = 1e9 + 7;
int in[N], out[N], ver[N], tim;
int hv[N], ans[N], cnt[N], p[N];
vector <int> adj[N];

ll mexp(ll a, ll k){
    ll r = 1;
    for (; k > 0; k >>= 1){
        if (k & 1) r = r * a % mod;
        a = a * a % mod;
    }
    return r;
}

int dfs_hv(int v){
    ver[in[v] = ++tim] = v;
    int v_sz = 1, mc_sz = 0, c_sz;
    for (int c : adj[v]){
        v_sz += c_sz = dfs_hv(c);
        if (mc_sz < c_sz){
            mc_sz = c_sz; hv[v] = c;
        }
    }
    out[v] = tim; return v_sz;
}

void dfs_sol(int v, bool cl){
    for (int c : adj[v])
        if (c != hv[v]) 
            dfs_sol(c, true);
    if (hv[v]){
        dfs_sol(hv[v], false);
        ans[v] = ans[hv[v]] + mexp(2, cnt[p[hv[v]]] - 1);
        ans[v] %= mod;
    }
    for (int c : adj[v])
        if (c != hv[v])
            for (int i = in[c]; i <= out[c]; i++){
                ans[v] = ans[v] + mexp(2, cnt[p[ver[i]]]++);
                ans[v] %= mod; 
            }
    cnt[p[v]]++;
    if (cl) for (int i = in[v]; i <= out[v]; i++)
        cnt[p[ver[i]]]--;
}

int main(){
    int n; cin >> n >> p[1] >> p[1];
    for (int i = 2, j; i <= n; i++){
        cin >> j >> p[i]; adj[j].push_back(i);
    }
    dfs_hv(1); dfs_sol(1, 0);
    cout << accumulate(ans + 1, ans + n + 1, n,
    [](const int &x, const int &y){
        return (x + y) % mod;
    }) << '\n';
;}