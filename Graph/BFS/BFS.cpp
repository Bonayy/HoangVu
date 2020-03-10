#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("BFS.inp", "r", stdin);
	freopen("BFS.out", "w", stdout);
	int n, u, v; cin >> n;
	int s, t; cin >> s >> t;
	vector <vector <int> > e(n + 1);
	bool avail[n + 1];
	int trace[n + 1];
	memset(avail, 1, sizeof avail);
	while (cin >> u >> v){
        e[u].push_back(v);
        e[v].push_back(u);
	}
	queue <int> q; avail[s] = 0;
	q.push(s); trace[s] = 0;
	while (!q.empty()){
        u = q.front(); q.pop();
        for (int i : e[u])
            if (avail[i]){
                trace[i] = u; avail[i] = 0;
                if (i == t) break;
                q.push(i); trace[i] = u;
            }
	}
	if (!avail[t]){
        u = t; stack <int> st;
        while (u != 0){
            st.push(u);
            u = trace[u];
        }
        cout << st.top(); st.pop();
        while (!st.empty()){
            cout << " --> " << st.top();
            st.pop();
        }
	}
	else cout << "The path doesn't exist !";
	return 0;
}
