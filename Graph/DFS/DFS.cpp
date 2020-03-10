#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("DFS.inp", "r", stdin);
	freopen("DFS.out", "w", stdout);
	int n; cin >> n;
	bool a[n][n], avail[n], trace[n];
	int x, y;
	memset(a, 0, sizeof a);
	memset(avail, 1, sizeof avail);
	while (cin >> x >> y){
		a[x - 1][y - 1] = 1; a[y - 1][x - 1] = 1;
	}
	stack <int> s; int kq = 0;
	for (int j = 0; j < n; j++){
		if (avail[j]){
			kq++;
			s.push(j);
			while (!s.empty()){
				int u = s.top(); s.pop();
				if (avail[u]){
					cout << u + 1 << ' ';
				 	avail[u] = 0;
					for (int i = n - 1; i >= 0; i--)
						if (avail[i] && a[u][i]){
							trace[i] = u; s.push(i);
						}
				}
			}
		}
	}
	cout << '\n' << kq;
}