#include <bits/stdc++.h>
using namespace std;

#define all(v) (v).begin(), (v).end()
#define lb lower_bound
#define ub upper_bound
using ll = long long;
const int N = 1000;
const ll mod = 1e12 + 7;
ll dp[N], sum[N], s; int a[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector <int> cmp(a + 1, a + n + 1); 
    sort(all(cmp)); dp[0] = 1;
    cmp.resize(unique(all(cmp)) - cmp.begin());
    for (int i = 1; i <= n; i++)
        a[i] = ub(all(cmp), a[i]) - cmp.begin();
    for (int len = 1; len <= k; len++){
        for (int i = 1; i <= n; i++) sum[i] = 0;
        s = dp[len - 1]; ll prev = dp[len];
        for (int i = len; i <= n; i++, prev = dp[i]){
            dp[i] = (s - sum[a[i]] + mod) % mod;
            sum[a[i]] = (sum[a[i]] + dp[i]) % mod;
            s = (s + prev) % mod;
            cout << dp[i] << " \n"[i == n];
        }
    }
    cout << accumulate(dp + k, dp + n + 1, 0);
}