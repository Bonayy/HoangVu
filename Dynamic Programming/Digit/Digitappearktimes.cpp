/// How many numbers x are there in the [a, b], where the digit d occurs exactly k times in x ?
#define fi first
#define se second
#include <bits/stdc++.h>
using namespace std;

int a, b, d, k;
vector <unsigned char> num;
int dp[12][12][2];

/// dp[p][c][f] = number of valid numbers <= b from this state
/// p = current position from left side in vector
/// c = number of occurs of digit d
/// f = this number <= b

int go(int pos, int cnt, int f){
    if (cnt > k) return 0;
    if (pos == num.size()){
        if (cnt == k) return 1;
        return 0;
    }
    if (dp[pos][cnt][f] != -1)
        return dp[pos][cnt][f];
    int res = 0, lmt;
    if (f == 0) lmt = num[pos];
    else lmt = 9;
    for (int dgt = 0; dgt <= lmt; dgt++){
        int _f = f, _cnt = cnt;
        if (f == 0 && dgt < lmt) _f = 1;
        if (dgt == d) _cnt++;
        if (_cnt <= k) res += go(pos + 1, _cnt, _f);
    }
    return dp[pos][cnt][f] = res;
}

int solve(int x){
    num.clear();
    memset(dp, -1, sizeof(int) * 12 * 12 * 2);
    while (x > 0){
        num.push_back(x % 10); x /= 10;
    }
    reverse(num.begin(), num.end());
    return go(0, 0, 0);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    cin >> a >> b >> d >> k;
    cout << solve(b) - solve(a);
}