/*
    Author : Nguyen Hoang Vu
    Date : 20 December 2019
    Time : 01.27 AM
*/

//~ #pragma GCC optimize("O3")
//~ #pragma GCC optimize("unroll-loops")
#define fi first
#define se second
#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef vector <ii> vii;
typedef priority_queue <ii, vii, greater <ii> > pqii;

struct Graph{
    int n; vii *Edge;
    Graph(int n) : n(n) {
        Edge = new (nothrow) vii [n + 1];
    }
    void addEdge(int u, int v, int w){
        Edge[u].push_back(ii(v, w));
        Edge[v].push_back(ii(u, w));
    }
    void Enter(){
        int u, v, w;
        while (cin >> u >> v >> w)
            addEdge(u, v, w);
    }
    void minPath(int s){
        pqii pq;
        int Dis[n + 1];
        fill(Dis, Dis + n + 1, INT_MAX);
        Dis[s] = 0; int u, v, cost; ii t;
        pq.push(ii(0, s));
        while (!pq.empty()){
            t = pq.top(); pq.pop(); u = t.se;
            if (t.fi > Dis[u]) continue;
            for (auto i : Edge[u]){
                v = i.fi; cost = i.se;
                if (Dis[v] > Dis[u] + cost){
                    Dis[v] = Dis[u] + cost;
                    pq.push(ii(Dis[v], v));
                }
            }
        }
        for (int i = 1; i <= n; i++)
            cout << Dis[i] << ' ';
    }
};

int main(){
    int n; cin >> n;
    Graph G(n); G.Enter();
    G.minPath(1);
    cerr << clock();
    return 0;
}
