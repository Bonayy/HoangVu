#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("summaxk.inp", "r", stdin);
    freopen("summaxk.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k;
    vector <int> a(n);
    for (int &x : a) cin >> x;
    long long sum = 0, ans = LLONG_MIN;
    for (int i = 0; i < k - 1; i++)
        sum += a[i];
    for (int i = k - 1; i < n; i++){
        sum += a[i]; ans = max(ans, sum);
        sum -= a[i - k + 1];
    }
    cout << ans << '\n';
}