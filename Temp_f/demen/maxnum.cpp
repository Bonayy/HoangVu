#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("maxnum.inp", "r", stdin);
    freopen("maxnum.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector <string> vs(n);
    for (auto &s : vs) cin >> s;
    sort(vs.begin(), vs.end(), [](const string &s, const string &t){
        if (s + t > t + s) return true; else return false;
    });
    for (auto s : vs) cout << s; cout << '\n';
}