#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int a[N], cnt[35];
int spt[17][N], powt[N], logt[N];
map <int, int> mp;

int query_and(int i, int j){
    int p = logt[j - i + 1], q = powt[j - i + 1];
    return spt[p][i] & spt[p][j + 1 - q];
}

int query_or(int i, int j){
    int p = logt[j - i + 1], q = powt[j - i + 1];
    return spt[p][i] | spt[p][j + 1 - q];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, x, tmp = 0; cin >> n; mp[0] = 1;
    for (int i = 1; i <= n; cin >> a[i++]);
    cin >> x;
    int cntand = 0, cntor = 0, cntxor = 0;
    for (int i = 1; i <= n; i++){
        tmp ^= a[i]; cntxor += mp[tmp ^ x];
        mp[tmp]++; spt[0][i] = a[i];
    }
    powt[1] = 1; logt[1] = 0;
    for (int i = 2; i <= n; i++){
        powt[i] = powt[i - 1]; logt[i] = logt[i - 1];
        if ((i & (i - 1)) == 0){
            powt[i] <<= 1; ++logt[i];
        }
    }
    for (int k = 1, p = 1; k <= 17; k++, p <<= 1)
        for (int i = 1; i + (p << 1) <= n + 1; i++)
            spt[k][i] = spt[k - 1][i] | spt[k - 1][i + p];
    for (int i = 1, j = 1, k = 1; i <= n; i++){
        j = max(j, i); k = max(k, i);
        int p = query_or(i, j), q = query_or(i, k);
        while ((p & x) == p && (p ^ x) > 0 && j <= n) j++, p |= a[j];
        while ((q & x) == q && k <= n) k++, q |= a[k];
        cntor += k - j;
    }
    for (int k = 1, p = 1; k <= 17; k++, p <<= 1)
        for (int i = 1; i + (p << 1) <= n + 1; i++)
            spt[k][i] = spt[k - 1][i] & spt[k - 1][i + p];
    for (int i = 1, j = 1, k = 1; i <= n; i++){
        j = max(j, i); k = max(k, i);
        int p = query_and(i, j), q = query_and(i, k);
        while ((p & x) == x && (p ^ x) > 0 && j <= n) j++, p &= a[j];
        while ((q & x) == x && k <= n) k++, q &= a[k];
        cntand += k - j;
    }
    cout << cntand << '\n' << cntor << '\n' << cntxor << '\n';
}