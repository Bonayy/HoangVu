/// Count total sum of every number x are there in [a, b] which have at most k different digits ?
#define popcnt __builtin_popcountll
#define clz __builtin_clzll
#define ctz __builtin_ctzll
 
#include <bits/stdc++.h>
using namespace std;
 
long long a, b;
int k;
int dp[18][1 << 10][2];
vector <char> num;
const int mod = 998244353;
/// dp[p][m][f] = number of valid numbers <= b in this state
/// p = current postion from the left
/// m = mask of occurs of 10 digits
/// f = this number <= b
 
void init(){
    freopen("dpd1.inp", "rt", stdin);
    freopen("dpd1.out", "wt", stdout);
}
 
int go(int pos, int mask, bool f, bool ok, long long tmp){
    if (popcnt(mask) > k) return 0;
    if (pos == num.size()){
        if (popcnt(mask) <= k) return tmp % mod;
        return 0;
    }
    if (dp[pos][mask][f] != -1)
        return dp[pos][mask][f];
    char lmt; int res = 0;
    if (!f) lmt = num[pos];
    else lmt = 9;
    for (char dgt = 0; dgt <= lmt; dgt++){
        int _f = f, _mask = mask;
        bool _ok = ok;
        if (!f && dgt < lmt) _f = true;
        if (dgt != 0){
            _mask |= (1 << dgt);
            _ok = true;
        }
        if (dgt == 0 && ok) _mask |= (1 << dgt);
        if (popcnt(_mask) <= k)
            res = (res + go(pos + 1, _mask, _f, _ok, tmp * 10 + dgt)) % mod;
    }
    return dp[pos][mask][f] = res;
}
 
int solve(long long x){
    num.clear();
    memset(dp, -1, sizeof(int) * 18 * (1 << 10) * 2);
    while (x > 0){
        num.push_back(x % 10); x /= 10;
    }
    reverse(num.begin(), num.end());
    return go(0, 0, 0, 0, 0);
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); //init();
    cin >> a >> b >> k;
    cout << solve(b) - solve(a - 1);
}