#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
short a[N], b[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string s, t; cin >> s >> t;
    int n = s.size(), m = t.size();
    s = ' ' + s; t = ' ' + t;
    int pre = 0, suf = 0, ans = 0, st;
    for (int i = 1; i <= n; i++) a[i] = s[i] - '0';
    for (int j = 1; j <= m; j++) b[j] = t[j] - '0';
    for (int i = 1; i <= min(n, m); i++)
        if (a[i] == b[i]) pre++; else break;
    for (int x = n, y = m; x > 0 && y > 0; x--, y--)
        if (a[x] == b[y]) suf++; else break;
    for (int l = 1; l <= 7; l++){
        if (a[l] != b[l]) break; 
        int cur = 0, sum = 0, pos = 0, mod = pow(10, l - 1);
        for (int i = 1; i < l; i++) cur = cur * 10 + b[i];
        for (int i = 1, j = l; j <= m && i <= pre + 1; i++, j++){
            cur = cur * 10 + b[j];
            while (pos < n && sum + a[pos + 1] <= cur) sum += a[++pos];
            while (sum > cur) sum -= a[pos--];
            if (sum == cur && m - j == n - pos && n - pos <= suf)
                if (pos - i + 1 > ans){
                    ans = pos - i + 1; st = i;
                }
            cur %= mod; sum -= a[i];
        }
    }
    cout << st << ' ' << st + ans - 1;
}