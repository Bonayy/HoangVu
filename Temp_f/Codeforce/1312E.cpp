/// O(nlogn) solution
/// we call a interval is good if it can be reduced to a single value
/// in fact there are only nlogn good intervals
/// consider all array of length n, the array which has n same value 'll have the largest number of good intervals
/// and it is easy to see that this array has nlogn good intervals
/// we will iterating over all good interval and update the dp value

#include <bits/stdc++.h>
using namespace std;

#define eb emplace_back
const int N = 1e5 + 5;
vector <int> red[N]; int a[N], dp[N], n;
/// red[i][j] be the largest k such that [i, k] can be reduced to single value a[i] + j

int get_red(int i, int val){
    int offset = val - a[i];
    if (i > n || offset < 0) return -1;
    if (offset >= size(red[i])) return -1;
    return red[i][offset];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0); cin >> n;
    for (int i = 1; i <= n; cin >> a[i++]);
    for (int i = n; i >= 1; i--){
        red[i].eb(i); int val = a[i];
        while (~get_red(red[i].back() + 1, val))
            red[i].eb(get_red(red[i].back() + 1, val++));
    }
    fill_n(dp + 1, n, 0x3f3f3f3f);
    for (int i = 1; i <= n; i++)
        for (int j : red[i])
            dp[j] = min(dp[j], dp[i - 1] + 1);
    cout << dp[n] << '\n';
}