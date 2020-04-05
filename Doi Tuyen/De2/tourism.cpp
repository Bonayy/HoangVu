#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 1e4 + 5;
ll dp[N], a[N]; int n, p; 
int trace[N];
vector <int> ans;

ll square(ll x){
    return x * x;
}

ll fine(int i, int j){
    return square(a[j] - a[i] - p);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0); 
    cin >> n >> p;
    for (int i = 1; i <= n; i++){
        cin >> a[i]; dp[i] = LLONG_MAX;
        for (int j = i - 1; j >= 0; j--){
            if (dp[i] > dp[j] + fine(j, i)){
                trace[i] = j; dp[i] = dp[j] + fine(j, i);
            }
        }
    }
    cout << dp[n] << '\n';
    while (n > 0){
        ans.push_back(n); 
        n = trace[n];
    }
    cout << ans.size() << '\n';
    for (auto rit = ans.rbegin(); rit != ans.rend(); rit++)
        cout << *rit << ' ';
}