#include <bits/stdc++.h>
using namespace std;

const int N = 3005;
using ll = long long;
ll dp[N][N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("bracket.inp", "r", stdin);
    freopen("bracket.out", "w", stdout);
    int n; ll k; cin >> n >> k; 
    n /= 2; string res; dp[0][0] = 1;
    for (int i = 1; i <= 2 * n; i++){
        dp[i][0] = dp[i - 1][1]; dp[i][n] = dp[i - 1][n - 1];
        for (int j = 1; j < n; j++)
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];
    }
    for (int i = 1, dep = 0; i <= 2 * n; i++)
        if (dep < n && k <= dp[2 * n - i][dep + 1]){
            res += "("; dep++;
        }
        else {
            res += ")"; 
            if (dep < n) k -= dp[2 * n - i][dep + 1];
            dep--;
        }
    cout << res << '\n';
}