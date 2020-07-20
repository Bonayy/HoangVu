#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int a[N], st[4 * N];

void build(int i, int l, int r){
    if (l + 1 == r){
        st[i] = a[l]; return;
    }
    int m = (l + r) / 2;
    int ls = 2 * i, rs = ls + 1;
    build(ls, l, m);
    build(rs, m, r);
    st[i] = max(st[ls], st[rs]);
}

void update(int i, int l, int r,
            int p, int v){
    if (l > p || r <= p) return;
    if (l + 1 == r){
        st[i] = v; return;
    }
    int m = (l + r) / 2;
    int ls = 2 * i, rs = ls + 1;
    update(ls, l, m, p, v);
    update(rs, m, r, p, v);
    st[i] = max(st[ls], st[rs]);
}

int lb(int i, int l, int r,
        int lim = 0, int v){
    if (st[i] < v) return -1;
    if (r <= lim) return -1;
    if (l + 1 == r) return l;
    int ls = 2 * i, rs = ls + 1;
    int res = -1, m = (l + r) / 2;
    if (st[ls] >= v)
        res = lb(ls, l, m, lim, v);
    if (res == -1)
        res = lb(rs, m, r, lim, v);
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, q; cin >> n >> q;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    build(1, 0, n); int cmd;
    while (q--){
        int u, v;
        cin >> cmd >> u >> v;
        if (cmd == 1)
            update(1, 0, n, u, v);
        else cout <<
        lb(1, 0, n, v, u) << '\n';
    }
}