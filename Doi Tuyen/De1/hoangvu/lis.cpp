#include <bits/stdc++.h>
using namespace std;

#define all(v) (v).begin(), (v).end()
#define ub upper_bound
#define lb lower_bound
const int N = 2e5 + 5;
int a[N], l[N], r[N], bit[N], n;

int retrieve(int i){
    int res = 0;
    for (; i > 0; i -= i & -i) res = max(res, bit[i]);
    return res;
}

void update(int i, int val){
    for (; i <= n; i += i & -i)
        bit[i] = max(bit[i], val);
}

int solve(){
    cin >> n; fill_n(bit + 1, n, 0); l[1] = r[n] = 1;
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector <int> cmp(a + 1, a + n + 1); int res = 0;
    sort(all(cmp)); cmp.resize(unique(all(cmp)) - cmp.begin());
    for (int i = 2; i <= n; i++)
        l[i] = a[i] > a[i - 1] ? l[i - 1] + 1 : 1;
    for (int i = n - 1; i > 0; i--)
        r[i] = a[i] < a[i + 1] ? r[i + 1] + 1 : 1;
    for (int i = 1; i <= n; i++){
        res = max(res, r[i] + retrieve(lb(all(cmp), a[i]) - cmp.begin()));
        update(ub(all(cmp), a[i]) - cmp.begin(), l[i]);
    }
    return res;
}

int main(){
    freopen("lis.inp", "r", stdin);
    freopen("lis.out", "w", stdout);
    int t; cin >> t; while (t--) cout << solve() << '\n';
}