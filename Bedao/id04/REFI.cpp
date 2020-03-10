#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;
const int N = 1e5 + 5;
int dp[N][17]; 
char s[N];

int main(){
    freopen("REFI.inp", "r", stdin);
    freopen("REFI.out", "w", stdout);
    scanf("%s", s + 1); 
    int n = strlen(s + 1); dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
        if (s[i] != '?'){
            for (int k = 0; k < 17; k++){
                int _k = (k * 10 + s[i] - '0') % 17;
                dp[i][_k] = dp[i - 1][k];
            }
        }
        else {
            for (int k = 0; k < 17; k++)
                for (int d = 0; d < 10; d++){
                    int _k = (k * 10 + d) % 17;
                    dp[i][_k] = (dp[i][_k] + dp[i - 1][k]) % mod;
                }
        }
    cout << dp[n][5] << '\n';
}