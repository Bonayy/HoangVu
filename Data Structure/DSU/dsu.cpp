#include <bits/stdc++.h>
using namespace std;

struct Dsu{
    int n; int *par, *rate;
    void makeSet(){
        for (int i = 1; i <= n; i++)
            par[i] = i, rate[i] = 0;
    }
    Dsu(int n) : n(n) {
        par = new (nothrow) int[n + 1];
        rate = new (nothrow) int[n + 1];
        makeSet();
    }
    int findSet(int u){
        if (u != par[u]) par[u] = findSet(par[u]);
        return par[u];
    }
    void unionSet(int u, int v){
        u = findSet(u);
        v = findSet(v);
        if (u == v) return;
        if (rate[u] == rate[v]) rate[u]++;
        if (rate[u] < rate[v]) par[u] = v;
        else par[v] = u;
    }
    bool isSameSet(int u, int v){
        return findSet(u) == findSet(v);
    }
};

int main(){
    int n; cin >> n;
    Dsu D(n);
    int c, u, v;
    for (int i = 1; i <= n; i++){
        cin >> u >> v >> c;
        if (c == 2) cout << D.isSameSet(u, v) << '\n';
        else D.unionSet(u, v);
    }
}
