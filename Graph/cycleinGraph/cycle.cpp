#define emp emplace_back
#include <bits/stdc++.h>
using namespace std;
vector <vector <int> > a;
vector <bool> avail, instack;
bool isCycle = false;
int n, m;
void setup(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    freopen("cycle.inp", "rt", stdin);
    freopen("cycle.out", "wt", stdout);
}

void timeElapsed(){
    cerr << "Time elapsed : " << clock() << " ms";
}

void addEdge(int u, int v){
    a[u].emp(v); a[v].emp(u);
}


void dfsCycle(int u, int par = 0){
    if (isCycle) return;
    avail[u] = false;
    instack[u] = true;
    for (auto v : a[u]){
        if (instack[v] && v != par){
            isCycle = true;
            return;
        }
        if (avail[v]) dfsCycle(v, u);
    }
    instack[u] = false;
}

int main(){
    setup();
    cin >> n >> m;
    a.resize(n + 1); int u, v;
    avail.resize(n + 1, true);
    instack.resize(n + 1, false);
    for (int i = 0; i < m; i++){
        cin >> u >> v;
        addEdge(u, v);
    }
    for (int i = 1; i <= n; i++)
        if (avail[i]) dfsCycle(i);
    cout << (isCycle ? "YES" : "NO");
    timeElapsed(); return 0;
}

