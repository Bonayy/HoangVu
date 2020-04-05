#include <bits/stdc++.h>
using namespace std;

const int mod = 131131;
const int N = 10005;
int sum[N], dp[N], n, s;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0); 
    int c, a; cin >> s >> n; dp[0] = 1;
    for (int i = 1; i <= n; i++){
        cin >> c >> a;
        for (int gr = 0; gr < c; gr++)
            for (int j = gr, cnt = 0; j <= s; j += c, cnt++){
                sum[cnt + 1] = (sum[cnt] + dp[j]) % mod;
                if (cnt >= a) dp[j] = (dp[j] + sum[cnt] - sum[cnt - a] + mod) % mod;
                else dp[j] = (dp[j] + sum[cnt]) % mod;
            }
    }
    cout << dp[s] << '\n';
}