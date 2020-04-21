#include <bits/stdc++.h>
using namespace std;

#define all(v) (v).begin(), (v).end()
#define lb lower_bound
#define ub upper_bound

const int N = 1e5 + 5;
const int V = 1e4 + 5;
int a[N], b[N], bit[N], pos[N], n, ans;

void update(int i){
    for (; i <= n; i += i & -i) bit[i]++;
}

int retrieve(int i){
    int res = 0;
    for (; i > 0; i -= i & -i) res += bit[i];
    return res;
}

int main(){
    freopen("exarray.inp", "r", stdin);
    freopen("exarray.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n; vector <int> cmp;
    for (int i = 1; i <= n; i++){
        cin >> a[i]; cmp.push_back(a[i]);
    }
    for (int i = 1; i <= n; cin >> b[i++]);
    array <int, N> cnta, cntb;
    for (int i = 1; i <= n; i++){
        cnta[a[i] + V]++; cntb[b[i] + V]++;
    }
    for (int i = 1; i <= n; i++)
        if (cnta[a[i] + V] != cntb[a[i] + V])
            return cout << "-1\n", 0;
    sort(all(cmp));
    for (int i = 1; i <= n; i++){
        a[i] = ub(all(cmp), a[i]) - cmp.begin();
        b[i] = ub(all(cmp), b[i]) - cmp.begin();
    }
    for (int i = 1; i <= n; i++) pos[b[i]] = i;
    for (int i = 1; i <= n; i++) a[i] = pos[a[i]];
    cmp.clear();
    while (true){
        bool flag = false;
        for (int i = 1; i < n; i++)
            if (a[i] > a[i + 1]){
                flag = true; cmp.push_back(i);
                swap(a[i], a[i + 1]);
            }
        if (!flag) break;
    }
    cout << cmp.size() << '\n';
    for (auto x : cmp) cout << x << " ";
}