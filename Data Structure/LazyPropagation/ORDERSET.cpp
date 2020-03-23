#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define all(v) (v).begin(), (v).end()
#define ub upper_bound
#define lb lower_bound

using ci = pair <char, int>;
ci que[200005]; vector <int> cmp;

struct SegTree{
    static const int N = 2e5 + 5;
    int cnt[N << 2], lo[N << 2], hi[N << 2], a[N];
    void build(int i, int l, int r){
        lo[i] = l; hi[i] = r; cnt[i] = 0;
        if (l == r) return; int m = (l + r) >> 1;
        build(i << 1, l, m); build(i << 1 | 1, m + 1, r);
    }
    int count(int i, int l, int r){
        if (lo[i] > r || hi[i] < l) return 0;
        if (lo[i] >= l && hi[i] <= r) return cnt[i];
        return count(i << 1, l, r) + count(i << 1 | 1, l, r);
    }
    int order(int i, int k){
        if (lo[i] == hi[i]) return lo[i];
        if (cnt[i << 1] >= k) return order(i << 1, k);
        return order(i << 1 | 1, k - cnt[i << 1]);
    }
    void update(int i, int pos, bool type){
        if (lo[i] > pos || hi[i] < pos) return;
        if (lo[i] == hi[i]){
            cnt[i] = type; return;
        }
        update(i << 1, pos, type); update(i << 1 | 1, pos, type);
        cnt[i] = cnt[i << 1] + cnt[i << 1 | 1];
    }
} ST;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> que[i].fi >> que[i].se;
        switch (que[i].fi){
            case 'K': break;
            default: cmp.push_back(que[i].se); break;
        }
    }
    sort(all(cmp)); cmp.resize(unique(all(cmp)) - cmp.begin());
    ST.build(1, 1, cmp.size());
    for (int i = 1; i <= n; i++){
        if (que[i].fi == 'I'){
            int t = ub(all(cmp), que[i].se) - cmp.begin();
            ST.a[t] = que[i].se; ST.update(1, t, 1);
        }
        if (que[i].fi == 'D'){
            int t = ub(all(cmp), que[i].se) - cmp.begin();
            ST.a[t] = que[i].se; ST.update(1, t, 0);
        }
        if (que[i].fi == 'K'){
            if (que[i].se > ST.cnt[1]) cout << "invalid\n";
            else cout << ST.a[ST.order(1, que[i].se)] << '\n';
        }
        if (que[i].fi == 'C'){
            int t = lb(all(cmp), que[i].se) - cmp.begin();
            if (t == 0) cout << "0\n";
            else cout << ST.count(1, 1, t) << '\n';
        }
    }
}