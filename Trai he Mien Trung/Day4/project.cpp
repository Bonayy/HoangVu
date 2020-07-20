#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 4e5 + 5;
int a[N], mx[N]; ll dp[N];


int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, h, s, d;
    cin >> n >> h >> s >> d;
    int k = (h + d) / s + 1;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = n; i > 0; i--){
        while (!dq.empty() &&
        a[dq.back()] >= a[i])
            dq.pop_back();
        dq.push_back(i);
        mx[i - 1] = a[dq.front()];
        if (dq.front() == i + k - 1)
            dq.pop_front();
    }
    long long res = 0, cur = 0;
    for (int i = 1; i <= n; i++){
        res += max(a[i] - cur, 0ll) * h;
    }
}
