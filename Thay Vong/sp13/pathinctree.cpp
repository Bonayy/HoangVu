#include <bits/stdc++.h>
using namespace std;

#define all(v) (v).begin(), (v).end()
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define eb emplace_back
#define pb push_back
using ii = pair <int, int>;

struct edge{
    int u, v, w;

    edge(){}

    edge(int u, int v, int w): u(u), v(v), w(w){}

    bool operator < (const edge &o) const {
        return w < o.w;
    }
};

const int N = 1e5 + 5;
int dp[N], tmp[N]; edge lst[N];
vector <int> adj[N];

template <class X, class Y>
bool chkmax(X &p, const Y &q){
    return p < q ? p = q, 1 : 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1, u, v, w; i < n; i++){
        cin >> u >> v >> w;
        adj[u].eb(v); adj[v].eb(u);
        lst[i] = edge(u, v, w);
    }
    sort(lst + 1, lst + n); int res = 0;
    for (int i = 1, j = 0; i < n; i++){
        if (lst[i].w > lst[j].w)
            while (j < i){
                chkmax(dp[lst[j].u], tmp[lst[j].u]);
                chkmax(dp[lst[j].v], tmp[lst[j].v]);
                j++;
            }
        chkmax(res, tmp[lst[i].u] = dp[lst[i].v] + 1);
        chkmax(res, tmp[lst[i].v] = dp[lst[i].u] + 1);
    }
    cout << res << '\n';
}