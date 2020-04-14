#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("rank.inp", "r", stdin);
    freopen("rank.out", "w", stdout);
    int n, k; cin >> n >> k;
    vector <pair <int, char>> a(n);
    for (auto &qq : a) cin >> qq.second >> qq.first;
    sort(a.rbegin(), a.rend());
    for (int i = 0; i < k; i++)
        cout << a[i].second << '\n' << a[i].first << '\n';
}