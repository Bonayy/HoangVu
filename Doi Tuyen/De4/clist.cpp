#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("clist.inp", "r", stdin);
    freopen("clist.out", "w", stdout);
    int n, x, y, k; 
    cin >> n >> x >> y;
    vector <int> a(n);
    for (int &it : a) cin >> it;
    x = ((x - y) % n + n) % n;
    cin >> k; x = 1ll * x * k % n;
    rotate(a.begin(), a.begin() + x, a.end());
    for (auto x : a) cout << x << ' ';
}