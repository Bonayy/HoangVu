#include    <bits/stdc++.h>
#define fo(i,a,b) for(int i=(a);i<=(b);++i)
#define fd(i,a,b) for(int i=(a);i>=(b);--i)
#define rep(i,a,b)  for(int i=(a);i<(b);++i)
#define fi  first
#define se  second
#define LL  long long
#define uint unsigned int
#define pb  push_back
#define eb  emplace_back
#define bit(s,i) ((s >> i) & 1)
#define off(s,i) (s & (~ (1 << i)))
#define ii pair <int , int>
#define iii1 pair <ii , int>
#define iii2 pair <int , ii>
#define TASK "MEETING"
using   namespace   std;
string s[70] , t;
int n , m , f[70][70] , p;
///--------------------------
void readf()
{
    cin >> p;
    cin >> m >> n;
    cin >> t;
    for (int i = 1 ; i <= m ; ++i)
    {
        cin >> s[i];
        s[i] = " " + s[i];
    }
}
///--------------------------
void solve()
{
    int d = 0;
    for (int i = 1 ; i <= m ; ++i)
    for (int j = 1 ; j <= n ; ++j)
    {
        bool ok = ('A' <= s[i][j] && s[i][j] <= 'Z');
        f[i][j] = ok + f[i-1][j] + f[i][j-1] - f[i-1][j-1];
        d += ok;
    }
    int ans = n * m;
    for (int i = 1 ; i <= m ; ++i)
    for (int j = 1 ; j <= n ; ++j)
    for (int k = i ; k <= m ; ++k)
    for (int z = j ; z <= n ; ++z)
    if (f[k][z] - f[i-1][z] - f[k][j-1] + f[i-1][j-1] == d) ans = min(ans,(k - i + 1) * (z - j + 1));
    cout << ans;
}
///--------------------------
int main()
{
   #ifdef BDP0509
       freopen(TASK".inp", "r", stdin);
       freopen(TASK".out", "w", stdout);
   #endif // ONLINE_JUDGE
   ios::sync_with_stdio(0);
   cin.tie(0);cout.tie(0);
   readf();
   if (p == 1) solve();
}

