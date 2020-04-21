#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
using iii = tuple <int, int, int>;

char op[] = "([{", cl[] = ")]}", s[205];
int dp[105][105][55];

int calc(int l, int r, int k){
    if (k < 0) return 0;
    if (k == 0) return l > r;
    if (l > r) return k == 0;
    if (k > (r - l + 1) / 2) return 0;
    int &res = dp[l][r][k];
    if (res != -1) return res;
    for (int m = l + 1; m <= r; m += 2)
        if (s[l] == '(' || s[l] == '?')
            if (s[m] == ')' || s[m] == '?'){
                for (int nk = 0; nk < k; nk++)
                    if (calc(l + 1, m - 1, k - 1) && calc(m + 1, r, nk))
                        return res = 1;
                for (int nk = 0; nk < k - 1; nk++)
                    if (calc(l + 1, m - 1, nk) && calc(m + 1, r, k))
                        return res = 1;
                if (calc(l + 1, m - 1, k - 1) && calc(m + 1, r, k)) 
                    return res = 1;
            }
    return res = 0;
}

int main(){
    freopen("btn1.inp", "r", stdin);
    freopen("btn1.out", "w", stdout);
    int n; cin >> s; n = strlen(s);
    memset(dp, -1, sizeof(int) * 105 * 105 * 55);
    for (int k = n / 2; k > 0; k--)
        if (calc(0, n - 1, k)) return cout << k << '\n', 0; 
}