#include <bits/stdc++.h>
using namespace std;

struct SegTree{
    static const int N = 1e4 + 5;
    int lo[N << 2], hi[N << 2], cnt[N << 2], sum[N << 2];
    void build(int i, int l, int r){
        lo[i] = l; hi[i] = r;
        if (l == r) return; int m = (l + r) >> 1;
        build(i << 1, l, m); build(i << 1 | 1, m + 1, r);
    }

    void update(int i, int pos, int type){
        if (lo[i] > pos || hi[i] < pos) return;
        if (lo[i] == hi[i]){
            cnt[i] += type; sum[i] += pos * type; return;
        }
        update(i << 1, pos, type);
        update(i << 1 | 1, pos, type);
        cnt[i] = cnt[i << 1] + cnt[i << 1 | 1];
        sum[i] = sum[i << 1] + sum[i << 1 | 1];
    }

    int order(int i, int k){
        if (lo[i] == hi[i]) return lo[i];
        if (cnt[i << 1] >= k) return order(i << 1, k);
        else return order(i << 1 | 1, k - cnt[i << 1]);
    }

    int query(int i, int l, int r){
        if (lo[i] > r || hi[i] < l) return 0;
        if (lo[i] >= l && hi[i] <= r) return sum[i];
        return query(i << 1, l, r) + query(i << 1 | 1, l, r);
    }
    int count(int i, int l, int r){
        if (lo[i] > r || hi[i] < l) return 0;
        if (lo[i] >= l && hi[i] <= r) return cnt[i];
        return count(i << 1, l, r) + count(i << 1 | 1, l, r);
    }
} ST;

const int N = 1e4 + 5;
vector <int> adj[N];
int child[N], n, k, res = INT_MAX;

void dfs1(int u, int par){
    child[u] = 1;
    for (int v : adj[u])
        if (v != par){
            dfs1(v, u); child[u] += child[v];
        }
    if (par != 0) ST.update(1, child[u], 1);
}

int get_cost(){
    int pos = ST.order(1, n - k - 1);
    return ST.query(1, 1, pos) - (ST.count(1, 1, pos) - n + k + 1) * pos;
}

void dfs2(int u, int par){
    int prev = child[u];
    if (par != 0){
        child[u] = n; child[par] -= prev;
        ST.update(1, prev, -1); ST.update(1, child[par], 1);
    }
    res = min(res, get_cost());
    for (int v : adj[u]) if (v != par) dfs2(v, u);
    if (par != 0){
        ST.update(1, prev, 1); ST.update(1, child[par], -1);
        child[u] = prev; child[par] = n;
    }
}

int main(){
    // freopen("cezar.inp", "r", stdin);
    // freopen("cezar.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0); cin >> n >> k;
    for (int i = 1; i < n; i++){
        int u, v; cin >> u >> v; 
        adj[u].push_back(v); adj[v].push_back(u);
    }
    ST.build(1, 1, n); dfs1(1, 0); dfs2(1, 0);
    cout << res << '\n';
}