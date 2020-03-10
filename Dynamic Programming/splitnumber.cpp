/// count number of ways to split number n into sum of numbers <= m
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = 1e9 + 7;
const int N = 1005;
ll dp[N][N];

int main(){
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) 
        dp[i][1] = 1;
    for (int i = 1; i <= m; i++)
        dp[1][i] = 1;
    for (int i = 2; i <= n; i++)
        for (int j = 2; j <= m; j++){
            if (i < j) dp[i][j] = dp[j][i];
            else if (i == j) dp[i][j] = 1 + dp[i][j - 1];
            else dp[i][j] = dp[i][j - 1] + dp[i - j][j];
            dp[i][j] %= mod;
        }
    cout << dp[n][m];
}