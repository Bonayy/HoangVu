#include <bits/stdc++.h>
using namespace std;

#define all(v) (v).begin(), (v).end()
#define lb lower_bound
#define ub upper_bound

int main(){
    int n, res = 0; cin >> n; vector <int> a(n);
    for (int &x : a) cin >> x; sort(all(a));
    for (auto it = a.begin(); it != a.end() - 3; ++it)
        res = max(res, int(ub(all(a), *it + *(it + 1)) - it));
    cout << res << '\n';
}