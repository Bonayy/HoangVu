#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 3e5 + 5;
ll bit[N], qv[N], reqd[N];
int ql[N], qr[N], lo[N], hi[N];
vector <int> own[N], check[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m, q; cin >> n >> m;
    for (int i = 1, x; i <= m; i++){
        cin >> x; own[x].push_back(i);
    }
    for (int i = 1; i <= n; i++)
        cin >> reqd[i];
    cin >> q;
    for (int i = 1; i <= q; i++)
        cin >> ql[i] >> qr[i] >> qv[i];
    for (int i = 1; i <= n; i++){
        lo[i] = 1; hi[i] = q + 1;
    }
}