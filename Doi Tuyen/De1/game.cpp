#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
const int N = 505;
using ii = pair <int, int>;
int rnk[N], anc[N]; ii que[N * N];

int find_set(int u){
    if (u != anc[u]) anc[u] = find_set(anc[u]);
    return anc[u];
}

bool union_set(int u, int v){
    if (u == v) return 0;
    if (rnk[u] == rnk[v]) rnk[u]++;
    if (rnk[u] > rnk[v]) anc[u] = v;
    else anc[v] = u;
    return 1;
}

void solve(){
    int n; cin >> n;
    for (int i = 1; i <= n; i++) anc[i] = i, rnk[i] = 0;
    int q = n * (n - 1) / 2;
    for (int i = 1; i <= q; i++) cin >> que[i].fi >> que[i].se;
    for (int i = 1; i <= q; i++){
        if (i == q){
            cout << "1\n"; continue;
        }
        int a = find_set(que[i].fi), b = find_set(que[i].se);
        int c = find_set(que[q].fi), d = find_set(que[q].se);
        if (a == b || (a == c && b == d) || (a == d && b == c)){
            cout << "0 "; continue;
        }
        union_set(a, b); cout << "1 ";
    }
    
}

int main(){
    freopen("game.inp", "r", stdin);
    freopen("game.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t; while (t--) solve();
}